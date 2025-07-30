#include <stdio.h>
#include <string.h>

int main(){
    char str[100],str_rev[100];
    int i=0;

printf("Enter the required string: ");
scanf("%s",str);

for(i=0;i<strlen(str);i++){
    str_rev[i]=str[strlen(str)-1-i];
}

str_rev[i+1]='\0';

if(strcmp(str,str_rev)==0){
    printf("Palindrome");
}
else{
    printf("Not Palindrome");
}

return(0);
}