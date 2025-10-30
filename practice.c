#include <stdio.h>
#include <stdlib.h>

// This is the Doubly Linked List

typedef struct Node
{
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* head = NULL; // Initialze the Head Node with Null value

Node* CreateNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->next = NULL;
    return newNode;
}

Node* InsertAtBegining(Node* head, int data){
    Node* newNode = CreateNode(data);
    newNode->prev = NULL;
    newNode->next = head;
    if (head != NULL)
    {
        head->prev = newNode;
    }
    head = newNode;
    return head;
}

Node* InsertAtEnd(Node* head, int data){
    
}

void displayForward(Node* head){
    Node* temp = head;
    printf("Forward ");

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL \n");
}

void displayBackward(struct Node* head) {
    struct Node* temp = head;
    if (temp == NULL) return;

    while (temp->next != NULL)
        temp = temp->next;

    printf("Backward: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

int main(){

    head = InsertAtBegining(head, 10);
    head = InsertAtBegining(head, 20);
    head = InsertAtBegining(head, 30);
    head = InsertAtBegining(head, 40);

    displayForward(head);
    displayBackward(head);

    return 0;
}