#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    NODE *next;
}NODE;


void append(NODE **,int);
void addatbeg(NODE **,int);
void addafter(NODE **,int,int);
void display(NODE *);
void delete(NODE * ,int);
int count(NODE *);

int main(){
    NODE *head;
    head=NULL;

    append(&head,20);
    append(&head,30);
    append(&head,40);

    display(head);

    addatbeg(&head,999);
    addatbeg(&head,888);
    addatbeg(&head,777);

    display(head);

    addafter(head,7,0);
    addafter(head,2,1);
    addafter(head,1,99);

    display(head);
    printf("Number of elements are %d",count(head));

    delete(&head,888);
    delete(&head,1);
    delete(&head,10);
    display(head);
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