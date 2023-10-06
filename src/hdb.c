#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/includes.h"

void HDBn(int n, int* data, int* P, int* N) {
    if (n == 5) {
        printf("Sélection HDBn pour n = ");
        scanf("%d", &n);
    }

    for (int i = 0; i < 23; i++) {
        P[i] = 0;
        N[i] = 0;
    }

    int zeros = 0;
    int last_viol = -1;
    int last_one = -1;
    for (int i = 0; i < 23; i++) {
        if (data[i] == 1) {
            if (last_one == -1) {
                P[i] = 1;
            } else {
                N[i] = 1;
            }
            last_one = -last_one;
            zeros = 0;
        } else {
            if (zeros == n) {
                if (last_viol == -1) {
                    P[i] = 1;
                    if (last_one == -1) {
                        P[i - n] = 1;
                        last_one = 1;
                    }
                } else {
                    N[i] = 1;
                    if (last_one == 1) {
                        N[i - n] = 1;
                        last_one = -1;
                    }
                }
                last_viol = -last_viol;
                zeros = 0;
            } else {
                zeros++;
            }
        }
    }
}

void print_polarite(int* P, int* N) {
    printf("Resultat : \n");
    printf("P | ");
    for (int i = 0; i < 23; i++) {
        printf("%d ", P[i]);
    }
    printf("\nN | ");
    for (int i = 0; i < 23; i++) {
        printf("%d ", N[i]);
    }
}

void process_hdb() {
    int select;
    int P[23];
    int N[23];
    int data[] = {1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0};
    while (select = process_menu(hdb_menu)) {
        switch(select) {
            case 1 :
                printf("%f", arithmetique("coucou"));
                break;
            case 2 :
            case 3 :
            case 4 :
            case 5 :
                HDBn(select, data, P, N);
                print_polarite(P, N);
                break;
            default:
                break;

        }
    }
}