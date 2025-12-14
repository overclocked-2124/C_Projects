#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int coeff;
    int expo;
    Struct node* next;
}Node;

void insert(Node* head, int co , int ex){
    Node* temp = head;
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->coeff = co;
    newnode ->expo = ex;
    newnode->next = NULL;

    if(head==NULL || exp> head->expo){
        newNode->next = head;
        head=newnode;
    }
    else{
        while(temp->link!=NULL && temp->next->expo>=ex)
            temp = temp->next;
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void create(Node* head){
    int n,i;
    int coeff;
    int expo;

    scanf("%d",&n);

    for(i=0;i<n;i++){
        scanf("%d",&coeff);
        scanf("%d",&expo);
        insert(head,coeff,expo)
    }
}

void polyMulty(Node* head1,Node* head2){
    struct node* ptr1 = head1;
    struct node* ptr2 = head2;
    struct node* ptr3 = head3;
    struct node* temp;
    struct node* head3 = NULL;

    if(head1 == NULL || head2 == NULL)
    {
        printf("Zero polynomial\n");
        return;
    }

    while (ptr1 != NULL)
    {
        while (ptr2 != NULL)
        {
            head3 = insert(head3, ptr1->coeff * ptr2->coeff, ptr1->expo + ptr2->expo);
            ptr2 = ptr2->link;
        }
        ptr1 = ptr1->link;
        ptr2 = head2;
    }

    // to group terms with same exponents we do the following part

    while(ptr3->next!=NULL){
        if(ptr->expo==ptr->next->expo){
            ptr3->coeff = ptr3->coeff+ptr3->next->coeff;
            temp = ptr3->next;
            ptr3->next=ptr3->next->next;
            free(temp);
            temp=NULL;
        }
        else{
            ptr3 = ptr3->next;
        }
    }

}