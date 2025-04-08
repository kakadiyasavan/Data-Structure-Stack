#include <stdio.h>   
#include <stdlib.h>  
#include <ctype.h>   
#include <string.h> 

#define MAX 100  

char stack[MAX];  
int top = -1;     

void push(char x) {  // Push Element
    if (top == MAX - 1) {  // Stack Full?
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = x;  // Insert Element
}

char pop() {  // Pop Element
    if (top == -1) {  // Stack Empty?
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];  // Remove Element
}

int precedence(char x) {  // Operator Priority
    if (x == '+' || x == '-')  // Low Priority
        return 1;
    if (x == '*' || x == '/')  // Medium Priority
        return 2;
    if (x == '^')  // High Priority
        return 3;
    return 0;  // Default
}

void reverseString(char *str) {  // Reverse String
    int i, j;
    char temp;
    int len = strlen(str);
    for (i = 0, j = len - 1; i < j; i++, j--) {  // Swap Characters
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

void infixToPrefix(char *infix) {  // Convert Function
    char prefix[MAX];  // Result Storage
    int i, j = 0;  // Iterators

    reverseString(infix);  // Step 1: Reverse Infix

    for (i = 0; infix[i] != '\0'; i++) {  // Loop Characters
        if (isalnum(infix[i]))  // Operand?
            prefix[j++] = infix[i];  // Add to Result
        else if (infix[i] == ')')  // Right Bracket?
            push(infix[i]);  // Push to Stack
        else if (infix[i] == '(') {  // Left Bracket?
            while (top != -1 && stack[top] != ')')  // Pop Until ')'
                prefix[j++] = pop();
            pop();  // Remove ')'
        } else {  // Operator Found
            while (top != -1 && precedence(stack[top]) >= precedence(infix[i]))  // Compare Priority
                prefix[j++] = pop();
            push(infix[i]);  // Push Operator
        }
    }

    while (top != -1)  // Empty Stack
        prefix[j++] = pop();

    prefix[j] = '\0';  // End String
    reverseString(prefix);  // Step 3: Reverse Output

    printf("Prefix Expression: %s\n", prefix);  // Output Result
}

int main() {  // Start Program
    char infix[MAX];  // Input Expression
    printf("Enter Infix Expression: ");  // Prompt User
    scanf("%s", infix);  // Read Input
    infixToPrefix(infix);  // Call Function
    return 0;  // End Program
}
