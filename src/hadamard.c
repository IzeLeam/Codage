#include <stdio.h>
#include <stdlib.h>

#include "../include/utils.h"
#include "../include/hadamard.h"
#include "../include/matrix.h"

int** get_baby_hadamard(int size, int** hadamard);

void generate_hadamard(int size, int** hadamard) {
    int iterative = from_base_2(size);
    hadamard[0][0] = 1;
    
    for (int i = 0; i < iterative; i++) {
        int length = to_base_2(i);
        int** baby = get_baby_hadamard(length, hadamard);

        for (int k = 0; k < length; k++) {
            for (int l = 0; l < length; l++) {
                hadamard[k+length][l] = baby[k][l];
            }
        }

        for (int k = 0; k < length; k++) {
            for (int l = 0; l < length; l++) {
                hadamard[k][l+length] = baby[k][l];
            }
        }

        for (int k = 0; k < length; k++) {
            for (int l = 0; l < length; l++) {
                hadamard[k+length][l+length] = -baby[k][l];
            }
        }
        free_squared_matrix(length, baby);
    }
}

int** get_baby_hadamard(int size, int** hadamard) {
    int** baby = create_squared_matrix(size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            baby[i][j] = hadamard[i][j];
        }
    }
    return baby;
}