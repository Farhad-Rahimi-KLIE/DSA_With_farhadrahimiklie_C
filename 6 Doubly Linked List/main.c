#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* CreateNode(int data);
void InsertAtBegining(Node** head, int data);
void InsertAtEnd(Node** head, int data);
void InsertAtIndex(Node** head, int data, int index);
void DeleteAtBeginning(Node** head);
void DeleteAtEnd(Node** head);
void DeleteAtIndex(Node** head, int index);
void Search(Node* head, int key);
void DisplayForward(Node* head);
void DisplayBackward(Node* head);

int main(){
    Node* head = NULL;
    InsertAtBegining(&head, 10);
    InsertAtBegining(&head, 20);
    InsertAtBegining(&head, 30);
    InsertAtBegining(&head, 40);

    DisplayForward(head);
    DisplayBackward(head);

    // printf("List after insertions:\n");
    // Display(head);

    // InsertAtEnd(&head, 100);
    // InsertAtEnd(&head, 200);
    // printf("\nList after inserting at end:\n");
    // Display(head);

    // InsertAtIndex(&head, 500, 1);
    // printf("\nList after inserting 500 at index 2:\n");
    // Display(head);

    // DeleteAtBeginning(&head);
    // printf("\nList after deleting from beginning:\n");
    // Display(head);

    // DeleteAtEnd(&head);
    // printf("\nList after deleting from end:\n");
    // Display(head);

    // DeleteAtIndex(&head, 2);
    // printf("\nList after deleting index 1:\n");
    // Display(head);

    // Search(head, 30);  // جستجوی عدد 30
    // Search(head, 100); // جستجوی عددی که وجود نداره
    return 0;
}

void DisplayForward(Node* head) {
    Node* temp = head;
    printf("NULL <--> ");
    while (temp != NULL) {
        printf("%d <--> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void DisplayBackward(Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    Node* temp = head;

    // حرکت تا آخر لیست
    while (temp->next != NULL) {
        temp = temp->next;
    }

    printf("NULL <--> ");
    // حالا از آخر تا اول برمی‌گردیم
    while (temp != NULL) {
        printf("%d <--> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}


Node* CreateNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Dynamic Memory Allocation is Failed.");
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
    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;
}

void InsertAtEnd(Node** head, int data) {
    Node* newNode = CreateNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

void InsertAtIndex(Node** head, int data, int index) {
    if (index == 0) {
        InsertAtBegining(head, data);
        return;
    }

    Node* newNode = CreateNode(data);
    Node* temp = *head;

    for (int i = 0; i < index - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Index out of range!\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }

    temp->next = newNode;
}


void DeleteAtBeginning(Node** head) {
    if (*head == NULL) {
        printf("Nothing to delete!\n");
        return;
    }

    Node* temp = *head;
    *head = temp->next;

    if (*head != NULL) {
        (*head)->prev = NULL;
    }

    free(temp);
}

void DeleteAtEnd(Node** head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    Node* temp = *head;

    // اگر فقط یک نود وجود دارد
    if (temp->next == NULL) {
        free(temp);
        *head = NULL;
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->prev->next = NULL;
    free(temp);
}

void DeleteAtIndex(Node** head, int index) {
    if (*head == NULL) {
        printf("Empty list!\n");
        return;
    }

    if (index == 0) {
        DeleteAtBeginning(head);
        return;
    }

    Node* temp = *head;
    for (int i = 0; i < index && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Index out of range!\n");
        return;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    free(temp);
}

void Search(Node* head, int key) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    Node* temp = head;
    int index = 0;
    while (temp != NULL) {
        if (temp->data == key) {
            printf("Found %d at index %d\n", key, index);
            return;
        }
        temp = temp->next;
        index++;
    }

    printf("%d not found in the list.\n", key);
}
