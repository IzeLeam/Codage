#include <stdio.h>
#include <stdlib.h>

#include "../include/hadamard.h"
#include "../include/matrix.h"
#include "../include/utils.h"

int main() {
    int** hadamard = create_squared_matrix(8);
    generate_hadamard(8, hadamard);
    print_squared_matrix(8, hadamard);

    //printf("%d, %d\n", to_base_2(0), from_base_2(2));

    return 0;
}