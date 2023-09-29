#include <stdio.h>
#include <stdlib.h>

#include "../include/menu.h"

void process_hdb() {
    int select;
    while (select = process_menu(hdb_menu)) {
        switch(select) {
            case 1 :
                arithemtique();
            case 2 : 
            case 3 :
            case 4 :
            case 5 :
                if (select == 5) {
                    printf("Sélection HDBn pour n = ");
                    scanf("%d", &select);
                }
                printf("Sélection du code : ");
                scanf
                break;
            default:
                break;

        }
    }
}

void HDBn(int n, char* data, int* P, int* N) {
    if (n == 5) {
        printf("Sélection HDBn pour n = ");
        scanf("%d", &n);
    }


}

void arithemtique()