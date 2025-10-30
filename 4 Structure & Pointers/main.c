#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// 1
// typedef struct Students
// {
//     char name[20];
//     int id;
//     float marks;
// } students;

// 2
// typedef struct Address
// {
//     char city[30];
//     int zip;
// } address;


// typedef struct Students
// {
//     char name[20];
//     int id;
//     float marks;
//     address address;
// } student;


// 3
// typedef struct Students
// {
//     char name[20];
//     int id;
// } students;


// 4 (node for linked list)
// typedef struct Node
// {
//     int data;
//     struct Node* next;
// } Node;



int main(){
    // Structures

    // students s1 = {"farhad rahimi klie", 5, 23.7};
    // strcpy(s1->name, "farhad rahimi kle");
    // s1->id = 7;
    // s1->marks = 34.7;

    // printf("name is: %s \n", s1.name);
    // printf("id is: %d \n", s1.id);
    // printf("marks is: %.2f \n", s1.marks);


    // student s = {"Farhad Rahimi Kle", 3, 23.8, {"Tehran", 12345}};
    // student s1;
    // strcpy(s1.name, "farhad rahimi");
    // s1.id = 12;
    // s1.marks = 65.9;
    // strcpy(s1.address.city, "Faryab, Andkhoi");
    // s1.address.zip = 123456;

    // printf("name : %s1 \n", s1.name);
    // printf("id : %d \n", s1.id);
    // printf("marks : %.2f \n", s1.marks);
    // printf("city : %s1 \n", s1.address.city);
    // printf("zip : %d \n", s1.address.zip);


    // Pointers 

    // int x = 10;
    // int *ptr = &x;
    
    // printf("Value of x: %d\n", x);
    // printf("Address of x: %p\n", &x);
    // printf("Value of ptr: %p\n", ptr);
    // printf("Value pointed by ptr: %d\n", *ptr);




    // Structure to Pointers

    // students s = {"Farhad Rahimi Klie", 7};
    // students* ptr = &s;

    // printf("name is: %s \n", ptr->name);
    // printf("id is: %d \n", ptr->id);


    // Linked List Small Example here

    // Node* head = NULL;
    // Node* second = NULL;
    // Node* third = NULL;

    // head = (Node*)malloc(sizeof(Node));
    // second = (Node*)malloc(sizeof(Node));
    // third = (Node*)malloc(sizeof(Node));

    // head->data = 10;
    // head->next = second;

    // second->data = 20;
    // second->next = third;

    // third->data = 30;
    // third->next = NULL;

    // Node* temp = head;

    // while (temp != NULL)
    // {
    //     printf("-> %d", temp->data);
    //     temp = temp->next;
    // }

    // printf("NULL \n");

    // free(head);
    // free(second);
    // free(third);
    
    return 0;
}