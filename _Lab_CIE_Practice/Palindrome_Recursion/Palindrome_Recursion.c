#include<stdio.h>
#include <string.h>

void check(char [],int);

int main(){

    char str[]="mom";
    check(str,0);
    return(0);
}

void check(char str[],int i){
    int len=strlen(str)-(i+1);
    if(str[i]==str[len]){
        if(i+1==len||i==len){
            printf("Palindrome");
            return;
        }
        check(str,i+1);
    }
    else{
        printf("Entered string is not a palindrome");
    }
}