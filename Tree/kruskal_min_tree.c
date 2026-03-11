#include <stdio.h>
#include <stdlib.h>
#define MAX_EDGES 100
#define MAX_VERTICES 20
// 1. Structure to represent an edge
typedef struct {
    int u, v, weight;
} Edge;
// 2. Disjoint Set Union (DSU) Structure to detect cycles
typedef struct {
    int parent[MAX_VERTICES];
} DSU;
void initDSU(DSU *s, int n) {
	int i;
    for (i = 0; i < n; i++)
        s->parent[i] = i;
}
// Find the root of the set (with path compression)
int find(DSU *s, int i) {
    if (s->parent[i] == i)
        return i;
    return s->parent[i] = find(s, s->parent[i]);
}
// Union of two sets
void unionSets(DSU *s, int root1, int root2) {
    s->parent[root1] = root2;
}
// 3. Comparison function for sorting edges (qsort)
int compareEdges(const void *a, const void *b) {
    return ((Edge*)a)->weight - ((Edge*)b)->weight;
}
int main() {
    int V, E,i;
    Edge edges[MAX_EDGES];
    DSU s;
    char ch;
    do {
        printf("Enter number of vertices and edges: ");
        scanf("%d %d", &V, &E);
        for (i = 0; i < E; i++) {
            printf("Edge %d (src dest weight): ", i + 1);
            scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
        }
        // Step 1: Sort edges by weight
        qsort(edges, E, sizeof(Edge), compareEdges);
        initDSU(&s, V);
        printf("\nEdges in the Minimum Spanning Tree:\n");
        int mst_weight = 0;
        int count = 0;
        for (i = 0; i < E && count < V - 1; i++) {
            int rootU = find(&s, edges[i].u);
            int rootV = find(&s, edges[i].v);
            // Step 2 & 3: If roots are different, no cycle is formed
            if (rootU != rootV) {
                printf("%d -- %d == %d\n", edges[i].u, edges[i].v, edges[i].weight);
                mst_weight += edges[i].weight;
                unionSets(&s, rootU, rootV);
                count++;
            }
        }
        printf("Total Weight of MST: %d\n", mst_weight);
        printf("\nEnter 'Y' for new session: ");
        scanf(" %c", &ch);
    } while (ch == 'y' || ch == 'Y');
    return 0;
}
