#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Implementation of Dynamic Stack on the Heap
// Operations: Push, Pop, Peek
// Push: Push 

typedef struct Stack {
    int *collection;
    int capacity;
    int size;
} Stack;

Stack *create_stack(int capacity);
bool isFull(Stack *stack);
bool isEmpty(Stack *stack);
bool pop(Stack *stack, int *item);
bool push(Stack *stack, int item);
int peek(Stack *stack);
void destroy_stack(Stack *stack);

int main() 
{
    Stack *stack = create_stack(5);

    if(!stack) {
        printf("Memory Allocation Failed.\n");
        return 1;
    }

    push(stack, 50);
    push(stack, 40);
    push(stack, 30);
    push(stack, 20);
    push(stack, 10);

    printf("Peeked Value: %d\n\n", peek(stack));

    int pop_val = 0;

    for (int i = 0; i < 5; i++) {
        pop(stack, &pop_val);
        printf("Popped Element: %d\n", pop_val);
    }


    destroy_stack(stack);

    return 0;
}

Stack *create_stack(int capacity)
{
    if (capacity <= 0) {
        return NULL;
    }

    Stack *stack = malloc(sizeof(Stack));

    if (!stack) {
        printf("Memory Allocation Failed!");
        return NULL;
    }

    stack->collection = malloc(capacity * sizeof(int));
    if (!stack->collection) {
        printf("Memory Allocation Failed.\n");
        return NULL;
    }

    stack->capacity = capacity; // the size of the stack.
    stack->size = 0; // this should be the top element.
    
    return stack;
}

void destroy_stack(Stack *stack)
{
    free(stack->collection);
    free(stack);
}

bool isFull(Stack *stack)
{
    if (stack->capacity == stack->size) {
        return true;
    } else {
        return false;
    }
}

bool isEmpty(Stack *stack)
{
    if (stack->size == 0) {
        return true;
    } else {
        return false;
    }
}

bool push(Stack *stack, int item) 
{
    if (!isFull(stack)) {
        stack->collection[stack->size] = item;
        stack->size++;
    } else {
        return false;
    }
}

bool pop(Stack *stack, int *item)
{
    if (!isEmpty(stack)) {
        stack->size--;
        *item = stack->collection[stack->size];
    } else {
        return false;
    }
}

int peek(Stack *stack) {

    if (!isEmpty(stack)) {
        return stack->collection[stack->size - 1]; 
    } else {
        return -1;
    }

}


