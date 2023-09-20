#include <stdio.h>
#include <stdlib.h>

int** create_squared_matrix(int size) {
    int** M = malloc(size * sizeof *M);
    for (int i = 0; i < size; i++) {
        M[i] = malloc(size * sizeof *(M[i]));
    }
    return M;
}

int** create_matrix(int height, int width) {
    int** M = malloc(width * sizeof *M);
    for (int i = 0; i < width; i++) {
        M[i] = malloc(height * sizeof *(M[i]));
    }
    return M;
}

void print_squared_matrix(int size, int** matrix) {
    for (int i = 0; i < size; i++) {
        printf("|");
        for (int j = 0; j < size; j++) {
            printf("%2d", matrix[i][j]);
        }
        printf(" |\n");
    }
}