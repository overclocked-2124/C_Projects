#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct node {
    int val;
    struct node *next;
};

typedef struct node* NODE;


NODE getnode();
NODE insert_front(NODE , int);
NODE delete_front(NODE);
void display(NODE);
void main()
{
NODE first;
int choice, item;
first = NULL;
while(1)
{
printf("Enter\n");
printf("1. Insert Front\n");
printf("2. Delete Front\n");
printf("3. Display the list\n");
printf("4. Exit\n");
scanf("%d", &choice);
switch(choice)
{
case 1:
printf("Enter item to be inserted\n"); scanf("%d", &item);
first = insert_front(first, item); break;
case 2:
first = delete_front(first); break;
case 3:
display(first); break;
default:
exit(0);
}
}
}

NODE getnode(int val, NODE next){
    NODE newnode;
    newnode=(NODE)malloc(sizeof(struct node));
    newnode->val=val;
    newnode->next=next;
}

NODE insert_front(NODE first , int item){
    NODE newnode=getnode(item,first);
    first=newnode;
    return(first);
}