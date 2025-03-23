//Multiple generator for multiples of 2 and 5
#include <stdio.h>

int main (){
    int n;

    printf("Please enter the number till multiples are to be generated:\n");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        if(i%2==0 && i%5==0){  //we can also just have i%10
            printf("%d\n",i);
        }
    }
}