#ifndef MENU_H
#define MENU_H

#define MAX_MENU_SIZE 10

typedef struct Menu {
    char* title;
    int size;
    char* select[MAX_MENU_SIZE];
} Menu;

extern Menu main_menu;
extern Menu hadamard_menu;

#endif