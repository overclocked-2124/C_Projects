#include<stdio.h>
#include<string.h>

int main(){
    struct nameses
    {
        char names[50];
        int usn ;
    };
    
struct nameses name[20]={
    {"Auma",131},
    {"Bma",12},
    {"ama",31},
    {"Sua",13},
    {"sumdjnaa",28237328}
};

struct nameses temp;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5-i-1; j++) {
            if (strcmp(name[j].names,name[j+1].names)>0) {
                temp=name[j];
                name[j] = name[j+1];
                name[j+1] = temp;
            }
        }
    }

    // Print sorted array
    printf("Sorted array: \n");
    for (int i = 0; i < 5; i++) {
        printf("%s     ", name[i].names);
        printf("%d \n", name[i].usn);
    }

    return 0;
}