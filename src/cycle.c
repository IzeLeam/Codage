#include <stdio.h>
#include <stdlib.h>

#include "../include/includes.h"

int** 

void test2(int l, int* nums, int num_size) {
    int lm = to_base_2(l) - 1;
    int sequence[lm];
    int code[l];

    for (int i = 0; i < l; i++) {
        code[i] = 1;
    }

    int xor;
    for (int i = 0; i < lm; i++) {
        sequence[i] = code[l-1];
        xor = code[l-1];
        for (int j = 0; j < num_size; j++) {
            xor ^= code[nums[j]-1];
        }
        for (int j = l-1; j > 0; j--) {
            code[j] = code[j-1];
        }
        code[0] = xor;
    }

    printf("Résultat : \n");
    for (int i = 0; i < lm; i++) {
        printf("%d ", sequence[i]);
    }
}

void process_cycle() {
    int select;
    int nums[2] = {2};
    while (select = process_menu(cycle_menu)) {
        switch(select) {
            case 1 :
                test2(5, nums, 1);
            default:
                break;

        }
    }
}