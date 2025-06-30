#include<stdio.h>
#include<math.h>

int btod(int b,int d,int bit){
    int bitw;
    if(b>0){
        bitw=b%10;
        b=b/10;
        d=d+bitw*pow(2,bit);
        bit++;
        d=btod(b,d,bit);
    }
    return(d);
}

int main(){
    int decimalnum=0,binarynum,bitweight=0; 
    printf("Enter the binary number\n"); 
    scanf("%d",&binarynum);
    decimalnum=btod( binarynum,decimalnum,bitweight); 
    printf("%d in binary %d",decimalnum, binarynum);
}