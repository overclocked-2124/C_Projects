#include <stdio.h>

int main(){
    FILE *fp;
    int usn=100;

    fp=fopen("data.txt","w");

    fprintf(fp,"Hello my USN is : %d",usn);
    fclose(fp);
    return(0);
}