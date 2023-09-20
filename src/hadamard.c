#include <stdio.h>
#include <stdlib.h>

#include "../include/utils.h"
#include "../include/hadamard.h"

void generate_hadamard(int size, int** hadamard) {
    int longueur = base2(size);
    
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            hadamard[i][j] = 1;
        }
    }
}

void print_hadamard(int size, int** hadamard) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%2d", hadamard[i][j]);
        }
        printf("\n");
    }
}