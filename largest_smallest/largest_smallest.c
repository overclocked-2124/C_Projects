//1)This is the program to find the largest and smallest element in the user inputted array.
#include <stdio.h>

int main (){
    int n;

    printf("Please enter the size of the array required\n");
    scanf("%d",&n);

    int lar,sma,a[n];

    for(int i=0;i<n;i++){
    printf("Enter the %dth element:",i+1);
    scanf("%d",&a[i]);
    }

    sma=a[0];
    lar=a[0];

    for(int i=1;i<n;i++){
        if(a[i]<sma){
            sma=a[i];
        }
        }
    
        for(int i=1;i<n;i++){
            if(a[i]>lar){
                lar=a[i];
            }
            }
    
            printf("The largest element is:%d\n The smallest element is:%d\n",lar,sma);
}