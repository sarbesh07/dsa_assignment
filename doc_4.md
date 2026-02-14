# Program 4: Implementation of Doubly Linked List

## 1. Data Structure Definition
A doubly linked list is implemented using a structure that contains three fields: an integer data field, a pointer to the previous node, and a pointer to the next node. This structure allows traversal of the list in both forward and backward directions.

## 2. Description of Functions Implemented

 
- **createNode(int value)**  
  This function creates a new node dynamically and initializes its data, previous pointer, and next pointer.

- **insertEnd(struct Node *head, int value)**  
  This function inserts a new node at the end of the doubly linked list.

- **insertAfter(struct Node *head, int key, int value)**  
  This function inserts a new node after the node containing the given key value.

- **deleteNode(struct Node *head, int key)**  
  This function deletes a node with the specified value from the doubly linked list.

- **displayList(struct Node *head)**  
  This function displays the elements of the doubly linked list from beginning to end.

## 3. Overview of main() Function
The `main()` function creates a doubly linked list by inserting nodes at the end. It then demonstrates insertion after a given node and deletion of a specified node. The linked list is displayed after each operation to show the changes.

## 4. Sample Output
```
Initial Doubly Linked List:
NULL <-> 10 <-> 20 <-> 30 <-> NULL

Inserting 25 after 20:
NULL <-> 10 <-> 20 <-> 25 <-> 30 <-> NULL

Deleting node with value 10:
NULL <-> 20 <-> 25 <-> 30 <-> NULL
```

## 5. Conclusion
This program demonstrates the implementation of a doubly linked list using structures. It shows how insertion after a given node and deletion of a node can be performed efficiently using previous and next pointers.

