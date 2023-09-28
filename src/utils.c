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

int nb_digits(int x) {
    int result = 0;
    for (int i = 1; i <= x; i*=10) {
        if (x/i < 1) result++;
    }
    return result;
}

int pow(int x, int p) {
    int result = 1;
    for (int i = 0; i < p; i++) {
        result *= x;
    }
    return result;
}

int* int_to_tab(int x) {
    int digits = nb_digits(x);
    int tab[digits];
    for (int i = 0; i < digits; i++) {
        tab[i] = x / pow(i, 10);
    }
    return tab;
}

int char_to_int(char c) {
    if (c == '1') return 1;
    return 0;
}
