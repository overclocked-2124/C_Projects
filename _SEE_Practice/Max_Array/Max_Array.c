#include <stdio.h>

int main(){
    int n,a[10],max;

    max=0;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        printf(" Enter element number : %d = ",i);
        scanf("%d",&a[i]);
    }

    for(int i=0;i<n;i++){
        if(a[i]>max){
            max=a[i];
        }
    }

    printf("\n Maximum: %d",max);
}