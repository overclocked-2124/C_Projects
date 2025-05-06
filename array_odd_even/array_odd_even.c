//This is a program to seperate out the odd and even numbers in an array and provide the count for it
#include<stdio.h>

int main(){
    int a[100],n,odd[100],even[100],ocount,ecount;
    ocount=0;
    ecount=0;
    printf("Enter the number of elements: ");
    scanf("%d",&n);

    printf("Enter the elements in array: \n");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++){
        if(a[i]%2==0){
            even[ecount]=a[i];
            ecount++;
        }else{
            odd[ocount]=a[i];
            ocount++;
        }
    }

    printf("Even array:\n");
    for(int i=0;i<ecount;i++){
        printf(" %d ",even[i]);
        printf("\n");
    }

    printf("Odd array:\n");
    for(int i=0;i<ocount;i++){
        printf(" %d ",odd[i]);
        printf("\n");
    }

    printf("\nnumber of even numbers: %d \n",ecount);
    printf("\nnumber of odd numbers: %d \n",ocount);
}