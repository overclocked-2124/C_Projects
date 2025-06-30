#include<stdio.h>

int check(char [],char []);

int main(){
    char str1[100]="Hello";
    char str2[100]="Heloo";
    int result;
    result=check(str1,str2);

    if(result){
        printf("Strings are equal");
    }
    else{
        printf("strings are not equal");
    }

    return(0);
}

int check(char *str1,char *str2){
    while(*str1==*str2){
        if(*str1=='\0' || *str2=='\0'){
            break;
        }
        else{
            str1++;
            str2++;
        }
    }
    if(*str1=='\0' && *str2=='\0'){
        return(1);
    }
    else{
        return(0);
    }
}