#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Binary Search Tree Implementatio 

// Create a Tree Node structure:
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *initializeNode(int value); // function to initialize values onto nodes and nodes itself.
Node *insertNode(Node *root, int value); // function to insert nodes onto the root.
Node *binarySearch(Node *root, int key); // function to search through trees for a specific node.

// Traversal Funtcions

// Inorder: left -> root -> right
// Preorder: root -> left -> right
// Postorder: right -> left -> root

void inorderTraversal(Node *root);
void preorderTraversal(Node *root);
void postorderTraversal(Node *root);

void show(Node *root);

int main()
{
    Node *root = initializeNode(10); // Root Node


    // Child Nodes
    root = insertNode(root, 20); 
    root = insertNode(root, 30);
    root = insertNode(root, 40);
    root = insertNode(root, 50);
    root = insertNode(root, 60);
    root = insertNode(root, 70);

    show(root);

    Node *search = binarySearch(root, 50);

    if (!search) {
        printf("Element not found in the tree.\n");
    } else {
        printf("Element found in the tree.\n");
    }

    return 0;
}

Node *initializeNode(int value)
{
    Node *node = malloc(sizeof(Node));

    if (!node) {
        printf("Memory Allocation Failed.\n");
        exit(1);
    }

    node->left = NULL;
    node->right = NULL;
    node->data = value;

    return node;

}

Node *insertNode(Node *root, int value)
{
    if (root == NULL) {
        return initializeNode(value);
    }

    if (value < root->data) {
        root->left = insertNode(root->left, value);
    } else {
        root->right = insertNode(root->right, value);
    }

    return root;
}

Node *binarySearch(Node *root, int key)
{
    if (root == NULL || root->data == key) {
        return root;
    }

    if (key < root->data) {
        return binarySearch(root->left, key);
    } else {
        return binarySearch(root->right, key);
    }
}

void inorderTraversal(Node *root)
{
    if (!root) {
        return;
    }

    inorderTraversal(root->left);
    printf("%d  ", root->data);
    inorderTraversal(root->right);
}

void preorderTraversal(Node *root)
{
    if (!root) {
        return;
    }

    printf("%d  ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(Node *root)
{
    if (!root) {
        return;
    }

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d  ", root->data);
}

void show(Node *root)
{
    printf("Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Pre-order Traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("Post-order Traversal: ");
    postorderTraversal(root);
    printf("\n");
}



