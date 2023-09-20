#include <stdio.h>
#include <stdlib.h>

int base2(int x) {
    int result = 1;
    for (int i = 0; i < x; i++) {
        result *= 2;
    }
    return result;
}