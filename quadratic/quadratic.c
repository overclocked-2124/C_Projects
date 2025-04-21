#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	float a,b,c,root1,root2;
	
	printf("Enter the quadratic coeff a b and c in respective order");
	scanf("%f%f%f",&a,&b,&c);
	
	if(b*b-4*a*c>0){
		root1= (-b+ sqrt(b*b-4*a*c))/(2*a);
		root2= (-b- sqrt(b*b-4*a*c))/(2*a);
		printf("Distinct and real roots are present\n");
		printf("Root 1 is: %f \n",root1);
		printf("Root 2 is: %f \n",root2);
	}
	
	else if(b*b-4*a*c==0){
		printf("Equal and real roots are present\n");
		root1= (-b+ sqrt(b*b-4*a*c))/(2*a);
		printf("Roots are: %f \n",root1);
	}
	
	else if(b*b-4*a*c<0){
		printf("Equal and imaginary roots are present\n");
		}
	
	return(0);
	
}
	
