#include <stdio.h>

#define V 4

int main() {
    int adjMatrix[V][V] = {0};

    adjMatrix[0][1] = adjMatrix[1][0] = 1; // A-B
    adjMatrix[0][2] = adjMatrix[2][0] = 1; // A-C
    adjMatrix[1][3] = adjMatrix[3][1] = 1; // B-D

    printf("Adjacency Matrix (Undirected Graph):\n");
    printf("    A B C D\n");
    for (int i = 0; i < V; i++) {
        printf("%c | ", 'A' + i);
        for (int j = 0; j < V; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
