#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    Struct node* next;
}Node;

Node* last = NULL;

void inserFront(int val){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next=NULL;

    if(last==NULL){
        last=newNode;
        last.next=last;
    }else{
        newNode->next = last->next;
        last->next = newNode;
    }
}

void insertRear(int val){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next=NULL;

    if(last==NULL){
        last=newNode;
        last.next=last;
    }else{
        newNode->next = last->next;
        last->next = newNode;
        last=newNode;
    }
}

void deleteFront() {
    if (last == NULL) return;
    Node* head = last->next;
    if (last == head) { 
        free(head);
    } else {
        last->next = head->next; 
        free(head);
    }
}

void deleteRear(){
    if (last == NULL) return;
    Node* head = last->next;
    if (last == head) { 
        free(head);
        last=NULL;
    }
    else{
        Node* temp = head;
        while (temp->next != last) temp = temp->next; 
        temp->next = last->next; 
        free(last);
        last = temp;
    }
}

void display() {
    if (last == NULL) return;
    Node* temp = last->next;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != last->next);
    printf("Head");
}
int main() {

}