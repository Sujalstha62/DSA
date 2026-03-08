#include <stdio.h>
#include <stdlib.h>

#define MAX 20

// Graph structure
typedef struct {
    int vertices;
    int adj[MAX][MAX];
} Graph;

// Simple Queue for BFS
int queue[MAX];
int front = -1, rear = -1;

void enqueue(int v) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = v;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

// 1. Breadth-First Search (Level-order)
void BFS(Graph* g, int startNode) {
	int i;
    int visited[MAX] = {0};
    front = rear = -1; // Reset queue

    printf("BFS Traversal: ");
    
    visited[startNode] = 1;
    enqueue(startNode);

    while (front <= rear && front != -1) {
        int current = dequeue();
        if (current == -1) break;

        printf("%d ", current);

        for (i = 0; i < g->vertices; i++) {
            if (g->adj[current][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
    printf("\n");
}

// 2. Depth-First Search (Recursive)
void DFS_Recursive(Graph* g, int current, int visited[]) {
	int i;
    visited[current] = 1;
    printf("%d ", current);

    for (i = 0; i < g->vertices; i++) {
        if (g->adj[current][i] == 1 && !visited[i]) {
            DFS_Recursive(g, i, visited);
        }
    }
}

void DFS(Graph* g, int startNode) {
    int visited[MAX] = {0};
    printf("DFS Traversal: ");
    DFS_Recursive(g, startNode, visited);
    printf("\n");
}

int main() {
    Graph g;
    int v, i,j,e, src, dest, choice, startNode;
    char ch;

    printf("Enter number of vertices: ");
    scanf("%d", &v);
    g.vertices = v;

    // Initialize adjacency matrix to 0
    for (i = 0; i < v; i++)
        for (j = 0; j < v; j++)
            g.adj[i][j] = 0;

    printf("Enter number of edges: ");
    scanf("%d", &e);

    for (i = 0; i < e; i++) {
        printf("Enter edge %d (src dest): ", i + 1);
        scanf("%d %d", &src, &dest);
        if (src < v && dest < v) {
            g.adj[src][dest] = 1;
            g.adj[dest][src] = 1; // Undirected graph
        }
    }

    do {
        printf("\n--- Traversal Menu ---");
        printf("\n1) BFS\n2) DFS\n3) Exit\nChoice: ");
        scanf("%d", &choice);

        if (choice == 3) break;

        printf("Enter starting node (0 to %d): ", v - 1);
        scanf("%d", &startNode);

        if (choice == 1) BFS(&g, startNode);
        else if (choice == 2) DFS(&g, startNode);

        printf("\nContinue? (y/n): ");
        scanf(" %c", &ch);
    } while (ch == 'y' || ch == 'Y');

    return 0;
}
