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

void* create_list(int size, size_t type) {
    void* list = malloc(type * size);
    return list;
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

void print_matrix(int height, int width, int** matrix) {
    for (int i = 0; i < width; i++) {
        printf("|");
        for (int j = 0; j < height; j++) {
            printf("%2d", matrix[i][j]);
        }
        printf(" |\n");
    }
}

void free_squared_matrix(int size, int** matrix) {
    for (int i = 0; i < size; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void free_matrix(int width, int** matrix) {
    for (int i = 0; i < width; i++) {
        free(matrix[i]);
    }
    free(matrix);
}