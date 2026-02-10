#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Global counters for comparisons and swaps
long long comparisons = 0;
long long swaps = 0;

// Swap function
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    swaps++;
}

// Display array
void displayArray(int arr[], int n) {
    printf("[ ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

// Bubble Sort
void bubbleSort(int arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            comparisons++;
            if(arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

// Selection Sort
void selectionSort(int arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        int minIdx = i;
        for(int j = i+1; j < n; j++) {
            comparisons++;
            if(arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        if(minIdx != i) {
            swap(&arr[i], &arr[minIdx]);
        }
    }
}

// Insertion Sort
void insertionSort(int arr[], int n) {
    for(int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        while(j >= 0) {
            comparisons++;
            if(arr[j] > key) {
                arr[j + 1] = arr[j];
                swaps++;
                j--;
            } else {
                break;
            }
        }
        arr[j + 1] = key;
    }
}

// Merge function for merge sort
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    int L[n1], R[n2];
    
    for(int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for(int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    
    int i = 0, j = 0, k = left;
    
    while(i < n1 && j < n2) {
        comparisons++;
        if(L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    while(i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    while(j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Merge Sort
void mergeSort(int arr[], int left, int right) {
    if(left < right) {
        int mid = left + (right - left) / 2;
        
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Reset counters
void resetCounters() {
    comparisons = 0;
    swaps = 0;
}

// Copy array
void copyArray(int dest[], int src[], int n) {
    for(int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
}

// Generate random array
void generateRandomArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        arr[i] = rand() % 1000 + 1;  // random numbers 1-1000
    }
}

int main() {
    int n, choice;
    
    printf("Sorting Algorithm Comparison\n");
    printf("============================\n\n");
    
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    int original[n], arr[n];
    
    srand(time(NULL));
    generateRandomArray(original, n);
    
    printf("\nOriginal array (%d elements):\n", n);
    if(n <= 20) {
        displayArray(original, n);
    } else {
        printf("First 20 elements: ");
        for(int i = 0; i < 20; i++) {
            printf("%d ", original[i]);
        }
        printf("...\n");
    }
    
    printf("\nChoose sorting algorithm:\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. Merge Sort\n");
    printf("Enter choice (1-4): ");
    scanf("%d", &choice);
    
    copyArray(arr, original, n);
    resetCounters();
    
    printf("\n");
    
    switch(choice) {
        case 1:
            printf("Using Bubble Sort...\n");
            bubbleSort(arr, n);
            break;
        case 2:
            printf("Using Selection Sort...\n");
            selectionSort(arr, n);
            break;
        case 3:
            printf("Using Insertion Sort...\n");
            insertionSort(arr, n);
            break;
        case 4:
            printf("Using Merge Sort...\n");
            mergeSort(arr, 0, n-1);
            break;
        default:
            printf("Invalid choice!\n");
            return 1;
    }
    
    printf("\nSorted array:\n");
    if(n <= 20) {
        displayArray(arr, n);
    } else {
        printf("First 20 elements: ");
        for(int i = 0; i < 20; i++) {
            printf("%d ", arr[i]);
        }
        printf("...\n");
    }
    
    printf("\nStatistics:\n");
    printf("===========\n");
    printf("Total comparisons: %lld\n", comparisons);
    
    if(choice != 4) {  // Merge sort doesn't count swaps the same way
        printf("Total swaps: %lld\n", swaps);
    }
    
    return 0;
}