#include <stdio.h>
#include <stdlib.h>

// Linked lists are data structures that consists of a node,
// in which, each node consists of the data, the memory address,
// and a pointer to memory address of the next node.

// the tail node points to NULL, that represents the end of the list.

// MEMORY:
// In memory, the linked lists are not contiguous, so its memory address
// are stored randomly.
// Head Node: [address][data]->[address][data]->[data][NULL] :Tail Node

// Operations: Traverse, Insertion, Deletion, and Search
// Types of Linked Lists: Singly, Doubly, and Circular Linked List

// Implementation of a Singly Linked List:
typedef struct Node {
    int data;
    struct Node *next;
} Node;

void traversal(Node *head);
void insertion(Node *middle, int insert);
void free_list(Node *head);
void search(Node *head, int key);

int main()
{
    int insert_data, search_key;
    Node *head = malloc(sizeof(Node));
    Node *middle = malloc(sizeof(Node));
    Node *tail = malloc(sizeof(Node));

    if (!head || !middle || !tail) {
        printf("Memory Allocation Failed.\n");
        return 1;
    }

    head->data = 10;
    head->next = middle;

    middle->data = 20;
    middle->next = tail;

    tail->data = 30;
    tail->next = NULL;

    // Traversal often leads to a Linear Time Complexity O(N), since we traverse 
    // each element through nodes.

    traversal(head);

    // Insertion is O(N) if we insert between nodes of Head or Tail Node.
    // The Best Case is O(1) is if we insert around Head or Tail Node.

    printf("Insert Data: ");
    scanf("%d", &insert_data);
    
    printf("\nAfter Insertion:\n");
    insertion(middle, insert_data);
    traversal(head);

    printf("Search Node: ");
    scanf("%d", &search_key);
    search(head, search_key);


    free_list(head);

    return 0;
}

void traversal(Node *head)
{
    printf("Linked List Traversal:\n");
    Node *current = head;

    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void insertion(Node *prev_node, int insert) 
{
    Node *new_node = malloc(sizeof(Node));

    if (!new_node) {
        printf("Memory Allocation Failed\n");
        return;
    }
    
    new_node->data = insert;
    new_node->next = prev_node->next;
    prev_node->next = new_node;

}

void search(Node *head, int key)
{
    int flag = 0;
    Node *current = head;

    while (current != NULL) 
    {
        if(current->data == key) {
            flag = 1;
            printf("\nNode Found!\n");
            break;
        }
        current = current->next;
    }

    if (!flag) {
        printf("\nNode not found!\n");
    }
}


void free_list(Node *head)
{

    Node *curr = head;
    Node *next;

    while (curr != NULL) 
    {
        next = curr->next;
        free(curr);
        curr = next;
    }

}