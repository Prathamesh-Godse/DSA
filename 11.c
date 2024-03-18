#include <stdio.h>

const int MAX = 100;
const int SIZE = 10;

typedef struct {
    int iaItems[10];
    int iFront;
    int iRear;
} QUEUE;

void fnBreadthFirstSearchReach(int vertex, int g[MAX][MAX], int v[MAX], int n);
void fnDepthFirstSearch(int currentVertex, int v[MAX], int g[MAX][MAX], int n);
void fnQInsert(QUEUE *stQueue, int elem);
int fnQDelete(QUEUE *stQueue);
int fnQFull(QUEUE *stQueue);
int fnQEmpty(QUEUE *stQueue);

int main(void) {
    int graph[MAX][MAX];
    int visited[MAX];
    int numVert, startVert, i, j;

    printf("Enter the number of vertices: ");
    scanf("%d", &numVert);
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < numVert; i++)
        visited[i] = 0;
    for (i = 0; i < numVert; i++)
        for (j = 0; j < numVert; j++)
            scanf("%d", &graph[i][j]);
    
    printf("Enter the starting vertex: ");
    scanf("%d", &startVert);
    fnBreadthFirstSearchReach(startVert - 1, graph, visited, numVert);
    printf("Vertices which can be reached from vertex %d are:\n", startVert);
    for (i = 0; i < numVert; i++)
        if (visited[i])
            printf("%d ", i + 1);
    printf("\n");

    for (i = 0; i < numVert; i++)
        visited[i] = 0;

    printf("\nEnter the source vertex for DFS: ");
    scanf("%d", &startVert);
    fnDepthFirstSearch(startVert, visited, graph, numVert);
    printf("Vertices reachable from vertex %d using DFS:\n", startVert);
    for (i = 0; i < numVert; i++) {
        if (visited[i])
            printf("%d ", i + 1);
    }
    printf("\n");

    return 0;
}

void fnBreadthFirstSearchReach(int vertex, int g[MAX][MAX], int v[MAX], int n) {
    QUEUE stQueue;
    stQueue.iFront = 0;
    stQueue.iRear = -1;
    int frontVertex, i;
    v[vertex] = 1;
    fnQInsert(&stQueue, vertex);
    while (!fnQEmpty(&stQueue)) {
        frontVertex = fnQDelete(&stQueue);
        for (i = 0; i < n; i++) {
            if (g[frontVertex][i] && !v[i]) {
                v[i] = 1;
                fnQInsert(&stQueue, i);
            }
        }
    }
}

void fnDepthFirstSearch(int currentVertex, int v[MAX], int g[MAX][MAX], int n) {
    int i;
    v[currentVertex - 1] = 1; // Adjusted indexing
    for (i = 0; i < n; i++) {
        if (g[currentVertex - 1][i] && !v[i])
            fnDepthFirstSearch(i + 1, v, g, n); // Adjusted indexing
    }
}

void fnQInsert(QUEUE *stQueue, int iItem) {
    if (fnQFull(stQueue))
        printf("\nQueue Overflow\n");
    else {
        stQueue->iRear++;
        stQueue->iaItems[stQueue->iRear] = iItem;
    }
}

int fnQDelete(QUEUE *stQueue) {
    int item;
    if (fnQEmpty(stQueue))
        printf("\nQueue Underflow\n");
    else if (stQueue->iRear == stQueue->iFront) {
        item = stQueue->iaItems[stQueue->iFront];
        stQueue->iRear = -1;
        stQueue->iFront = 0;
    } else {
        item = stQueue->iaItems[stQueue->iFront++];
    }
    return item;
}

int fnQFull(QUEUE *stQueue) {
    if (stQueue->iRear == SIZE - 1)
        return 1;
    else
        return 0;
}

int fnQEmpty(QUEUE *stQueue) {
    if (stQueue->iRear == stQueue->iFront - 1)
        return 1;
    else
        return 0;
}
