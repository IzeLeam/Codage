#include <stdio.h>
#include <stdlib.h>

int to_base_2(int x) {
    int result = 1;
    for (int i = 0; i < x; i++) {
        result *= 2;
    }
    return result;  
}

int from_base_2(int x) {
    int result = 0;
    for (int i = x; i > 1; i /= 2) {
        result++;
    }
    return result;  
}

int next_base_2(int num) {
    if (num <= 1)
        return 1;

    int result = 1;
    while (result < num) {
        result <<= 1;
    }
    
    return result;
}