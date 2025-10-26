#include <stdio.h>
#include <stdlib.h>

// Implementation: Doubly Linked Lists


// Representation:
// [1] <-> [2] <-> [3]

typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

void free_list(Node *head);
void traversal_forward(Node *head);
void traversal_backward(Node *tail);
int main()
{
    Node *head = malloc(sizeof(Node));
    Node *node1 = malloc(sizeof(Node));
    Node *node2 = malloc(sizeof(Node));
    Node *tail = malloc(sizeof(Node));

    if (!head || !node1 || !node2)

    head->prev = NULL;
    head->data = 10;
    head->next = node1;

    node1->prev = head;
    node1->data = 15;
    node1->next = node2;

    node2->prev = node1;
    node2->data = 20;
    node2->next = tail;

    tail->prev = node2;
    tail->data = 25;
    tail->next = NULL;

    traversal_forward(head);
    traversal_backward(tail);

    free_list(head);

    return 0;
}

void traversal_forward(Node *head)
{
    Node *curr = head;

    while (curr != NULL) {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

void traversal_backward(Node *tail)
{
    Node *curr = tail;

    while (curr != NULL) {
        printf("%d -> ", curr->data);
        curr = curr->prev;
    }
    printf("NULL\n");
}

void free_list(Node *head)
{
    Node *current = head;
    Node *next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
}
