#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    Struct node* next;
    Struct node* prev;
}Node;

Node* head = NULL;


Node* getnode(int val){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode==NULL){
        printf("Failed to create new node");
        exit(1);
    }

    newNode.data=val;
    newNode.next=NULL;
    return(newNode);
}

Node* freenode(Node* p){
    if(p){
        free(p);
    }
}

void insertFront(int val){
    Node* newNode = getnode(val);
    newNode->next=head;
    head=newNode;
}

void insertRear(int val){
    Node* newNode = getnode(val);
    if(head==NULL){
        head=newNode;
        return;
    }
    else{
        Node* temp = head;
        while(temp->next != NULL){
            temp=temp->next;
        }
        temp->next=newNode;
    }
}

void deleteFront(){
    if(!head){
        printf("Empty LL");
        exit(1);
    }
    else{
        Node* temp = head;
        head=head->next;
        freenode(temp;)
    }
}

void deleteRear(){
    if(!head){
        printf("Empty LL");
        exit(1);
    }
    else{
        Node* temp = head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        freenode(temp->next);
        temp->next=NULL;

    }
    
}

Void displayforward(Node* head ) { 
Node* curr = head ; 
while(curr!=NULL){
printf(“%d”,curr->val);
curr=curr->next ; 
} 
} 

Void displaybackward(Node* tail ) { 
Node* curr = tail ; 
while(curr!=NULL){
printf(“%d”,curr->val);
curr=curr->prev ; 
} 
}


int main() {
    insertFront(10); insertRear(20); insertFront(5); 
    deleteFront(); 
    deleteRear();  
    display();
    return 0;
}