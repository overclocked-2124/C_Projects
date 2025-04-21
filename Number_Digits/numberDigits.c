#include <stdio.h>

int main(){
	int count=0;
	int num;
	
	scanf("%d",&num);
	
	while(num!=0){
		num = num/10;
		count++;
	}
	
	printf("The total digits in the number are: %d \n",count);
	return(0);
}
