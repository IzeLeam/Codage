#include <stdio.h>
#include <stdlib.h>

#include "../include/menu.h"

Menu main_menu = {"Principal" ,2 , {"Hadamard", "Test"}};
Menu hadamard_menu = {"Hadamard" ,5 , {"Initialiser", "Afficher Matrice", "Envoyer un message", "Lire un message", "Afficher étalement"}};

void print_menu(Menu menu) {
    printf("\nMenu %s :\n", menu.title);
    for (int i = 0; i < menu.size; i++) {
        printf(" %d. %s\n", i+1, menu.select[i]);
    }
    printf(" 0. Quitter\n");
    printf("Selection : ");
}

int process_menu(Menu menu) {
    int select = -1;
    while (select < 0 || select > menu.size) {
        print_menu(menu);
        scanf("%d", &select);
    }
    system("clear");
    return select;
}