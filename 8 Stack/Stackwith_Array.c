#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
    int size;
    int top;
    int* arr;
} Stack;

int isEmpty(Stack* ptr){
    if (ptr->top == -1)
    {
        return 1;
    }else{
        return 0;
    }
}

int isFull(Stack* ptr){
    if (ptr->top == ptr->size-1)
    {
        return 1;
    }else{
        return 0;
    }
}

void Push(Stack* ptr, int data){
    if (isFull(ptr))
    {
        printf("Stac is Full! do not in it.");
        return;
    }
    ptr->top++;
    ptr->arr[ptr->top] = data;
    return;
}

void Pop(Stack* ptr){
    if (isEmpty(ptr))
    {
        printf("Your Stack is empty.");
        return;
    }
    int value = ptr->arr[ptr->top];
    ptr->top--;
    return;
}

int Top(Stack* ptr){
    return ptr->arr[ptr->top];
}

void Display(Stack* ptr) {
    if (isEmpty(ptr)) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack elements (top to bottom): ");
    for (int i = ptr->top; i >= 0; i--) {
        printf("%d ", ptr->arr[i]);
    }
    printf("\n");
}

int main(){
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->size = 5;
    stack->top = -1;
    stack->arr = (int*)malloc(stack->size * sizeof(int));

    printf("%d\n", isFull(stack));
    printf("%d\n", isEmpty(stack));

    Push(stack, 10);
    Push(stack, 20);
    Push(stack, 30);

    // Pop(stack);
    // Pop(stack);

    Display(stack);

    int top = Top(stack);
    printf("Top of the Stack is : %d \n", top);

    return 0;
}