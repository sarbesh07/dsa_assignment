/*
program to implement the doubly linked list using structure
*/#include <stdio.h>
#include <stdlib.h>

/* structure for doubly linked list node */
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

/* create a new node */
struct Node* createNode(int value) {
    struct Node *temp;
    temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->prev = NULL;
    temp->next = NULL;
    return temp;
}

/* insert node at end */
struct Node* insertEnd(struct Node *head, int value) {
    struct Node *newNode = createNode(value);
    struct Node *ptr = head;

    if (head == NULL)
        return newNode;

    while (ptr->next != NULL)
        ptr = ptr->next;

    ptr->next = newNode;
    newNode->prev = ptr;

    return head;
}

/* insert after a given value */
struct Node* insertAfter(struct Node *head, int key, int value) {
    struct Node *ptr = head;

    while (ptr != NULL && ptr->data != key)
        ptr = ptr->next;

    if (ptr == NULL) {
        printf("Node with value %d not found\n", key);
        return head;
    }

    struct Node *newNode = createNode(value);
    newNode->next = ptr->next;
    newNode->prev = ptr;

    if (ptr->next != NULL)
        ptr->next->prev = newNode;

    ptr->next = newNode;

    return head;
}

/* delete a node with given value */
struct Node* deleteNode(struct Node *head, int key) {
    struct Node *ptr = head;

    while (ptr != NULL && ptr->data != key)
        ptr = ptr->next;

    if (ptr == NULL) {
        printf("Node with value %d not found\n", key);
        return head;
    }

    if (ptr->prev != NULL)
        ptr->prev->next = ptr->next;
    else
        head = ptr->next;   // deleting head node

    if (ptr->next != NULL)
        ptr->next->prev = ptr->prev;

    free(ptr);
    return head;
}

/* display list forward */
void displayList(struct Node *head) {
    struct Node *temp = head;
    printf("NULL <-> ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node *head = NULL;

    head = insertEnd(head, 10);
    head = insertEnd(head, 20);
    head = insertEnd(head, 30);

    printf("Initial Doubly Linked List:\n");
    displayList(head);

    printf("\nInserting 25 after 20:\n");
    head = insertAfter(head, 20, 25);
    displayList(head);

    printf("\nDeleting node with value 10:\n");
    head = deleteNode(head, 10);
    displayList(head);

    return 0;
}
