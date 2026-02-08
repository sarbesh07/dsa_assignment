/*
program to implement the reverse traversal algorithm in the linked list
*/
#include <stdio.h>
#include <stdlib.h>
/* structure for linked list node */
struct Node {
    int data;
    struct Node *next;
};
/* creating a new node */
struct Node* createNode(int value) {
    struct Node *temp;
    temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->next = NULL;
    return temp;
}
/* inserting node at end */
struct Node* insertEnd(struct Node *head, int value) {
    struct Node *newNode = createNode(value);
    struct Node *ptr = head;
    if (head == NULL)
        return newNode;
    while (ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = newNode;
    return head;
}
/* displaying the list normally */
void displayList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
/* Reverse traversal using recursion */
void reversePrint(struct Node *head) {
    if (head == NULL)
        return;
    reversePrint(head->next);
    printf("%d -> ", head->data);
}
int main() {
    struct Node *head = NULL;
    int i, n, value;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &value);
        head = insertEnd(head, value);
    }
    printf("\nLinked List (Normal Order):\n");
    displayList(head);
    printf("\nLinked List (Reverse Traversal):\n");
    reversePrint(head);
    printf("NULL\n");
    return 0;
}
