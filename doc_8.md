# Program 8 - Sorting Algorithm Comparison

## What it does
Generates random array of N integers and sorts them using chosen algorithm. Displays comparisons and swaps performed.

## Sorting Algorithms Implemented

1. **Bubble Sort** - compares adjacent elements and swaps
2. **Selection Sort** - finds minimum and places it
3. **Insertion Sort** - builds sorted array one element at a time
4. **Merge Sort** - divide and conquer approach

## Functions

**Sorting algorithms:**
- `bubbleSort()` - O(n²) time complexity
- `selectionSort()` - O(n²) time complexity
- `insertionSort()` - O(n²) time complexity
- `mergeSort()` - O(n log n) time complexity
- `merge()` - helper for merge sort

**Helper functions:**
- `swap()` - swaps two elements and counts
- `generateRandomArray()` - creates random array
- `copyArray()` - copies array for sorting
- `displayArray()` - prints array
- `resetCounters()` - resets statistics

**Global counters:**
- `comparisons` - tracks number of comparisons
- `swaps` - tracks number of swaps

## How Each Algorithm Works

### Bubble Sort
1. Compare adjacent elements
2. Swap if in wrong order
3. Repeat until no swaps needed
- Multiple passes through array

### Selection Sort
1. Find minimum in unsorted part
2. Swap with first unsorted element
3. Move boundary of sorted part
- One swap per pass

### Insertion Sort
1. Start with first element as sorted
2. Take next element
3. Insert it in correct position in sorted part
- Good for nearly sorted data

### Merge Sort
1. Divide array into halves
2. Recursively sort each half
3. Merge sorted halves
- Most efficient of the four

## Sample Output

```
Sorting Algorithm Comparison
============================

Enter number of elements: 10

Original array (10 elements):
[ 362 457 643 64 684 688 654 237 132 360 ]

Choose sorting algorithm:
1. Bubble Sort
2. Selection Sort
3. Insertion Sort
4. Merge Sort
Enter choice (1-4): 1

Using Bubble Sort...

Sorted array:
[ 64 132 237 360 362 457 643 654 684 688 ]

Statistics:
===========
Total comparisons: 45
Total swaps: 24
```

## Another Example (Merge Sort)

```
Original array (10 elements):
[ 905 242 317 579 30 953 713 521 43 751 ]

Choose sorting algorithm:
1. Bubble Sort
2. Selection Sort
3. Insertion Sort
4. Merge Sort
Enter choice (1-4): 4

Using Merge Sort...

Sorted array:
[ 30 43 242 317 521 579 713 751 905 953 ]

Statistics:
===========
Total comparisons: 24
```

## How to Run

```bash
gcc prog_8.c -o prog_8
./prog_8
```

Input:
- Number of elements (N)
- Choice of algorithm (1-4)

## Performance Comparison

For 10 elements (example):
- **Bubble Sort:** 45 comparisons, 24 swaps
- **Merge Sort:** 24 comparisons

For larger arrays (N=100):
- Bubble/Selection/Insertion: ~10,000 comparisons
- Merge Sort: ~664 comparisons

## Time Complexity

| Algorithm | Best Case | Average Case | Worst Case |
|-----------|-----------|--------------|------------|
| Bubble | O(n) | O(n²) | O(n²) |
| Selection | O(n²) | O(n²) | O(n²) |
| Insertion | O(n) | O(n²) | O(n²) |
| Merge | O(n log n) | O(n log n) | O(n log n) |

## Space Complexity

- Bubble, Selection, Insertion: O(1)
- Merge: O(n)

## When to Use Each

**Bubble Sort:** Educational purposes, nearly sorted data  
**Selection Sort:** When swaps are expensive  
**Insertion Sort:** Small arrays, nearly sorted data  
**Merge Sort:** Large arrays, guaranteed performance