# Program 6: Build Min Heap and Max Heap

## 1. Data Structure Definition
A heap is a complete binary tree represented using an array. 
For any element at index i:
Left child = 2*i + 1  
Right child = 2*i + 2  

In a Min Heap, the parent node is smaller than its children.  
In a Max Heap, the parent node is greater than its children.

## 2. Description of Functions

- swap()  
  Swaps two elements.

- minHeapify()  
  Ensures the subtree satisfies the min heap property.

- buildMinHeap()  
  Converts the array into a min heap.

- maxHeapify()  
  Ensures the subtree satisfies the max heap property.

- buildMaxHeap()  
  Converts the array into a max heap.

## 3. Overview of main()
The main function takes input from the user and stores it in an array. 
It builds both min heap and max heap from the same data and displays the result.

## 4. Sample Output
```
Enter number of elements: 6
Enter elements:
10 20 5 30 40 2

Min Heap:
2 20 5 30 40 10
Max Heap:
40 30 5 10 20 2
```

## 5. Conclusion
This program demonstrates how to build both min heap and max heap from an unsorted array using heapify operations.

