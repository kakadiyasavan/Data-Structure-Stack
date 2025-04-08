#include <stdio.h>
#include <stdlib.h>

int *stack;  // Dynamic array for stack
int top = -1;
int capacity = 2; // Initial capacity of stack

// Function to resize stack dynamically
void resizeStack() {
    capacity *= 2; // Double the stack size
    stack = (int *)realloc(stack, capacity * sizeof(int));
    if (stack == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    printf("Stack resized to capacity %d.\n", capacity);
}

// Function to push an element onto the stack
void push(int value) {
    if (top == capacity - 1) {
        resizeStack(); // Resize the stack if full
    }
    stack[++top] = value;
    printf("%d pushed into stack.\n", value);
}

// Function to pop an element from the stack
void pop() {
    if (top == -1) {
        printf("Stack Underflow! Cannot pop.\n");
    } else {
        printf("%d popped from stack.\n", stack[top--]);
    }
}

// Function to display the top element of the stack
void peek() {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Top element: %d\n", stack[top]);
    }
}

// Function to display the stack elements
void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    int choice, value;

    // Initial memory allocation
    stack = (int *)malloc(capacity * sizeof(int));
    if (stack == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    while (1) {
        printf("\nStack Operations:\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting program...\n");
                free(stack); // Free dynamically allocated memory
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}
