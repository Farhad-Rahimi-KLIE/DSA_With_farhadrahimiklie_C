#include <stdio.h>
#include <stdlib.h>

// Structure for a node in binary tree
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to add (insert) a node into the binary tree (BST style)
Node* addNode(Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = addNode(root->left, value);
    else if (value > root->data)
        root->right = addNode(root->right, value);
    // If value already exists, do nothing (avoid duplicates)
    return root;
}

// Inorder Traversal (Left → Root → Right)
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Preorder Traversal (Root → Left → Right)
void preorder(Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Postorder Traversal (Left → Right → Root)
void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

// Free the memory (to avoid leaks)
void freeTree(Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// Main function to test all operations
int main() {
    Node* root = NULL;

    // Adding nodes
    root = addNode(root, 50);
    root = addNode(root, 30);
    root = addNode(root, 70);
    root = addNode(root, 20);
    root = addNode(root, 40);
    root = addNode(root, 60);
    root = addNode(root, 80);

    printf("Inorder traversal   : ");
    inorder(root);
    printf("\n");

    printf("Preorder traversal  : ");
    preorder(root);
    printf("\n");

    printf("Postorder traversal : ");
    postorder(root);
    printf("\n");

    // Free memory
    freeTree(root);

    return 0;
}
