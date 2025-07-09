#include <stdio.h>

void swap(int *, int *);

int main(){
    int *ptra ,*ptrb,a,b;
    a=5;
    b=6;
    ptra=&a;
    ptrb=&b;
    swap(ptra,ptrb);
    printf("a= %d \nb= %d\n",*ptra,*ptrb);
}


void swap(int *a, int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}