//1. Prime Number Checker
#include<stdio.h>

int main()
{
    int number, i;
    int flag = 0;
    
    printf("Enter a number: ");
    scanf("%d", &number);
    
    for(i=2; i<number; i++)
    {
        if(number % i == 0)
        {
            flag = 1;
            break;
        }
    }
    
    if(number == 1)
    {
        printf("%d is not a prime number\n", number);
    }
    else
    {
        printf("%d is a prime number\n", number);
    }
    
    return 0;
}
