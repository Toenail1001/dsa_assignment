# Program 7 - Dijkstra's Shortest Path Algorithm

## What it does
Finds shortest path from a source vertex to all other vertices in a weighted graph using Dijkstra's algorithm.

## Data Structure

**Graph:**
```c
typedef struct {
    int vertices;
    int adjMatrix[MAX][MAX];
} Graph;
```

Uses weighted adjacency matrix where `adjMatrix[i][j]` stores weight of edge between i and j.

**Arrays used in algorithm:**
- `dist[]` - shortest distance from source
- `visited[]` - tracks visited vertices
- `parent[]` - stores path (for reconstruction)

## Functions

**Graph operations:**
- `initGraph()` - initialize graph
- `addEdge()` - add weighted edge
- `displayGraph()` - show adjacency matrix

**Algorithm functions:**
- `minDistance()` - find unvisited vertex with minimum distance
- `dijkstra()` - main algorithm
- `printPath()` - prints path from source to destination

## How Dijkstra's Algorithm Works

1. Initialize all distances to infinity except source (0)
2. Mark all vertices as unvisited
3. Repeat until all vertices visited:
   - Pick unvisited vertex with minimum distance
   - Mark it as visited
   - Update distances of all adjacent unvisited vertices
4. Distance is updated if: current_dist + edge_weight < old_dist

## Algorithm Steps

For each vertex:
1. Select vertex u with minimum distance that's unvisited
2. Mark u as visited
3. For each neighbor v of u:
   - If dist[u] + weight(u,v) < dist[v]
   - Update dist[v] = dist[u] + weight(u,v)
   - Set parent[v] = u

## Sample Output

```
Dijkstra's Shortest Path Algorithm
===================================

Enter number of vertices: 6
Enter number of edges: 9
Enter edges (src dest weight):
0 1 4
0 2 2
1 2 1
1 3 5
2 3 8
2 4 10
3 4 2
3 5 6
4 5 3

Adjacency Matrix (weights):
     0   1   2   3   4   5 
0:   -   4   2   -   -   - 
1:   4   -   1   5   -   - 
2:   2   1   -   8  10   - 
3:   -   5   8   -   2   6 
4:   -   -  10   2   -   3 
5:   -   -   -   6   3   - 

Enter source vertex: 0

Shortest paths from vertex 0:
==================================
Vertex	Distance	Path
----------------------------------
0	0		0
1	3		0 -> 2 -> 1
2	2		0 -> 2
3	8		0 -> 2 -> 1 -> 3
4	10		0 -> 2 -> 1 -> 3 -> 4
5	13		0 -> 2 -> 1 -> 3 -> 4 -> 5
```

## Example Graph

```
    (4)
  0-----1
  |\    |\(5)
(2)| \(1)| \
  |  \  |  3
  2---\ |(2)|(6)
  |\(8)\|/  |
(10)\ --4   |
  |  (3)\  /
  |------5
```

Weights shown in parentheses.

## Shortest Path Example

From vertex 0 to vertex 5:
- Path: 0 -> 2 -> 1 -> 3 -> 4 -> 5
- Total distance: 2 + 1 + 5 + 2 + 3 = 13

## How to Run

```bash
gcc prog_7.c -o prog_7
./prog_7
```

Input:
- Number of vertices
- Number of edges
- Each edge as: source destination weight
- Source vertex for shortest path calculation

## Time Complexity

- O(V²) where V is number of vertices
- Can be improved to O(E log V) using priority queue

## Use Cases

- GPS navigation (shortest route)
- Network routing protocols
- Flight path optimization
- Any shortest path problem with non-negative weights