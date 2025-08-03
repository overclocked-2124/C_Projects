#include <stdio.h>

int GCD(int ,int );

int LCM(int,int);

int main(){
    int a=10,b=20;
    printf("GCD = : %d\n",GCD(a,b));
    printf("LCM = : %d\n",LCM(a,b));
}

int GCD(int x,int y){
    while(x!=y){
    if(x>y){
        return(GCD(x-y,y));
    }
    else if(x<y){
        return(GCD(x,y-x));
    }
    }
    return(x);
}

int LCM(int x,int y){
    static int temp=1;
    if(temp%x==0 && temp%y==0){
        return(temp);
    }
    else{
        temp++;
        LCM(x,y);
    }
}