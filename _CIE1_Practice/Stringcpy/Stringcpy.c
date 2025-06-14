#include<stdio.h>
#include<string.h>

int main(){

    char str1[50],str2[50];

    printf("Enter string 1");
    scanf("%s",&str1);
    strcpy(str2,str1);
    printf(str2);

    return(0);
}