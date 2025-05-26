/*
Using functions develop a C program to perform the following tasks by parameter passing to read a string from the user and print appropriate message for palindrome or not palindrome
*/

#include <stdio.h>
#include <string.h>
void check(char [], int);
int main()
{
char word[15];
printf("Enter a string to check if it is a palindrome\n");
scanf("%s", word);
check(word, 0);
return 0;
}
void check (char word [], int index)
{
intlen = strlen(word) - (index + 1);
if (word[index] == word[len])
{
if (index + 1 == len || index == len)
{
printf("The entered word is a palindrome\n");
return;
}
check(word, index + 1);
}
else
{
printf("The entered word is not a palindrome\n");
}
}
}