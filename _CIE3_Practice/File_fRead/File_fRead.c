#include <stdio.h>

int main(){
    FILE *fp;
    int usn;
    fp=fopen("data.txt","r");

    fscanf(fp,"Hello my USN is : %d",&usn);
    printf("%d",usn);
    fclose(fp);
    return(0);
}