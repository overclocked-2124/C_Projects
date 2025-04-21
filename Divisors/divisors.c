#include <stdio.h>

int main(){
	int num;
	scanf("%d",&num);
	printf("the divisors of the number are: \n");
	
	for(int i =1;i<=num;i++){
		if ((num%i)==0){
			printf(" %d ",i);
		}
	}
	return(0);	
}
