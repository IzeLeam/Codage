#include <stdio.h>
#include <stdlib.h>

#include "../include/includes.h"

void test() {
    printf("%d", -8/8);
}

int main() {
    int select;
    while (select = process_menu(main_menu)) {
        switch(select) {
            case 1 :
                process_hadamard();
                break;
            case 2 : 
                process_hdb();
            default:
                test();
        }
    }

    return 0;
}