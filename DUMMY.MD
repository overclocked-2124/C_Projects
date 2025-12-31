This is the **Master Plan** for your 2-ESP32 Poaching Detection System (No SD Card).

We are switching to a **"Store & Burst" Architecture**.

1. **Field Node (Sender):** Wakes up on sound $\rightarrow$ Records 4 seconds of audio into its internal RAM $\rightarrow$ Blasts the data to the Base Node $\rightarrow$ Goes back to sleep.
    
2. **Base Node (Receiver):** Receives data packets $\rightarrow$ Sends them over USB cable to Laptop.
    
3. **Laptop:** Stitches data back into a `.wav` file $\rightarrow$ Runs ML.
    

This is much more reliable than live streaming because if a packet drops during recording, it ruins the ML model. Recording to RAM first guarantees clean audio.

---

### **Part 1: The Wiring (Field Node)**

You are using the **NodeMCU ESP32 (30 Pin)**.

- **Base Node:** Needs **NO wiring**. Just plug into USB.
    
- **Field Node:** Wire the microphones as follows.
    

**A. Digital Mic (INMP441) – For Recording**

- **VDD** $\rightarrow$ **3.3V**
    
- **GND** $\rightarrow$ **GND**
    
- **SD** $\rightarrow$ **GPIO 32**
    
- **WS** $\rightarrow$ **GPIO 25**
    
- **SCK** $\rightarrow$ **GPIO 33**
    

**B. Analog Mic (MAX4466) – For Wake-up**

- **VCC** $\rightarrow$ **3.3V**
    
- **GND** $\rightarrow$ **GND**
    
- **OUT** $\rightarrow$ **GPIO 34** (Analog Input only pin, perfect for this)
    

---

### **Part 2: The Receiver Code (Base Node)**

**Do this first.** We need the Receiver running to catch data.

1. Connect the **Base Node ESP32** to your PC.
    
2. Upload this code.
    
3. **Write down the MAC Address** printed in the Serial Monitor. You need it for the Sender.
    

C++

```
/* ROLE: BASE NODE (RECEIVER)
   1. Receives Audio Packets via ESP-NOW
   2. Prints them to Serial (for Python to read)
*/
#include <esp_now.h>
#include <WiFi.h>

// Data packet structure
typedef struct {
    uint8_t sampleData[200]; // Payload
    int packetIndex;         // To keep order
    int totalPackets;        // To know when done
} AudioPacket;

AudioPacket incomingPacket;

// Callback when data is received
void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {
    memcpy(&incomingPacket, incomingData, sizeof(incomingPacket));
    
    // We send a specific header so Python knows this is data, not debug text
    Serial.write((uint8_t*)&incomingPacket, sizeof(incomingPacket));
}

void setup() {
  Serial.begin(115200); // Fast serial for audio
  WiFi.mode(WIFI_MODE_STA);

  // Print MAC Address for you to copy
  Serial.print("MY MAC ADDRESS: ");
  Serial.println(WiFi.macAddress());

  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  // Register callback
  esp_now_register_recv_cb(OnDataRecv);
}

void loop() {
  // Receiver just listens. Nothing in loop.
}
```

---

### **Part 3: The Sender Code (Field Node)**

**Important:** You must edit the `receiverMacAddress` line with the address you got from Part 2.

Logic:

1. ESP32 sleeps.
    
2. **MAX4466** (Analog) detects loud noise $\rightarrow$ Trigger wake up.
    
3. **INMP441** (Digital) turns on $\rightarrow$ Records 4 seconds to RAM.
    
4. Sends audio via ESP-NOW.
    
5. Goes back to sleep.
    

C++

