#include<stdio.h>
#include <string.h>

void check(char [],int);

int main(){

    char str[]="moam";
    check(str,0);
    return(0);
}

void check(char str[],int i){
    int len = strlen(str)-(i+1);
    if(str[len]==str[i]){
        if(len==i || len==i+1){
            printf("Palindrome");
            return;
        }
        else{
            check(str,i+1);
        }
    }
    else{
        printf("not a palindrome");
    }
}