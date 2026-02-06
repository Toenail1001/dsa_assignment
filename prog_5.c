#include<stdio.h>
#include<stdlib.h>

#define MAX 20

// Graph structure using adjacency matrix
typedef struct {
    int vertices;
    int adjMatrix[MAX][MAX];
} Graph;

// Queue for BFS
int queue[MAX];
int front = -1, rear = -1;

// Stack for DFS (using array)
int stack[MAX];
int top = -1;

// Initialize graph
void initGraph(Graph* g, int v) {
    g->vertices = v;
    for(int i = 0; i < v; i++) {
        for(int j = 0; j < v; j++) {
            g->adjMatrix[i][j] = 0;
        }
    }
}

// Add edge (undirected graph)
void addEdge(Graph* g, int src, int dest) {
    g->adjMatrix[src][dest] = 1;
    g->adjMatrix[dest][src] = 1;  // for undirected graph
}

// Display adjacency matrix
void displayGraph(Graph* g) {
    printf("\nAdjacency Matrix:\n");
    printf("   ");
    for(int i = 0; i < g->vertices; i++) {
        printf("%d ", i);
    }
    printf("\n");
    
    for(int i = 0; i < g->vertices; i++) {
        printf("%d: ", i);
        for(int j = 0; j < g->vertices; j++) {
            printf("%d ", g->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// Queue operations
void enqueue(int value) {
    if(rear == MAX - 1) {
        printf("Queue full\n");
        return;
    }
    if(front == -1) front = 0;
    queue[++rear] = value;
}

int dequeue() {
    if(front == -1 || front > rear) {
        return -1;
    }
    return queue[front++];
}

int isQueueEmpty() {
    return (front == -1 || front > rear);
}

// Stack operations
void push(int value) {
    if(top == MAX - 1) {
        printf("Stack full\n");
        return;
    }
    stack[++top] = value;
}

int pop() {
    if(top == -1) {
        return -1;
    }
    return stack[top--];
}

int isStackEmpty() {
    return (top == -1);
}

// BFS traversal
void BFS(Graph* g, int startVertex) {
    int visited[MAX] = {0};
    
    printf("BFS Traversal starting from vertex %d: ", startVertex);
    
    visited[startVertex] = 1;
    enqueue(startVertex);
    
    while(!isQueueEmpty()) {
        int currentVertex = dequeue();
        printf("%d ", currentVertex);
        
        // Visit all adjacent vertices
        for(int i = 0; i < g->vertices; i++) {
            if(g->adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
    printf("\n");
}

// DFS traversal (iterative using stack)
void DFS(Graph* g, int startVertex) {
    int visited[MAX] = {0};
    
    printf("DFS Traversal starting from vertex %d: ", startVertex);
    
    push(startVertex);
    
    while(!isStackEmpty()) {
        int currentVertex = pop();
        
        if(!visited[currentVertex]) {
            printf("%d ", currentVertex);
            visited[currentVertex] = 1;
        }
        
        // Push all adjacent unvisited vertices
        for(int i = g->vertices - 1; i >= 0; i--) {
            if(g->adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                push(i);
            }
        }
    }
    printf("\n");
}

// Reset queue and stack
void reset() {
    front = -1;
    rear = -1;
    top = -1;
}

int main() {
    Graph g;
    int vertices, edges, src, dest, startVertex;
    
    printf("Graph Implementation using Adjacency Matrix\n");
    printf("============================================\n\n");
    
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    
    initGraph(&g, vertices);
    
    printf("Enter number of edges: ");
    scanf("%d", &edges);
    
    printf("Enter edges (src dest):\n");
    for(int i = 0; i < edges; i++) {
        scanf("%d %d", &src, &dest);
        addEdge(&g, src, dest);
    }
    
    displayGraph(&g);
    
    printf("\nEnter starting vertex for traversal: ");
    scanf("%d", &startVertex);
    
    printf("\n");
    reset();
    BFS(&g, startVertex);
    
    reset();
    DFS(&g, startVertex);
    
    return 0;
}