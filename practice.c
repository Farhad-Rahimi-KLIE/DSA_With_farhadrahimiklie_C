#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

Node* InsertAtBegining(Node* head, int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    return head;
}

Node* InsertAtEnd(Node* head, int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    Node* temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = NULL;
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

    head = InsertAtBegining(head, 10);
    head = InsertAtBegining(head, 20);
    head = InsertAtBegining(head, 30);

    head = InsertAtEnd(head, 40);
    head = InsertAtEnd(head, 50);
    display(head);

    return 0;
}