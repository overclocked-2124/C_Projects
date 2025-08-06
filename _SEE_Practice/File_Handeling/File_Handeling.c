#include <stdio.h>
#include <ctype.h>

int main(){
    FILE *fp;
    fp = fopen("data.txt","r");
    char ch;
    int con=0,vow=0;
    
    while((ch=fgetc(fp))!=EOF){
        if(toupper(ch)=='A'||toupper(ch)=='E'||toupper(ch)=='I'||toupper(ch)=='O'||toupper(ch)=='U'){
            vow++;
        }
        else{
            con++;
        }
    }

    fp = fopen("data.txt","a");

    fprintf(fp,"\nNumber of vowvels: %d \n Number of Consonents: %d",vow,con);


    fclose(fp);
    return(0);
}