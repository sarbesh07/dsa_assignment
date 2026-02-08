# Program 3: Reverse Traversal of a Singly Linked List

## 1. Data Structure Definition
In this program, a singly linked list is implemented using a structure. Each node of the linked list contains two parts: an integer data field to store the value and a pointer that stores the address of the next node in the list. The last node of the linked list points to NULL, which indicates the end of the list.

## 2. Description of Functions Implemented

- **createNode(int value)**  
  This function dynamically allocates memory for a new node, assigns the given value to the data field, and initializes the next pointer to NULL.

- **insertEnd(struct Node *head, int value)**  
  This function inserts a new node at the end of the linked list. If the list is empty, the new node becomes the head of the list.

- **displayList(struct Node *head)**  
  This function traverses the linked list from the beginning and prints all the elements in normal order.

- **reversePrint(struct Node *head)**  
  This function prints the elements of the linked list in reverse order using recursion. It first reaches the last node and then prints the data while returning back through recursive calls.

## 3. Overview of main() Function
The `main()` function starts by taking input from the user for the number of nodes and their values. It creates the linked list by inserting nodes at the end. After constructing the list, it first displays the linked list in normal order and then displays the elements in reverse order using the reverse traversal function.

## 4. Sample Output
```
Enter number of nodes: 4
Enter value: 10
Enter value: 20
Enter value: 30
Enter value: 40

Linked List (Normal Order):
10 -> 20 -> 30 -> 40 -> NULL

Linked List (Reverse Traversal):
40 -> 30 -> 20 -> 10 -> NULL
```
## 5. Conclusion
This program demonstrates the implementation of reverse traversal in a singly linked list. By using recursion, the linked list is traversed in reverse order without modifying the original list structure. This approach helps in understanding recursive function calls and linked list traversal techniques.
