#ifndef HADAMARD_H
#define HADAMARD_H

#define MAX_USERS 16
#define MAX_MESSAGE_LEN 16

typedef struct Hadamard {
    int** matrix;
    int size;
    int users;
    int etalement[MAX_MESSAGE_LEN*32];
} Hadamard;

#endif