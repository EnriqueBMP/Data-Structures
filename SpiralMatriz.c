#include <stdio.h>

int main(){
    int m=4;
    int n=5;
    int matriz[4][5];
    int contador=0;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            contador++;
            matriz[i][j] = contador;
        }
    }
    int top = 0;
    int bottom = m - 1;
    int left = 0;
    int right = n - 1;

    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++) {
            printf("%d ", matriz[top][i]);
        }
        top++;
        for (int i = top; i <= bottom; i++) {
            printf("%d ", matriz[i][right]);
        }
        right--;

        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                printf("%d ", matriz[bottom][i]);
            }
            bottom--;
        }
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                printf("%d ", matriz[i][left]);
            }
            left++;
        }
    }
    printf("\n"); 
    return 0;     
}