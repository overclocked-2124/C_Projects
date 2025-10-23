#include<stdio.h>
#include<stdlib.h>

int main(){
    int n, *ptr,largest=0;
    largest=0;
    n=5;

    ptr=(int *)calloc(n,sizeof(int));

    for(int i=0;i<n;i++){
        scanf("%d",(ptr+i));
    }

    for(int i=0;i<n;i++){
        if(*(ptr+i)>largest){
            largest=*(ptr+i);
        }
    }

    printf("Largest = %d\n",largest);
}