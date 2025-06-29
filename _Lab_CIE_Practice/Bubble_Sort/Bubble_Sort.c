#include<stdio.h>

int main(){
    int a[]={3,5,2,7,5};
    int temp,i,j,n=5;

    for(j=0;j<n-1;j++){
        for(i=0;i<n-j-1;i++){
            if(a[i]>a[i+1]){
                temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
            }
        }
    }

    for(int i=0;i<5;i++){
        printf("%d\t",a[i]);
    }
}