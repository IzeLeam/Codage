#include <stdio.h>
#include <stdlib.h>

void init(int longueur, int** hadamard) {
    hadamard = (int**)malloc(longueur * sizeof(int*));
    for (int i = 0; i < longueur; i++) {
        *(hadamard+i)=(int*)malloc(longueur * sizeof(int));
    }
}

void generate_hadamard(int iterative, int** hadamard) {
    int longueur = base2(iterative);
    init(longueur, hadamard);
    
    for (int i = 0; i < longueur; i++) {
        for (int j = 0; j < longueur; j++) {
            //printf("%2d", *(*(hadamard+i)+j));
        }
    }
}

void print_hadamard(int longueur, int** hadamard) {
    for (int i = 0; i < longueur; i++) {
        for (int j = 0; j < longueur; j++) {
            printf("%2d", *(*(hadamard+i)+j));
        }
        printf("\n");
    }
}