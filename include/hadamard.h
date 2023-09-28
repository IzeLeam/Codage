#ifndef HADAMARD_H
#define HADAMARD_H

#define MAX_USERS 16

void generate_hadamard(int longueur, int** hadamard);

typedef struct Hadamard {
    int** matrix;
    int size;
    int users;
    char* messages[MAX_USERS];
} Hadamard;

#endif