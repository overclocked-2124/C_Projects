//2. Pattern Printing Programs
#include<stdio.h>

int main()
{
    int i, j;
    int num = 1;
    
    // First pattern
    printf("Pattern 1:\n");
    for(i=1; i<=4; i++)
    {
        for(j=1; j<=i; j++)
        {
            printf("%d ", num);
            num = num + 1;
        }
        printf("\n");
    }
    
    printf("\n");
    
    // Second pattern
    printf("Pattern 2:\n");
    for(i=1; i<=4; i++)
    {
        for(j=1; j<=i; j++)
        {
            printf("1 ");
        }
        printf("\n");
    }
    
    printf("\n");
    
    // Third pattern
    printf("Pattern 3:\n");
    for(i=1; i<=5; i++)
    {
        for(j=1; j<=i; j++)
        {
            printf("%d ", j);
        }
        printf("\n");
    }
    
    return 0;
}
