#include<stdio.h>
#include<string.h>

int top = -1;  // Initialize top of stack

// Function to push an item to stack
void push(char stack[], char item) {
    if (top >= 99) {
        printf("Stack Overflow\n");
    } else {
        top++;
        stack[top] = item;
    }
}

// Function to pop an item from stack
char pop(char stack[]) {
    if (top < 0) {
        printf("Stack Underflow\n");
        return '\0';  
    } else {
        char item = stack[top];
        top--;
        return item;
    }
}

// Function to return precedence of operators
int precedence(char op) {
    switch(op) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

// Function to check if character is operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

int main(){
    char str1[100] = "(((a+(b-c)*d)/e)^f)";
    char stack[100];
    char postfix[100];
    int lenp=0;
    int len = strlen(str1);
    char ch;

    for(int i=0; i<len; i++){
        ch = str1[i];

        // If operand, add to postfix
        if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')){
            postfix[lenp++] = ch;
        }
        else if(ch == '('){
            push(stack, ch);
        }
        else if(ch == ')'){
            while(top >= 0 && stack[top] != '('){
                postfix[lenp++] = pop(stack);
            }
            pop(stack); // Remove '(' from stack
        }
        else if(isOperator(ch)){
            while(top >= 0 && precedence(stack[top]) >= precedence(ch)){
                if(ch == '^' && stack[top] == '^') {
                    // Right associativity for '^' operator
                    break;
                }
                postfix[lenp++] = pop(stack);
            }
            push(stack, ch);
        }
    }

    // Pop all remaining operators from stack
    while(top >= 0){
        postfix[lenp++] = pop(stack);
    }

    postfix[lenp] = '\0'; // Null terminate the postfix expression

    printf("Postfix Expression: %s\n", postfix);

    return 0;
}
