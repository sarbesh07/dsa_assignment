/*
program to generate N random integers in range [1,1000],allow user to choose a sorting algorithm,
sort the numbers,and display number of comparisons and swaps.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000

/* Bubble Sort */
void bubbleSort(int arr[], int n, int *comp, int *swap) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            (*comp)++;
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                (*swap)++;
            }
        }
    }
}

/* Selection Sort */
void selectionSort(int arr[], int n, int *comp, int *swap) {
    int i, j, min_index, temp;
    for (i = 0; i < n - 1; i++) {
        min_index = i;
        for (j = i + 1; j < n; j++) {
            (*comp)++;
            if (arr[j] < arr[min_index])
                min_index = j;
        }
        if (min_index != i) {
            temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
            (*swap)++;
        }
    }
}

/* Insertion Sort */
void insertionSort(int arr[], int n, int *comp, int *swap) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0) {
            (*comp)++;
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                (*swap)++;
                j--;
            } else {
                break;
            }
        }
        arr[j + 1] = key;
    }
}

/* Merge Function */
void merge(int arr[], int left, int mid, int right, int *comp) {
    int i = left, j = mid + 1, k = 0;
    int temp[MAX];

    while (i <= mid && j <= right) {
        (*comp)++;
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left, k = 0; i <= right; i++, k++)
        arr[i] = temp[k];
}

/* Merge Sort */
void mergeSort(int arr[], int left, int right, int *comp) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid, comp);
        mergeSort(arr, mid + 1, right, comp);
        merge(arr, left, mid, right, comp);
    }
}

/* Display array */
void display(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[MAX];
    int n, choice;
    int comparisons = 0, swaps = 0;
    int i;

    printf("Enter value of N: ");
    scanf("%d", &n);

    srand(time(0));

    for (i = 0; i < n; i++)
        arr[i] = rand() % 1000 + 1;

    printf("\nNumbers before sorting:\n");
    display(arr, n);

    printf("\nChoose sorting algorithm:\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. Merge Sort\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            bubbleSort(arr, n, &comparisons, &swaps);
            break;
        case 2:
            selectionSort(arr, n, &comparisons, &swaps);
            break;
        case 3:
            insertionSort(arr, n, &comparisons, &swaps);
            break;
        case 4:
            mergeSort(arr, 0, n - 1, &comparisons);
            break;
        default:
            printf("Invalid choice\n");
            return 0;
    }

    printf("\nNumbers after sorting:\n");
    display(arr, n);

    printf("\nTotal Comparisons: %d\n", comparisons);

    if (choice != 4)
        printf("Total Swaps: %d\n", swaps);
    else
        printf("Swaps not counted for Merge Sort\n");

    return 0;
}
