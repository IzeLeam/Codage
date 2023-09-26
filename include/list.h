#ifndef LIST_H
#define LIST_H

// Définition de la structure de la liste

typedef struct Node {
    void* data;
    struct Node* next;
} Node;

typedef struct List {
    Node* start;
    void free();
    void add();
    int get();
    void removeByIndex();
    void print();
} List;

// Définition du type de fonction d'affichage des éléments
typedef void (*PrintFunc)(void *);

// Prototypes des fonctions
List *createList(int capacity);
void freeList(List *list, PrintFunc freeItemFunc);
void addItem(List *list, void *item);
void removeItem(List *list, int index, PrintFunc freeItemFunc);
void *getItem(List *list, int index);
void printList(List *list, PrintFunc printItemFunc);

#endif
