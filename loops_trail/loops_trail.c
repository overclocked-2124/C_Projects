//4. Demonstration of Loops
#include<stdio.h>

int main()
{
    int i, n;
    
    printf("Enter a number: ");
    scanf("%d", &n);

    printf("\nNumbers using for loop:\n");
    for(i=1; i<=n; i++)
    {
        printf("%d ", i);
    }

    printf("\n\nNumbers using while loop:\n");
    i = 1; 
    while(i <= n)
    {
        printf("%d ", i);
        i++;
    }

    printf("\n\nNumbers using do-while loop:\n");
    i = 1; 
    do
    {
        printf("%d ", i);
        i++;
    } while(i <= n);
    
    printf("\n");
    return 0;
}
