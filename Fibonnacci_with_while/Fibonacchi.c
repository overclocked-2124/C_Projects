//program to print the first n terms of the Fibonacci series using a for or while loop.
#include <stdio.h>

int main(){
    int n,prev,prevprev,current;
    prev=1;
    prevprev=0;

    printf("Input the number of terms to be found till: ");
    scanf("%d",&n);
    n=n-2;
    printf("%d ",prevprev);
    printf("%d ",prev);

    while(n--){
        current=prevprev+prev;
        printf("%d ",current);
        prevprev=prev;
        prev=current;
    }

    return 0;
}