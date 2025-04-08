#include<stdio.h>
#include<stdlib.h>

#define Max 5

int stack[Max];
int top = -1;

void push(int value){

    if(top == Max - 1){
        printf("Stack is OverFlowed\n");
        return;
    }
    stack[++top] = value;
    printf("%d is Pushed in Stack\n",value);
}

void pop(){

    if(top == -1){
        printf("Stack is Empty\n");
        return;
    }
    printf("%d Element is Poped\n",stack[top--]);
}

void peek(){

    if(top == -1){
        printf("Stack is Empty\n");
        return;
    }
    printf("%d Element is Peeked\n",stack[top]);
}

void display(){

    if(top == -1){
        printf("Stack is Empty\n");
        return;
    }

    printf("Stack Elements : ");
    for(int i=0 ; i<=top ; i++){
        printf("%d",stack[i]);
    }
    printf("\n");
}

int main(){

    int choice,value;

    while(1){
        printf("\n Stack Menu: \n");
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Peek\n");
        printf("4.Display\n");
        printf("5.Exit\n\n");

        printf("Enter Your Choice : ");
        scanf("%d",&choice);

        switch(choice){

            case 1:
                printf("Enter Element to Push : ");
                scanf("%d",&value);
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
                printf("Exiting Programm..");
                return 0;

            default:
                printf("Invalid Choice,Please Try Again..");
        }
    }
}