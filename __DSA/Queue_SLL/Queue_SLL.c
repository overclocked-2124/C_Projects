#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;


Node* front = NULL;
Node* rear = NULL;


void enqueue(int val){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if(front==NULL){
        front = rear = newNode;
    }
    else{
        rear->next = newNode;
        rear = newNode;
    }
}

int dequeue(){
    if(front==NULL){
        printf("Queue empty");
        return;
    }
    else{
        int val = front->data;
        Node* temp = front;
        front = front->next;

        if(front == NULL){
            rear=NULL;
        }
        free(temp);
        return(val);
    }
}


void display() {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    Node* temp = front;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
