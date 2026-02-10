#include<stdio.h>
#include<stdlib.h>

#define MAX 100

// Swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify for max heap
void maxHeapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if(left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    
    if(right < n && arr[right] > arr[largest]) {
        largest = right;
    }
    
    if(largest != i) {
        swap(&arr[i], &arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

// Build max heap
void buildMaxHeap(int arr[], int n) {
    // Start from last non-leaf node
    for(int i = n/2 - 1; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }
}

// Heapify for min heap
void minHeapify(int arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if(left < n && arr[left] < arr[smallest]) {
        smallest = left;
    }
    
    if(right < n && arr[right] < arr[smallest]) {
        smallest = right;
    }
    
    if(smallest != i) {
        swap(&arr[i], &arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

// Build min heap
void buildMinHeap(int arr[], int n) {
    // Start from last non-leaf node
    for(int i = n/2 - 1; i >= 0; i--) {
        minHeapify(arr, n, i);
    }
}

// Display array
void displayArray(int arr[], int n) {
    printf("[ ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

// Display heap in tree format
void displayHeapTree(int arr[], int n) {
    int level = 0;
    int levelNodes = 1;
    int printed = 0;
    
    while(printed < n) {
        for(int i = 0; i < levelNodes && printed < n; i++) {
            printf("%d ", arr[printed]);
            printed++;
        }
        printf("\n");
        levelNodes *= 2;
        level++;
    }
}

int main() {
    int arr[MAX];
    int n;
    
    printf("Min and Max Heap Builder\n");
    printf("========================\n\n");
    
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("\nOriginal array: ");
    displayArray(arr, n);
    
    // Build max heap
    int maxHeap[MAX];
    for(int i = 0; i < n; i++) {
        maxHeap[i] = arr[i];
    }
    buildMaxHeap(maxHeap, n);
    
    printf("\n--- MAX HEAP ---\n");
    printf("Array representation: ");
    displayArray(maxHeap, n);
    printf("\nTree representation:\n");
    displayHeapTree(maxHeap, n);
    
    // Build min heap
    int minHeap[MAX];
    for(int i = 0; i < n; i++) {
        minHeap[i] = arr[i];
    }
    buildMinHeap(minHeap, n);
    
    printf("\n--- MIN HEAP ---\n");
    printf("Array representation: ");
    displayArray(minHeap, n);
    printf("\nTree representation:\n");
    displayHeapTree(minHeap, n);
    
    return 0;
}