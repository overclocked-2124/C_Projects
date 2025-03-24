//Program to find factorial till n using recursion in c

#include<stdio.h>

int fact(int x){
    if(x==1 || x==0){
        return(1);
    }
    else{
        return(x*fact(x-1));
    }
}

int main(){
    int n, ans;

    printf("Enter the number to find the factorial of: ");
    scanf("%d",&n);

    ans=fact(n);

    printf("The factorial of %d is %d\n", n, ans);

    return 0;
}
