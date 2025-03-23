//Even number generator
#include <stdio.h>

int main (){
    int n;

    printf("Please enter the number till even numbers are to be generated:\n");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        if(i%2==0){
            printf("%d\n",i);
        }
    }
}