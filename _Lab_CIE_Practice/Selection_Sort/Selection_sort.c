#include<stdio.h>

int main(){
    int a[]={5,1,3,5,7};
    int temp;
    for(int j=0;j<4;j++){
        int iMin=j;
        for(int i=j+1;i<5;i++){
            if(a[i]<a[iMin]){
                iMin=i;
            }
        }
        if(iMin!=j){
            temp=a[j];
            a[j]=a[iMin];
            a[iMin]=temp;
        }
        
    }
    for(int i=0;i<5;i++){
        printf("%d\t",a[i]);
    }
}