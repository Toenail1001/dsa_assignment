#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define MAX 20
#define INF INT_MAX

// Graph structure
typedef struct {
    int vertices;
    int adjMatrix[MAX][MAX];
} Graph;

// Initialize graph
void initGraph(Graph* g, int v) {
    g->vertices = v;
    for(int i = 0; i < v; i++) {
        for(int j = 0; j < v; j++) {
            g->adjMatrix[i][j] = 0;
        }
    }
}

// Add weighted edge
void addEdge(Graph* g, int src, int dest, int weight) {
    g->adjMatrix[src][dest] = weight;
    g->adjMatrix[dest][src] = weight;  // for undirected graph
}

// Display graph
void displayGraph(Graph* g) {
    printf("\nAdjacency Matrix (weights):\n");
    printf("   ");
    for(int i = 0; i < g->vertices; i++) {
        printf("%3d ", i);
    }
    printf("\n");
    
    for(int i = 0; i < g->vertices; i++) {
        printf("%d: ", i);
        for(int j = 0; j < g->vertices; j++) {
            if(g->adjMatrix[i][j] == 0)
                printf("  - ");
            else
                printf("%3d ", g->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// Find vertex with minimum distance
int minDistance(int dist[], int visited[], int n) {
    int min = INF;
    int minIndex = -1;
    
    for(int i = 0; i < n; i++) {
        if(!visited[i] && dist[i] < min) {
            min = dist[i];
            minIndex = i;
        }
    }
    
    return minIndex;
}

// Print path from source to destination
void printPath(int parent[], int vertex) {
    if(parent[vertex] == -1) {
        printf("%d", vertex);
        return;
    }
    
    printPath(parent, parent[vertex]);
    printf(" -> %d", vertex);
}

// Dijkstra's algorithm
void dijkstra(Graph* g, int src) {
    int dist[MAX];      // shortest distance from source
    int visited[MAX];   // visited vertices
    int parent[MAX];    // to store path
    
    // Initialize
    for(int i = 0; i < g->vertices; i++) {
        dist[i] = INF;
        visited[i] = 0;
        parent[i] = -1;
    }
    
    dist[src] = 0;
    
    // Find shortest path for all vertices
    for(int count = 0; count < g->vertices - 1; count++) {
        int u = minDistance(dist, visited, g->vertices);
        
        if(u == -1) break;
        
        visited[u] = 1;
        
        // Update distances of adjacent vertices
        for(int v = 0; v < g->vertices; v++) {
            if(!visited[v] && g->adjMatrix[u][v] != 0 && 
               dist[u] != INF && 
               dist[u] + g->adjMatrix[u][v] < dist[v]) {
                dist[v] = dist[u] + g->adjMatrix[u][v];
                parent[v] = u;
            }
        }
    }
    
    // Print results
    printf("\nShortest paths from vertex %d:\n", src);
    printf("==================================\n");
    printf("Vertex\tDistance\tPath\n");
    printf("----------------------------------\n");
    
    for(int i = 0; i < g->vertices; i++) {
        printf("%d\t", i);
        if(dist[i] == INF) {
            printf("INF\t\tNo path\n");
        } else {
            printf("%d\t\t", dist[i]);
            printPath(parent, i);
            printf("\n");
        }
    }
}

int main() {
    Graph g;
    int vertices, edges, src, dest, weight, startVertex;
    
    printf("Dijkstra's Shortest Path Algorithm\n");
    printf("===================================\n\n");
    
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    
    initGraph(&g, vertices);
    
    printf("Enter number of edges: ");
    scanf("%d", &edges);
    
    printf("Enter edges (src dest weight):\n");
    for(int i = 0; i < edges; i++) {
        scanf("%d %d %d", &src, &dest, &weight);
        addEdge(&g, src, dest, weight);
    }
    
    displayGraph(&g);
    
    printf("\nEnter source vertex: ");
    scanf("%d", &startVertex);
    
    dijkstra(&g, startVertex);
    
    return 0;
}