#include<stdio.h>
#include<string.h>

int main(){
    char str1[50],str2[50];
    int n;

    printf("Enter the string here:");
    scanf("%s",str1);
    n= strlen(str1);

    for(int i=0;i<n;i++){
        str2[i]=str1[n-i-1];
    }

    printf("The reversed string is: %s\n",str2);

    return(0);
}