#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} NODE;



void append(NODE **,int);
void addatbeg(NODE **,int);
void addafter(NODE **,int,int);
void display(NODE **);
void delete(NODE ** ,int);
int count(NODE *);

int main(){
    NODE *head;
    head=NULL;

    append(&head,20);
    append(&head,30);
    append(&head,40);

    display(&head);

    addatbeg(&head,999);
    addatbeg(&head,888);
    addatbeg(&head,777);

    display(&head);

    addafter(&head,7,0);
    addafter(&head,2,1);
    addafter(&head,1,99);

    display(&head);
    printf("Number of elements are %d",count(head));

    delete(&head,888);
    delete(&head,1);
    delete(&head,10);
    display(&head);
    printf("Number of elements are %d",count(head));
    return(0);

}


void append(NODE **q,int d){
    NODE *temp;
    temp=*q;
    
    if(*q==NULL){
        *q=(NODE *)malloc(sizeof(NODE));
        temp=*q;
    }
    else{
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=(NODE *)malloc(sizeof(NODE));
        temp=temp->next;
    }
    temp->data=d;
    temp->next=NULL;
}


void addatbeg(NODE **q,int d){
    NODE *temp;
    temp=(NODE *)malloc(sizeof(NODE));
    temp->next=*q;
    temp->data=d;
    *q=temp;
}

int count(NODE *q){
    int count=0;
    NODE *temp;
    temp=q;
    while(temp!=NULL){
        temp=temp->next;
        count++;
    }
    return(count);
}


void addafter(NODE **q,int pos,int d){
    NODE *temp,*new;
    temp=*q;

    while(pos--){
        temp=temp->next;
    }
    new=(NODE *)malloc(sizeof(NODE ));
    new->next=temp->next;
    temp->next=new;
    new->data=d;

}

void display(NODE **q){
    NODE *temp;
    temp=*q;
    while(temp!=NULL){
            printf("%d\n",temp->data);
            temp=temp->next;
        }
}

void delete(NODE **q, int n) {
    NODE *temp;
    temp=*q;
    NODE *prev = NULL;

    // If the list is empty
    if (temp == NULL) {
        printf("List is empty. Cannot delete %d.\n", n);
        return;
    }

    // If head node itself holds the key to be deleted
    if (temp->data == n) {
        *q = temp->next; // Changed head
        free(temp);      // Free old head
        return;
    }

    // Search for the key to be deleted, keep track of the previous node
    while (temp != NULL && temp->data != n) {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in the list
    if (temp == NULL) {
        printf("Element %d not found in the list.\n", n);
        return;
    }

    // Unlink the node from linked list
    prev->next = temp->next;
    free(temp);
}

