#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define N 20
#define INF 999999

// 1. Graph Structure
typedef struct {
    int vertices;
    int adj[N][N];
} Graph;

void initGraph(Graph* g, int v) {
	int i,j;
    g->vertices = v;
    for (i = 0; i < v; i++) {
        for (j = 0; j < v; j++) {
            g->adj[i][j] = (i == j) ? 0 : INF;
        }
    }
}

// 2. Dijkstra's Logic
void dijkstra(Graph* g, int startNode) {
	int i,count;
    int dist[N];     // Shortest distance from source to i
    int visited[N];  // visited[i] will be true if vertex i is finalized

    // Initialize all distances as INFINITE and visited[] as false
    for (i = 0; i < g->vertices; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    // Distance of source vertex from itself is always 0
    dist[startNode] = 0;

    for (count = 0; count < g->vertices - 1; count++) {
    	int v,i;
        // Pick the minimum distance vertex from the set of vertices not yet processed
        int min = INF, u;

        for (v = 0; v < g->vertices; v++) {
            if (!visited[v] && dist[v] <= min) {
                min = dist[v], u = v;
            }
        }

        // Mark the picked vertex as processed
        visited[u] = 1;

        // Update dist value of the adjacent vertices of the picked vertex
        for (v = 0; v < g->vertices; v++) {
            /* Update dist[v] only if:
               1. It's not visited
               2. There is an edge from u to v
               3. Total weight of path from source to v through u is smaller than current dist[v]
            */
            if (!visited[v] && g->adj[u][v] != INF && dist[u] != INF 
                && dist[u] + g->adj[u][v] < dist[v]) {
                dist[v] = dist[u] + g->adj[u][v];
            }
        }
    }

    // 3. Display the shortest distances
    printf("\nVertex \t Distance from Source (%d)\n", startNode);
    for (i = 0; i < g->vertices; i++) {
        if (dist[i] == INF) printf("%d \t INF\n", i);
        else printf("%d \t %d\n", i, dist[i]);
    }
}

int main() {
    Graph g;
    int v,i, e, src, dest, weight, startNode;
    char ch;

    do {
        printf("Enter number of vertices: ");
        scanf("%d", &v);
        initGraph(&g, v);

        printf("Enter number of edges: ");
        scanf("%d", &e);

        for (i = 0; i < e; i++) {
            printf("Edge %d (src dest weight): ", i + 1);
            scanf("%d %d %d", &src, &dest, &weight);
            if (src < v && dest < v) {
                g.adj[src][dest] = weight; // Directed graph logic
                // g.adj[dest][src] = weight; // Uncomment for Undirected
            }
        }

        printf("Enter the starting node for Dijkstra: ");
        scanf("%d", &startNode);

        dijkstra(&g, startNode);

        printf("\nEnter 'Y' for new session: ");
        scanf(" %c", &ch);
    } while (ch == 'y' || ch == 'Y');

    return 0;
}
