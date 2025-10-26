#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 4
#define EMPTY -1

int stack[SIZE];
int top = EMPTY;

int peek();
bool isFull();
bool isEmpty();
void push(int data);
int pop();

int main()
{

    push(40);
    push(30);
    push(20);
    push(10);

    printf("Top Element: %d\n\n", peek());
    printf("First Element: %d\n", pop());
    printf("Second Element: %d\n", pop());
    printf("Third Element: %d\n", pop());
    printf("Fourth Element: %d\n\n", pop());
    

    return 0;
}

int peek()
{
    return stack[top];
}

bool isFull()
{
    if (top == SIZE - 1) {
        return true;
    } else {
        return false;
    }
}

bool isEmpty()
{
    if (top == EMPTY) {
        return true;
    } else {
        return false;
    }
}

void push(int data)
{
    if (!isFull())
    {
        top++;
        stack[top] = data;
    } else {
        printf("Stack Overflow!\n");
    }
}

int pop()
{
    if (!isEmpty()) {
        int data = stack[top];
        top--;
        return data;
    } else {
        printf("The Stack is Empty!\n");
        return EMPTY;
    }
}


