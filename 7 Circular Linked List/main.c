#include <stdio.h>
#include <stdlib.h>

// تعریف ساختار نود
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 🧱 تابع ساخت نود جدید
Node* CreateNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// ✅ درج در ابتدای لیست
Node* InsertAtBeginning(Node* head, int data) {
    Node* newNode = CreateNode(data);
    if (head == NULL) {
        newNode->next = newNode; // خودش به خودش اشاره کند
        return newNode;
    }

    Node* temp = head;
    // برو تا آخر لیست
    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
    head = newNode;
    return head;
}

// ✅ درج در انتهای لیست
Node* InsertAtEnd(Node* head, int data) {
    Node* newNode = CreateNode(data);
    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }

    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
    return head;
}

// ✅ درج در ایندکس مشخص
Node* InsertAtIndex(Node* head, int data, int index) {
    if (index == 0) {
        return InsertAtBeginning(head, data);
    }

    Node* newNode = CreateNode(data);
    Node* temp = head;
    int i = 0;

    while (i < index - 1 && temp->next != head) {
        temp = temp->next;
        i++;
    }

    if (temp->next == head && i < index - 1) {
        printf("Index out of range!\n");
        free(newNode);
        return head;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

// ✅ حذف از ابتدای لیست
Node* DeleteAtBeginning(Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return NULL;
    }

    if (head->next == head) { // فقط یک نود وجود دارد
        free(head);
        return NULL;
    }

    Node* temp = head;
    Node* last = head;
    while (last->next != head) {
        last = last->next;
    }

    head = head->next;
    last->next = head;
    free(temp);
    return head;
}

// ✅ حذف از انتهای لیست
Node* DeleteAtEnd(Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return NULL;
    }

    if (head->next == head) {
        free(head);
        return NULL;
    }

    Node* temp = head;
    Node* prev = NULL;

    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = head;
    free(temp);
    return head;
}

// ✅ حذف از ایندکس مشخص
Node* DeleteAtIndex(Node* head, int index) {
    if (head == NULL) {
        printf("List is empty!\n");
        return NULL;
    }

    if (index == 0) {
        return DeleteAtBeginning(head);
    }

    Node* temp = head;
    Node* prev = NULL;
    int i = 0;

    while (i < index && temp->next != head) {
        prev = temp;
        temp = temp->next;
        i++;
    }

    if (temp->next == head && i < index) {
        printf("Index out of range!\n");
        return head;
    }

    prev->next = temp->next;
    free(temp);
    return head;
}

// ✅ جستجو در لیست
void Search(Node* head, int key) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    Node* temp = head;
    int index = 0;
    do {
        if (temp->data == key) {
            printf("Found %d at index %d\n", key, index);
            return;
        }
        temp = temp->next;
        index++;
    } while (temp != head);

    printf("%d not found in the list.\n", key);
}

// ✅ نمایش لیست (از ابتدا تا آخر)
void Display(Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    Node* temp = head;
    printf("List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}

// ✅ تابع main
int main() {
    Node* head = NULL;

    head = InsertAtEnd(head, 10);
    head = InsertAtEnd(head, 20);
    head = InsertAtEnd(head, 30);
    head = InsertAtEnd(head, 40);

    printf("\nInitial List:\n");
    Display(head);

    head = InsertAtBeginning(head, 100);
    printf("\nAfter inserting 100 at beginning:\n");
    Display(head);

    head = InsertAtIndex(head, 500, 2);
    printf("\nAfter inserting 500 at index 2:\n");
    Display(head);

    head = DeleteAtBeginning(head);
    printf("\nAfter deleting from beginning:\n");
    Display(head);

    head = DeleteAtEnd(head);
    printf("\nAfter deleting from end:\n");
    Display(head);

    head = DeleteAtIndex(head, 2);
    printf("\nAfter deleting at index 2:\n");
    Display(head);

    Search(head, 30);
    Search(head, 200);

    return 0;
}