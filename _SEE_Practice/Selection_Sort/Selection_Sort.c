#include <stdio.h>

int main(){
    int a[] = {3,2,5,1,8,9};
    int n =6;
    int temp;
    for (int i =0;i<n-1;i++){
        int min=i;
        for(int j =i+1;j<n;j++){
            if(a[j]<a[min]){
                min=j;
            }
        }
        if(i!=min){
            temp=a[i];
            a[i]=a[min];
            a[min]=temp;
        }
    }

    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}