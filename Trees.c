#include <stdio.h>
#include <stdlib.h>

// Create Node:
typedef struct Treenode {
    int data;
    struct Treenode *left;
    struct Treenode *right;
} Treenode;

// Create Tree Node Function:
Treenode *init_node(int value);

// Traversals uses recursive functions
void preorder_traverse(Treenode *root); // Root -> Left -> Right Traversal
void inorder_traverse(Treenode *root); // Left -> Root -> Right Traversal
void postorder_traverse(Treenode *root); // Right -> Left -> Root Traversal

int main()
{
    // Inititalize Root and Child Nodes:

    Treenode *root = init_node(10);
    Treenode *child_node1 = init_node(20);
    Treenode *child_node2 = init_node(30);
    Treenode *child_node3 = init_node(40);
    Treenode *child_node4 = init_node(50);
    Treenode *child_node5 = init_node(60);
    Treenode *child_node6 = init_node(70);

    root->left = child_node1;
    root->right = child_node2;

    child_node1->left = child_node3;
    child_node1->right = child_node4;

    child_node2->left = child_node5;
    child_node2->right = child_node6;

    printf("Output: ");
    preorder_traverse(root);

    printf("\n");

    printf("Output: ");
    inorder_traverse(root);

    printf("\n");

    printf("Output: "); 
    postorder_traverse(root);   

    return 0;
}

Treenode *init_node(int value) 
{
    Treenode *node = malloc(sizeof(Treenode));

    if (node) {
        node->left = NULL;
        node->right = NULL;
        node->data = value;
    } else{
        printf("Memory Allocation Failed.\n");
        exit(1);
    }

    return node;
}

void preorder_traverse(Treenode *root)
{
    if (!root) {
        return;
    }
    printf("%d  ", root->data);
    preorder_traverse(root->left);
    preorder_traverse(root->right);
}

void inorder_traverse(Treenode *root)
{
    if (!root) {
        return;
    }
    preorder_traverse(root->left);
    printf("%d  ", root->data);
    preorder_traverse(root->right);
}

void postorder_traverse(Treenode *root)
{
    if (!root) {
        return;
    }

    postorder_traverse(root->left);
    postorder_traverse(root->right);
    printf("%d  ", root->data);
}