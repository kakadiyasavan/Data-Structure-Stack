#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char x) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = x;
}

char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

int precedence(char x) {
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    if (x == '^')
        return 3;
    return 0;
}

void infixToPostfix(char *infix) {
    char postfix[MAX];
    int i, j = 0;
    
    for (i = 0; infix[i] != '\0'; i++) {
        char token = infix[i];
        
        if (isalnum(token)) {
            postfix[j++] = token;
        } else if (token == '(') {
            push(token);
        } else if (token == ')') {
            while (top != -1 && stack[top] != '(')
                postfix[j++] = pop();
            pop();
        } else {
            while (top != -1 && precedence(stack[top]) >= precedence(token))
                postfix[j++] = pop();
            push(token);
        }
    }
    
    while (top != -1)
        postfix[j++] = pop();
    
    postfix[j] = '\0';
    printf("Postfix Expression: %s\n", postfix);
}

int main() {
    char infix[MAX];
    
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    
    infixToPostfix(infix);
    
    return 0;
}
