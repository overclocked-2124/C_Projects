#include <stdio.h>
#include <string.h>

int main(){
    char str[100];
    int vowel=0,consonent=0,special=0;

    printf("Enter a string: ");
    scanf("%s",str);

    for(int i=0;i<strlen(str);i++){
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u'){
            vowel++;
        }
        else if(str[i]>='a' && str[i]<='z'){
            consonent++;
        }
        else{
            special++;
        }
    }
    return(0);
}