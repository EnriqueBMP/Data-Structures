#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows, cols;

    printf("Introduce el número de filas: ");
    scanf("%d", &rows);

    printf("Introduce el número de columnas: ");
    scanf("%d", &cols);

    int **matriz1 = (int **)malloc(rows * sizeof(int *));
    if (matriz1 == NULL) {
        printf("Error: No se pudo asignar memoria para las filas de la primera matriz.\n");
        return 1;
    }

    for (int i = 0; i < rows; i++) {
        *(matriz1 + i) = (int *)malloc(cols * sizeof(int));
        if (*(matriz1 + i) == NULL) {
            printf("Error: No se pudo asignar memoria para la fila %d de la primera matriz.\n", i);
            return 1;
        }
    }

    int **matriz2 = (int **)malloc(rows * sizeof(int *));
    if (matriz2 == NULL) {
        printf("Error: No se pudo asignar memoria para las filas de la segunda matriz.\n");
        return 1;
    }

    for (int i = 0; i < rows; i++) {
        *(matriz2 + i) = (int *)malloc(cols * sizeof(int));
        if (*(matriz2 + i) == NULL) {
            printf("Error: No se pudo asignar memoria para la fila %d de la segunda matriz.\n", i);
            return 1;
        }
    }

    int **matriz3 = (int **)malloc(rows * sizeof(int *));
    if (matriz3 == NULL) {
        printf("Error: No se pudo asignar memoria para las filas de la matriz resultado.\n");
        return 1;
    }

    for (int i = 0; i < rows; i++) {
        *(matriz3 + i) = (int *)malloc(cols * sizeof(int));
        if (*(matriz3 + i) == NULL) {
            printf("Error: No se pudo asignar memoria para la fila %d de la matriz resultado.\n", i);
            return 1;
        }
    }

    printf("\nIntroduce los elementos de la matriz A:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", (*(matriz1 + i) + j));
        }
    }

    printf("\nIntroduce los elementos de la matriz B:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", (*(matriz2 + i) + j));
        }
    }

    printf("\nMatriz A:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", *(*(matriz1 + i) + j));
        }
        printf("\n");
    }

    printf("\nMatriz B:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", *(*(matriz2 + i) + j));
        }
        printf("\n");
    }

    printf("Suma de matrices A y B\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            *(*(matriz3 + i) + j) = *(*(matriz1 + i) + j) + *(*(matriz2 + i) + j);
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d \t", *(*(matriz3 + i) + j));
        }
        printf("\n");
    }

    for (int i = 0; i < rows; i++) {
        free(*(matriz1 + i));
        free(*(matriz2 + i));
        free(*(matriz3 + i));
    }

    free(matriz1);
    free(matriz2);
    free(matriz3);

    return 0;
}
