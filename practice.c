#include <stdio.h>
#include <stdlib.h>
// We Explore Singly Linked List
typedef struct Node
{
    int data;
    struct Node* prev; // pointer
    struct Node* next; // pointer
} Node;

Node* head = NULL;

Node* CreateNode(int data);
void InsertAtBegining(Node** head, int data);
void InsertAtEnd(Node** head, int data);
void InsertAtIndex(Node** head, int data, int index);
void DeleteAtBegining(Node** head);
void DeleteAtEnd(Node** head);
void DeleteAtIndex(Node** head, int index);
int Search(Node** head, int key);
void Display(Node* head);

int main() {
    InsertAtBegining(&head, 10);
    InsertAtBegining(&head, 20);
    InsertAtBegining(&head, 30);
    InsertAtBegining(&head, 40);

    // InsertAtEnd(&head, 100);

    // InsertAtIndex(&head, 400, 3);

    // DeleteAtBegining(&head);

    // DeleteAtEnd(&head);

    // DeleteAtIndex(&head, 3);


    Display(head);

    // int result = Search(&head, 40);
    // if (result != -1)
    // {
    //     printf("Found at Index %d \n", result);
    // }else{
    //     printf("Not Founded\n");
    // }
    
    return 0;
}

void Display(Node* head){
    Node* temp = head;

    while (temp != NULL)
    {
        printf("%d <--> ", temp->data);
        temp = temp->next;
    }
    printf("NULL \n");
}

Node* CreateNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Allocation Failed! ");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
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
    
    newNode->data = data;
    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;
    return;
}

void InsertAtEnd(Node** head, int data){
    Node* newNode = CreateNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return;
}

void InsertAtIndex(Node** head, int data, int index){
    Node* newNode = CreateNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    if (index == 0)
    {
        InsertAtBegining(head, data);
        return;
    }
    Node* temp = *head;

    for (int i = 0; i < index-1 && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Index is Out of Range");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
    {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    return;
}

void DeleteAtBegining(Node** head){
    if ((*head)->next == NULL)
    {
        free(head);
        *head = NULL;
    }
    Node* temp = *head;
    *head = (*head)->next;
    if ((*head)->prev != NULL)
    {
        (*head)->prev = NULL;
    }
    temp->next = NULL;
    free(temp);
    return;
}

void DeleteAtEnd(Node** head){
    Node* temp = *head;

    if ((*head)->next == NULL)
    {
        free(head);
        *head = NULL;
        return;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
    return;
}

void DeleteAtIndex(Node** head, int index){
    if ((*head)->next == NULL)
    {
        free(head);
        *head = NULL;
    }
    if (index == 0)
    {
        DeleteAtBegining(head);
        return;
    }
    
    Node* temp = *head;
    for (int i = 0; i < index && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Out of Range");
        return;
    }
    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != NULL)
    {
        temp->prev->next = temp->next;
    }
    free(temp);
    return;
}

int Search(Node** head, int key){
    Node* temp = *head;
    int i = 0;

    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return i;
        }
        temp = temp->next;
        i++;
    }
    return -1;
}
