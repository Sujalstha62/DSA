#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define N 20
#define INF 999999
// 1. Structure to represent the MST results
typedef struct {
    int parent;
    int weight;
} MSTResult;
// 2. Graph Structure
typedef struct {
    int vertices;
    int adj[N][N];
} Graph;
void initGraph(Graph* g, int v) {
	int i,j;
    g->vertices = v;
    for (i = 0; i < v; i++) {
        for ( j = 0; j < v; j++) {
            g->adj[i][j] = (i == j) ? 0 : INF;
        }
    }
}
// 3. Prim's Algorithm Logic
void findMST(Graph* g) {
	int i,count,v;
    int parent[N];   // Array to store constructed MST
    int key[N];      // Values used to pick minimum weight edge in cut
    int mstSet[N];   // To represent set of vertices included in MST
    // Initialize all keys as INFINITE
    for (i = 0; i < g->vertices; i++) {
        key[i] = INF;
        mstSet[i] = 0;
    }
    // Always include first 1st vertex in MST.
    key[0] = 0;
    parent[0] = -1; // First node is always root of MST
    for ( count = 0; count < g->vertices - 1; count++) {
        // Pick the minimum key vertex from the set of vertices not yet included
        int min = INF, u;
        for (v = 0; v < g->vertices; v++) 
            if (mstSet[v] == 0 && key[v] < min){
                min = key[v], u = v;
            }
        // Add the picked vertex to the MST Set
        mstSet[u] = 1;
        // Update key value and parent index of the adjacent vertices
        for (v = 0; v < g->vertices; v++) {
            if (g->adj[u][v] && mstSet[v] == 0 && g->adj[u][v] < key[v]) {
                parent[v] = u;
                key[v] = g->adj[u][v];
            }
        }
    }
    // 4. Display the MST
    printf("\nEdge \tWeight\n");
    int totalCost = 0;
    for (i = 1; i < g->vertices; i++) {
        printf("%d - %d \t%d \n", parent[i], i, g->adj[i][parent[i]]);
        totalCost += g->adj[i][parent[i]];
    }
    printf("\nTotal Cost of MST: %d\n", totalCost);
}
int main() {
    Graph g;
    int v, e, src, dest, weight,i;
    char ch;
    do {
        printf("Enter number of vertices (max %d): ", N);
        if (!scanf("%d", &v)) break;
        initGraph(&g, v);
        printf("Enter number of edges: ");
        scanf("%d", &e);
        for (i = 0; i < e; i++) {
            printf("Enter edge %d (source destination weight): ", i + 1);
            scanf("%d %d %d", &src, &dest, &weight);
            if (src < v && dest < v) {
                g.adj[src][dest] = weight;
                g.adj[dest][src] = weight; // For undirected graph
            }
        }
        findMST(&g);
        printf("\nEnter 'Y' for new session: ");
        scanf(" %c", &ch);
    } while (ch == 'y' || ch == 'Y');
    return 0;
}
