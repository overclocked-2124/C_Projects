//This is a problem to find the intersection of elements between 2 arrays

#include <stdio.h>
int main(){

int a[5]={12,15,18,21,31};
int b[5]={12,15,19,24,31};
int c[5];
int count=0;

for(int i=0;i<5;i++){
    for(int j =0;j<5;j++){
        if(a[i]==b[j]){
            c[count];
            count++;
        }
    }
}

printf("the elements present in both a and b are:\n");

for(int i =0;i<count;i++){
    printf("%d\n",a[i]);
}

}