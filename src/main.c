#include <stdio.h>
#include <stdlib.h>

#include "../include/hadamard.h"
#include "../include/matrix.h"

int main() {
    int** hadamard = create_squared_matrix(8);
    generate_hadamard(8, hadamard);
    print_hadamard(8, hadamard);

    return 0;
}