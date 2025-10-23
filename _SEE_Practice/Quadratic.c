//Program to find and display quadratic roots.

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main(){
    float r1,r2,d,a,b,c;

    scanf("%f%f%f",&a,&b,&c);

    d=(b*b)-4*a*c;

    if(d>0){
        r1=((-b+sqrt(d))/(2*a));
        r2=((-b-sqrt(d))/(2*a));
        printf("The roots are real and distinct: %f and %f",r1,r2);
    }

    if(d==0){
        r1=((-b)/(2*a));
        printf("The roots are real and equal: %f and %f",r1,r1);
    }
    else{
        r1=((-b)/(2*a));
        r2=((sqrt(-d))/(2*a));
        printf("The Imaginary root 1: %f + i%f\n",r1,r2);
        printf("The Imaginary root 2: %f - i%f\n",r1,r2);
    }
}
