#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 3
#define BACK -1
#define FRONT 0

int queue[SIZE];
int rear = BACK;
int front = FRONT;

int peek();
bool isFull();
bool isEmpty();
void enqueue(int data);
void dequeue(int data);

int main()
{
    enqueue(10);



    return 0;
}

int peek()
{
    return queue[front];
}

bool isFull()
{
    if (rear == SIZE - 1) {
        return true;
    } else {
        return false;
    }
}

bool isEmpty()
{
    if (front < 0 || front > rear) {
        return true;
    } else {
        return false;
    }
}

void enqueue(int data)
{
    if (isFull()) {
        printf("Queue Overflow\n");
    } else {
        rear++;
        queue[rear] = data;
    }
}

void dequeue(int data)
{
    if (isEmpty()) {
        printf("Queue is Empty.\n");
    } else {
        data = queue[front];
        front++;
    }
}