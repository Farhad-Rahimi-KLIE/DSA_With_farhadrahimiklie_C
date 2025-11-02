#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

Node* CreateNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Allocation Failed! ");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int isEmpty(Node* top){
    if (top == NULL)
    {
        return 1;
    }else{
        return 0;
    }
}

int isFull(Node* top){
    Node* FullNode = (Node*)malloc(sizeof(Node));
    if (FullNode == NULL)
    {
        return 1;
    }else{
        return 0;
    } 
}


void Push(Node** top, int data){
    if (isFull(*top))
    {
        printf("Stack Overflow \n");
        return;
    }
    Node* newNode = CreateNode(data);
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
    return;
}

int Pop(Node** top){
    if (isEmpty(*top))
    {
        printf("Stack Underflow \n");
    }
    Node* temp = *top;
    *top = (*top)->next;
    temp->next = NULL;
    int x = temp->data;
    free(temp);
    return x;
}

int Peak(Node* top){
    return top->data;
}

void Display(Node* head){
    Node* temp = head;
    printf("Top -> Bottom \n");
    while (temp != NULL)
    {
        printf("%d \n", temp->data);
        temp = temp->next;
    }
}

int main(){
    Node* top = NULL;
    Push(&top, 2);
    Push(&top, 5);
    Push(&top, 8);
    Push(&top,4);
    printf("Popped Element is : %d \n", Pop(&top));
    printf("Popped Element is : %d \n", Pop(&top));

    int Top = Peak(top);
    printf("Top Element is : %d \n", Top);
    Display(top);
    return 0;
}