#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node* next;
} Node;

Node* head = NULL;

Node* CreateNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void InsertAtBegining(Node** head, int data){
    Node* newNode = CreateNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    newNode->next = *head;
    *head = newNode;
    return;
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

int main() {
    InsertAtBegining(&head, 10);
    InsertAtBegining(&head, 20);
    InsertAtBegining(&head, 30);
    InsertAtBegining(&head, 40);

    display(head);
    return 0;
}
