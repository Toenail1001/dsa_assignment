# Program 4 - Doubly Linked List

## What it does
Implements doubly linked list with insert after node and delete node operations.

## Data Structure

```c
typedef struct node{
    int data;
    struct node* next;
    struct node* prev;
}Node;

Node* head = NULL;  // global head pointer
```

## Functions

**Display:**
- `displayList()` - prints the list

**Insertion:**
- `insertBegin()` - insert at beginning
- `insertEnd()` - insert at end  
- `insertAfterNode()` - **required** - insert after given node

**Deletion:**
- `deleteBegin()` - delete from beginning
- `deleteEnd()` - delete from end
- `deleteNode()` - **required** - delete node by value

## How insertAfterNode works

Takes a node pointer and value:
1. Creates new node
2. Sets new node's prev to given node
3. Sets new node's next to given node's next
4. Updates pointers of adjacent nodes

```c
newNode->prev = pre;
newNode->next = pre->next;
if(pre->next != NULL){
    pre->next->prev = newNode;
}
pre->next = newNode;
```

## How deleteNode works

Takes value to delete:
1. Searches for node with that value
2. Updates prev node's next pointer
3. Updates next node's prev pointer  
4. Frees the node

## Sample Output

```
Doubly Linked List Demo
========================

Empty list 
After inserting at beginning: [ 30 20 10  ]
After inserting at end: [ 30 20 10 40 50  ]

Inserting 25 after head (30):
[ 30 25 20 10 40 50  ]
Inserting 15 after second node (20):
[ 30 25 20 15 10 40 50  ]

Deleting from beginning:
[ 25 20 15 10 40 50  ]
Deleting from end:
[ 25 20 15 10 40  ]

Deleting node with value 20:
Deleted node with value 20
[ 25 15 10 40  ]
Deleting node with value 10:
Deleted node with value 10
[ 25 15 40  ]
```

## How to Run

```bash
gcc prog_4.c -o prog_4
./prog_4
```