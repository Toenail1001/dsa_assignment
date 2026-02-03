# Program 3 - Reverse Traversal in Linked List

## What it does
Creates a linked list and traverses it in reverse order using recursion.

## Data Structure

Simple singly linked list node:

```c
struct Node {
    int data;
    struct Node* next;
};
```

Each node has:
- `data` - stores the integer value
- `next` - pointer to next node

## Functions

**Node creation:**
- `createNode()` - creates a new node with given data

**Insertion:**
- `insertAtBeginning()` - adds node at the start
- `insertAtEnd()` - adds node at the end

**Traversal:**
- `traverse()` - prints list from start to end (normal)
- `reverseTraversal()` - recursive function that prints in reverse
- `displayReverse()` - wrapper function for reverse traversal

## How Reverse Traversal Works

Uses recursion:
1. If node is NULL, return
2. Recursively call for next node
3. Print current node's data while coming back

This way it reaches the end first, then prints while unwinding the recursion.

## main() Function

Creates two linked lists and demonstrates both forward and reverse traversal:
- First list: 10 -> 20 -> 30 -> 40 -> 50
- Second list: 1 -> 2 -> 3 -> 4 -> 5

## Sample Output

```
Linked List - Reverse Traversal Demo
=====================================

Creating linked list...

Forward traversal:
10 -> 20 -> 30 -> 40 -> 50 -> NULL

Reverse traversal:
50 -> 40 -> 30 -> 20 -> 10 -> NULL


Creating another list...

Forward traversal:
1 -> 2 -> 3 -> 4 -> 5 -> NULL

Reverse traversal:
5 -> 4 -> 3 -> 2 -> 1 -> NULL
```

## How to Run

```bash
gcc prog_3.c -o prog_3
./prog_3
```
It works as expected.