#include <stdio.h>

int main(){
    int a[] = {3,2,5,1,8,9};
    int n =6;
    int temp;

    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                temp=a[j+1];
                a[j+1]=a[j];
                a[j]=temp;
            }
        }
    }

    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}