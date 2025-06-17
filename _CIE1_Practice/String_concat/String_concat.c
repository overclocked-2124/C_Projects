#include<stdio.h>

int main(){
    char str1[50],str2[50],str3[50],str[150];
    int i,j;
    i=0;
    j=0;
    printf("Enter your first name: ");
    scanf("%s",str1);
    printf("Enter your middle name: ");
    scanf("%s",str2);
    printf("Enter your last name: ");
    scanf("%s",str3);
    
    while(str1[j] !='\0'){
        str[i++]=str1[j++];
    }

    str[i++]=' ';
    j=0;

    while(str2[j] !='\0'){
        str[i++]=str2[j++];
    }

    str[i++]=' ';
    j=0;

    while(str3[j] !='\0'){
        str[i++]=str3[j++];
    }

    str[i++]='\0';

    printf("Your full name is: %s",str);
    return(0);
}



