# Program 6 - Min and Max Heap Builder

## What it does
Takes an unsorted array and builds both min heap and max heap from it.

## Data Structure

Heap is stored in array format:
- Parent at index i
- Left child at 2*i + 1
- Right child at 2*i + 2

**Max Heap:** Parent >= Children  
**Min Heap:** Parent <= Children

## Functions

**Helper:**
- `swap()` - swaps two elements

**Max Heap:**
- `maxHeapify()` - maintains max heap property
- `buildMaxHeap()` - builds max heap from array

**Min Heap:**
- `minHeapify()` - maintains min heap property
- `buildMinHeap()` - builds min heap from array

**Display:**
- `displayArray()` - prints array
- `displayHeapTree()` - prints heap in tree format

## How maxHeapify works

1. Takes node at index i
2. Compares with left and right children
3. Finds largest among parent and children
4. If largest is not parent, swap and recursively heapify

## How buildMaxHeap works

1. Start from last non-leaf node (n/2 - 1)
2. Call maxHeapify on each node going backwards
3. This builds heap from bottom up

Same logic for min heap but finds smallest instead.

## Sample Output

```
Min and Max Heap Builder
========================

Enter number of elements: 7
Enter 7 elements:
10 20 15 30 40 50 25

Original array: [ 10 20 15 30 40 50 25 ]

--- MAX HEAP ---
Array representation: [ 50 40 25 30 20 15 10 ]

Tree representation:
50 
40 25 
30 20 15 10 

--- MIN HEAP ---
Array representation: [ 10 20 15 30 40 50 25 ]

Tree representation:
10 
20 15 
30 40 50 25
```

## Visual Explanation

**Max Heap Tree:**
```
       50
      /  \
    40    25
   / \   / \
  30 20 15 10
```
Parent is always larger than children.

**Min Heap Tree:**
```
       10
      /  \
    20    15
   / \   / \
  30 40 50 25
```
Parent is always smaller than children.

## How to Run

```bash
gcc prog_6.c -o prog_6
./prog_6
```

Enter number of elements and the elements.

## Heap Properties

**Max Heap:**
- Root is maximum element
- Used in heap sort (descending)
- Used in priority queues

**Min Heap:**
- Root is minimum element
- Used in heap sort (ascending)
- Used in finding smallest k elements

## Time Complexity

- buildHeap: O(n)
- heapify: O(log n)