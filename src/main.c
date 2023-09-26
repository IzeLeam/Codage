#include <stdio.h>
#include <stdlib.h>

#include "../include/hadamard.h"
#include "../include/matrix.h"
#include "../include/utils.h"
#include "../include/list.h"

int main() {
    int** hadamard = create_squared_matrix(64);
    generate_hadamard(64, hadamard);
    print_squared_matrix(64, hadamard);

    return 0;
}