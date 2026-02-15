/*
 program to build the min and max heap,given the array of the data(unsorted) 
*/
#include <stdio.h>

#define MAX 100

/* function to swap two elements */
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* heapify for min heap */
void minHeapify(int arr[], int n, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

/* build min heap */
void buildMinHeap(int arr[], int n) {
    int i;
    for (i = n/2 - 1; i >= 0; i--)
        minHeapify(arr, n, i);
}

/* heapify for max heap */
void maxHeapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

/* build max heap */
void buildMaxHeap(int arr[], int n) {
    int i;
    for (i = n/2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);
}

/* display array */
void display(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr1[MAX], arr2[MAX];
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr1[i]);
        arr2[i] = arr1[i];   // copy array
    }

    buildMinHeap(arr1, n);
    buildMaxHeap(arr2, n);

    printf("\nMin Heap:\n");
    display(arr1, n);

    printf("Max Heap:\n");
    display(arr2, n);

    return 0;
}
