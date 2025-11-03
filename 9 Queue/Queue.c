#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
    int size;
    int Rear;
    int Front;
    int* Array; // Pointer array
} Queue;

int isFull(Queue* fr){
    if (fr->Rear == fr->size-1)
    {
        return 1;
    }
    return 0;
}

int isEmpty(Queue* fr){
    if (fr->Rear == fr->Front)
    {
        return 1;
    }
    return 0;
}

void Enqueue(Queue* fr, int data){
    if (isFull(fr))
    {
        printf("Queue is Full ! please do not put it.");
        return;
    }else{
        fr->Rear++;
        fr->Array[fr->Rear] = data;
        return;
    }
}

int Dequeue(Queue* fr){
    if (isEmpty(fr))
    {
        printf("Queue is Empty !");
    }else{
        fr->Front++;
        int a = fr->Array[fr->Front];
        return a;
    }
}

int Peak(Queue* fr){
    fr->Front++;
    return fr->Array[fr->Front];
}

int main(){
    Queue q;
    q.size = 10;
    q.Front = q.Rear = -1;
    q.Array = (int*)malloc(q.size * sizeof(int));

    Enqueue(&q, 2);
    Enqueue(&q, 5);
    Enqueue(&q, 8);
    Enqueue(&q, 4);
    
    printf("Dequeue element is %d \n", Dequeue(&q));
    printf("Dequeue element is %d \n", Dequeue(&q));
    printf("Dequeue element is %d \n", Dequeue(&q));
    
    int result = Peak(&q);
    printf("Top element is %d \n", result);
    return 0;
}