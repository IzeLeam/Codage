#include <stdio.h>
#include <stdlib.h>

#include "../include/hadamard.h"
#include "../include/utils.h"

int main() {
    int** hadamard;

    generate_hadamard(3, hadamard);
    //print_hadamard(8, hadamard);

    return 0;
}