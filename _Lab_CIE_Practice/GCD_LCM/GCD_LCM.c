#include<stdio.h>

int findLCM(int,int);
int findGCD(int,int);

int main(){
    int a=366,b=60,GCD,LCM;

    GCD=findGCD(a,b);
    LCM=findLCM(a,b);

    printf("GCD: %d\nLCM: %d",GCD,LCM);
}

int findLCM(int a,int b){
    static int temp=1;
    if(temp%a==0 &&temp%b==0){
        return(temp);
    }
    temp++;
    findLCM(a,b);
}


int findGCD(int a,int b){
    while(a!=b){
        if(a>b){
            return(findGCD(a-b,b));
        }
        else{
            return(findGCD(a,b-a));
        }
    }
}