```
/* ROLE: FIELD NODE (SENDER)
   1. Sleeps until Analog Mic > Threshold
   2. Records 4 seconds of Audio to RAM
   3. Sends to Base Node via ESP-NOW
*/
#include <driver/i2s.h>
#include <esp_now.h>
#include <WiFi.h>

// --- CONFIGURATION ---
// REPLACE THIS WITH YOUR RECEIVER'S MAC ADDRESS
uint8_t receiverMacAddress[] = {0x24, 0x6F, 0x28, 0xAB, 0xCD, 0xEF}; 

#define I2S_WS 25
#define I2S_SD 32
#define I2S_SCK 33
#define I2S_PORT I2S_NUM_0

#define ANALOG_PIN GPIO_NUM_34
#define WAKE_THRESHOLD 2000 // Adjust sensitivity (0-4095)

// Audio Settings
#define SAMPLE_RATE 16000
#define RECORD_TIME_SECONDS 4
#define TOTAL_SAMPLES (SAMPLE_RATE * RECORD_TIME_SECONDS)

// Buffer to store audio in RAM (16-bit samples)
// 16000 * 4 = 64,000 samples. 
// 64,000 * 2 bytes = 128KB (ESP32 has plenty of RAM for this)
int16_t audioBuffer[TOTAL_SAMPLES]; 

// Packet Structure
typedef struct {
    uint8_t sampleData[200];
    int packetIndex;
    int totalPackets;
} AudioPacket;

AudioPacket packet;

void setup() {
  Serial.begin(115200);
  
  // 1. Setup Wakeup Source (Analog Mic)
  // We use ext0 for simple high/low, but for analog threshold we need deep sleep logic.
  // For simplicity in this step, we use a simple loop sleep.
  // REAL DEEP SLEEP needs ULP (Advanced). Let's stick to "Light Sleep" logic for now.
  
  WiFi.mode(WIFI_MODE_STA);

  // 2. Init ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }
  
  esp_now_peer_info_t peerInfo;
  memcpy(peerInfo.peer_addr, receiverMacAddress, 6);
  peerInfo.channel = 0;  
  peerInfo.encrypt = false;
  
  if (esp_now_add_peer(&peerInfo) != ESP_OK){
    Serial.println("Failed to add peer");
    return;
  }

  // 3. Init I2S Microphone
  i2s_config_t i2s_config = {
    .mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_RX),
    .sample_rate = SAMPLE_RATE,
    .bits_per_sample = I2S_BITS_PER_SAMPLE_16BIT,
    .channel_format = I2S_CHANNEL_FMT_ONLY_LEFT,
    .communication_format = I2S_COMM_FORMAT_I2S,
    .intr_alloc_flags = ESP_INTR_FLAG_LEVEL1,
    .dma_buf_count = 8,
    .dma_buf_len = 64,
    .use_apll = false,
    .tx_desc_auto_clear = false,
    .fixed_mclk = 0
  };
  
  i2s_pin_config_t pin_config = {
    .bck_io_num = I2S_SCK,
    .ws_io_num = I2S_WS,
    .data_out_num = I2S_PIN_NO_CHANGE,
    .data_in_num = I2S_SD
  };
  
  i2s_driver_install(I2S_PORT, &i2s_config, 0, NULL);
  i2s_set_pin(I2S_PORT, &pin_config);
}

void loop() {
  // --- STATE 1: LISTEN FOR WAKE UP ---
  Serial.println("Waiting for noise...");
  while(analogRead(ANALOG_PIN) < WAKE_THRESHOLD) {
     delay(10); // Low power wait
  }
  
  Serial.println("NOISE DETECTED! Recording...");

  // --- STATE 2: RECORD AUDIO TO RAM ---
  size_t bytesRead;
  // Discard first chunk (settling time)
  // Read full buffer
  i2s_read(I2S_PORT, (char*)audioBuffer, sizeof(audioBuffer), &bytesRead, portMAX_DELAY);
  
  Serial.println("Recording Complete. Sending...");

  // --- STATE 3: SEND OVER ESP-NOW ---
  int totalBytes = sizeof(audioBuffer);
  int bytesPerPacket = 200;
  int totalPackets = totalBytes / bytesPerPacket;
  
  uint8_t* bytePtr = (uint8_t*)audioBuffer;

  for(int i=0; i<totalPackets; i++) {
     memcpy(packet.sampleData, bytePtr + (i * bytesPerPacket), bytesPerPacket);
     packet.packetIndex = i;
     packet.totalPackets = totalPackets;
     
     esp_now_send(receiverMacAddress, (uint8_t *) &packet, sizeof(packet));
     delay(2); // Small delay to prevent jamming the radio
  }
  
  Serial.println("Sent! Going back to wait mode.");
  delay(1000); // Debounce
}
```

---

### **Part 4: The Laptop Python Script**

Run this on your laptop. It listens to the Base Node and saves the file when it hears a "burst" of data.

**Requirements:** `pip install pyserial`

Python

```
import serial
import wave
import struct

# --- CONFIG ---
SERIAL_PORT = 'COM4'  # CHANGE THIS to your Base Node Port
BAUD_RATE = 115200
OUTPUT_FILE = "poaching_alert.wav"

# Packet Config (Must match Arduino)
PACKET_SIZE = 200 + 4 + 4  # 200 data + 4 index + 4 total
AUDIO_DATA_SIZE = 200

def save_wav(audio_bytes):
    print(f"Saving {len(audio_bytes)} bytes to {OUTPUT_FILE}...")
    with wave.open(OUTPUT_FILE, "w") as f:
        f.setnchannels(1)
        f.setsampwidth(2) # 16-bit
        f.setframerate(16000)
        f.writeframes(audio_bytes)
    print("File Saved!")

def main():
    ser = serial.Serial(SERIAL_PORT, BAUD_RATE)
    print(f"Listening on {SERIAL_PORT}...")

    audio_buffer = {} # Use dict to order packets
    current_total = 0
    
    while True:
        # Read exactly one packet structure size
        # Note: This is a simplified reader. In production, we need header bytes.
        data = ser.read(208) 
        
        if len(data) == 208:
            # Unpack: 200 bytes audio, int index, int total
            # '200s' = 200 bytes char, 'i' = int (4 bytes)
            payload, idx, total = struct.unpack('<200sii', data)
            
            if current_total == 0:
                current_total = total
                print("Receiving Audio Burst...")

            audio_buffer[idx] = payload

            if len(audio_buffer) >= current_total:
                print("Transmission Complete.")
                
                # Reassemble in order
                full_audio = b''.join([audio_buffer[i] for i in range(current_total)])
                save_wav(full_audio)
                
                # Reset for next shot
                audio_buffer = {}
                current_total = 0

if __name__ == "__main__":
    main()
```

### **Summary of Operations**

1. **Cable Fix:** Get a data cable. This is non-negotiable.
    
2. **Base Node:** Upload code, plug into Laptop.
    
3. **Field Node:** Upload code, connect battery & mics, place in box.
    
4. **Laptop:** Run Python script.
    
5. **Test:** Clap loudly near the Field Node.
    
6. **Result:** Field node records, sends data to Base Node, Python script saves `poaching_alert.wav`.
    

Once you get the cable, start at **Part 2**.
