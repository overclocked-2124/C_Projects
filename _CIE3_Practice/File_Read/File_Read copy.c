#include <stdio.h>

int main() {
    FILE *fp;
    char ch;

    fp = fopen("data.txt", "r");

    while((fgetc(fp))!=EOF){
        putchar(fp);
    }
}