#include <stdio.h>
#include <stdbool.h>
#define MAX 20
#define INF 9999
int minDistance(int dist[], bool visited[], int V) {
    int min = INF, min_index,v;
    for (v = 0; v < V; v++) {
        if (visited[v] == false && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}
void dijkstra(int graph[MAX][MAX], int V, int src) {
    int dist[MAX],i,count,v;
    bool visited[MAX];
    for (i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = false;
    }
    dist[src] = 0;
    for (count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited, V);
        visited[u] = true;
        for (v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] != 0 && dist[u] != INF 
                && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    printf("\nVertex \t Distance from Source (%d)\n", src);
    for (i = 0; i < V; i++) {
        if (dist[i] == INF)
            printf("%d \t INF\n", i);
        else
            printf("%d \t %d\n", i, dist[i]);
    }
}
int main() {
    int graph[MAX][MAX];
    int V, E,i,j, u, v, w, startNode;
    printf("Enter number of vertices (max %d): ", MAX);
    scanf("%d", &V);
    // Initialize matrix with 0 (no edges)
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            graph[i][j] = 0;
    printf("Enter number of edges: ");
    scanf("%d", &E);
    for (i = 0; i < E; i++) {
        printf("Edge %d (src dest weight): ", i + 1);
        scanf("%d %d %d", &u, &v, &w);
        if (u < V && v < V) {
            graph[u][v] = w;
            graph[v][u] = w; // Remove this line if the graph is directed
        } else {
            printf("Invalid vertex! Try again.\n");
            i--;
        }
    }
    printf("\nEnter the starting node (0 to %d): ", V - 1);
    scanf("%d", &startNode);
    if (startNode < V) {
        dijkstra(graph, V, startNode);
    } else {
        printf("Invalid starting node.\n");
    }
    return 0;
}
