#include <stdio.h>
#include <stdlib.h>
//#include <Windows.h>

#include "../include/includes.h"

Menu main_menu = {"Principal" ,4 , {"Hadamard", "HDB Encodage", "Code Cyclique", "Test"}};
Menu hadamard_menu = {"Hadamard" ,5 , {"Initialiser", "Afficher Matrice", "Envoyer un message", "Lire un message", "Afficher étalement"}};
Menu hdb_menu = {"HDB Encodage", 5, {"Arithmétique", "HDB2", "HDB3", "HDB4", "HDBn"}};
Menu cycle_menu = {"Codage Cyclique", 1, "Test"};

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
    //system("cls");
    return select;
}