#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

Node* InerstAtBeg(Node* head, int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    return head;
}

Node* AtEnd(Node* head, int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        return newNode;
    }

    Node* temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

void display(Node* head){
    Node* temp = head;

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL \n");
}

int main(){
    Node* head = NULL;

    head = InerstAtBeg(head, 10);
    head = InerstAtBeg(head, 20);
    head = InerstAtBeg(head, 30);
    head = AtEnd(head, 40);
    head = AtEnd(head, 50);

    printf("LInked List is Here: \n");
    display(head);
    return 0;
}