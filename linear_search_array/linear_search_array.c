//This is a program to perform linear search on an array
#include <stdio.h>

int main(){
    int j,n, key,flag;
    flag=0;
    j=0;

    printf("Enter the number of elements in the array:");
    scanf("%d",&n);

    printf("Enter the key:");
    scanf("%d",&key);

    int a[n];

    for(int i=0;i<n;i++){
    printf("Enter the %dth element:",i+1);
    scanf("%d",&a[i]);
    }

    while(flag==0){
        if(j<n){
            if(a[j]==key){
                printf("The element %d if present at the position %d",key,j+1);
                flag=1;
            }
            else{
                j++;
            }
        }
        else{
            printf("element %d not in given array",key);
        }

    }

}