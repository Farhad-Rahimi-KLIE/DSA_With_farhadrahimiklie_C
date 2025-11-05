#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
} node;

node* root = NULL;

node* CreateNode(int data){
    node* newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL)
    {
        printf("Dynamic memory allocaation is faild");
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

node* AddNode(node* root, int data){
    if (root == NULL)
    {
        return CreateNode(data);
    }
    if (data < root->data)
    {
        root->left = AddNode(root->left, data);
    }else{
        root->right = AddNode(root->right, data);
    }
    return root;
}

void PreOrder(node* root){
    if (root == NULL)
    {
        return;
    }
    PreOrder(root->left);
    printf("%d \n", root->data);
    PreOrder(root->right);
}

int main(){
    root = AddNode(root, 2);
    root = AddNode(root, 1);
    root = AddNode(root, 7);
    root = AddNode(root, 9);
    root = AddNode(root, 3);
    root = AddNode(root, 5);

    PreOrder(root);
    return 0;
}