#include <stdio.h>
#include <stdlib.h>

#include "../include/list.h"

List *createList(int capacity) {
    List *list = (List *)malloc(sizeof(List));
    if (list == NULL) {
        perror("Erreur lors de l'allocation de mémoire pour la liste.");
        exit(EXIT_FAILURE);
    }

    list->capacity = capacity;
    list->size = 0;
    list->items = (void **)malloc(capacity * sizeof(void *));
    if (list->items == NULL) {
        perror("Erreur lors de l'allocation de mémoire pour les éléments de la liste.");
        exit(EXIT_FAILURE);
    }

    return list;
}

void freeList(List *list, PrintFunc freeItemFunc) {
    for (int i = 0; i < list->size; i++) {
        if (freeItemFunc != NULL) {
            freeItemFunc(list->items[i]);
        }
    }

    free(list->items);
    free(list);
}

void addItem(List *list, void *item) {
    if (list->size >= list->capacity) {
        // Redimensionnement de la liste si nécessaire
        list->capacity *= 2;
        list->items = (void **)realloc(list->items, list->capacity * sizeof(void *));
        if (list->items == NULL) {
            perror("Erreur lors du redimensionnement de la liste.");
            exit(EXIT_FAILURE);
        }
    }

    list->items[list->size] = item;
    list->size++;
}

void removeItem(List *list, int index, PrintFunc freeItemFunc) {
    if (index < 0 || index >= list->size) {
        fprintf(stderr, "Indice invalide pour la suppression.\n");
        return;
    }

    if (freeItemFunc != NULL) {
        freeItemFunc(list->items[index]);
    }

    for (int i = index; i < list->size - 1; i++) {
        list->items[i] = list->items[i + 1];
    }

    list->size--;
}

void *getItem(List *list, int index) {
    if (index < 0 || index >= list->size) {
        fprintf(stderr, "Indice invalide pour l'accès à l'élément.\n");
        return NULL;
    }

    return list->items[index];
}

void printList(List *list, PrintFunc printItemFunc) {
    for (int i = 0; i < list->size; i++) {
        if (printItemFunc != NULL) {
            printItemFunc(list->items[i]);
        }
    }
}
