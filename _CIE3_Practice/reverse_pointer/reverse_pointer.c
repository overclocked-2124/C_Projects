#include<stdio.h>

int main(){
    int *ptr, n,a[10]={1,2,3,4,5,6,7};
    n=7;
    ptr=a+(n-1);
    for(int i=0;i<n;i++){
        printf("%d\n",*(ptr-i));
    }
    return(0);
}