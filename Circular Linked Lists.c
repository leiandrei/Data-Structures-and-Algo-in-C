#include <stdio.h>
#include <stdlib.h>

// Implementation: Circular Linked Lists

typedef struct Node 
{
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

int main() 
{
    Node *head = malloc(sizeof(Node));
    Node *middle = malloc(sizeof(Node));
    Node *tail = malloc(sizeof(Node));

    head->prev = tail;
    head->data = 50;
    head->next = middle;

    middle->prev = head;
    middle->data = 100;
    middle->next = tail;

    tail->prev = middle;
    tail->data = 150;
    tail->next = head;

    free(head);
    free(middle);
    free(tail);

    return 0;
}