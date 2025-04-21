//Number guessing game
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	int min=0,max =100,usr;
	int flag = 1;
	srand(time(0));
	int random_number = rand() % (max - min+1)+min;
	
	
	while(flag){
		printf("Guess the number: ");
		scanf("%d",&usr);
		
		if(usr==random_number){
				printf("YAY you got it right the number was inteed %d \n",random_number);
				flag = 0;
			}
		if(usr>random_number){
				printf("Try again \t Hint: try Lower\n");
			}
		if(usr<random_number){
				printf("Try again \t Hint: try Higher\n");
			}

		}
		return(0);
}


