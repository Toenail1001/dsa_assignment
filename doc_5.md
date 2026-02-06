# Program 5 - Graph with BFS and DFS

## What it does
Implements an undirected graph using adjacency matrix and performs BFS and DFS traversals.

## Data Structure

**Graph structure:**
```c
typedef struct {
    int vertices;
    int adjMatrix[MAX][MAX];
} Graph;
```

Uses adjacency matrix where `adjMatrix[i][j] = 1` means there's an edge between vertex i and j.

**Global arrays for BFS and DFS:**
- `queue[]` - for BFS traversal
- `stack[]` - for DFS traversal

## Functions

**Graph operations:**
- `initGraph()` - initializes graph with given vertices
- `addEdge()` - adds edge between two vertices (undirected)
- `displayGraph()` - prints adjacency matrix

**Queue operations (for BFS):**
- `enqueue()` - add to queue
- `dequeue()` - remove from queue
- `isQueueEmpty()` - check if queue empty

**Stack operations (for DFS):**
- `push()` - add to stack
- `pop()` - remove from stack
- `isStackEmpty()` - check if stack empty

**Traversal algorithms:**
- `BFS()` - Breadth First Search
- `DFS()` - Depth First Search

## How BFS works

1. Start from given vertex, mark as visited
2. Add to queue
3. While queue not empty:
   - Dequeue vertex
   - Print it
   - Add all unvisited neighbors to queue
   
Visits level by level (breadth-wise).

## How DFS works

1. Push starting vertex to stack
2. While stack not empty:
   - Pop vertex
   - If not visited, mark and print
   - Push all unvisited neighbors
   
Goes deep into graph before backtracking.

## Sample Output

```
Graph Implementation using Adjacency Matrix
============================================

Enter number of vertices: 5
Enter number of edges: 7
Enter edges (src dest):
0 1
0 2
1 3
1 4
2 4
3 4
2 3

Adjacency Matrix:
   0 1 2 3 4 
0: 0 1 1 0 0 
1: 1 0 0 1 1 
2: 1 0 0 1 1 
3: 0 1 1 0 1 
4: 0 1 1 1 0 

Enter starting vertex for traversal: 0

BFS Traversal starting from vertex 0: 0 1 2 3 4 
DFS Traversal starting from vertex 0: 0 1 3 2 4
```

## Graph used in example

```
    0
   / \
  1   2
 / \ / \
3   4   
 \ /
  
```

Vertices: 0, 1, 2, 3, 4
Edges: (0,1), (0,2), (1,3), (1,4), (2,3), (2,4), (3,4)

## How to Run

```bash
gcc prog_5.c -o prog_5
./prog_5
```

Then enter:
- Number of vertices
- Number of edges  
- Each edge as two vertices
- Starting vertex for traversal

## BFS vs DFS

**BFS:**
- Uses queue
- Visits level by level
- Good for shortest path

**DFS:**
- Uses stack
- Goes deep first
- Good for detecting cycles