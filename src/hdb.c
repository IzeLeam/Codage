#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/includes.h"

void HDBn(int n, char* data, int* P, int* N) {
    if (n == 5) {
        printf("Sélection HDBn pour n = ");
        scanf("%d", &n);
    }


}

/*
int compare_chars(const void* a, const void* b) {
    return (*(char*)a - *(char*)b);
}

void sort(char* data) {
    size_t len = strlen(data);
    qsort(data, len, sizeof(char), compare_chars);
}

float arithmetique(char* data) {
    int size = strlen(data);
    int* probs = malloc(sizeof)
    for (int i = 0)
}
*/

void probabilities(char* data, float* probabilities) {
    int size = strlen(data);

    for (int i = 0; i < 26; i++) {
        probabilities[i] = 0.0;
    }

    for (int i = 0; i < size; i++) {
        probabilities[data[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        probabilities[i] /= size;
        printf("%.3f\n", probabilities[i]);
    }
}

float arithmetique(char* data, float* probabilities) {
    // Initialisation des bornes de l'intervalle [0, 1]
    float lower_bound = 0.0;
    float upper_bound = 1.0;
    float range = 1.0;

    // Parcours de la séquence de symboles
    int size = strlen(data);
    float result = 0;
    
    

    return result;
}

void process_hdb() {
    int select;
    while (select = process_menu(hdb_menu)) {
        switch(select) {
            case 1 :
                char data[] = "coucou";
                float prob[26];
                probabilities(data, prob);

                float code = arithmetique(data, prob);
                printf("%f", code);
                break;
            case 2 : 
            case 3 :
            case 4 :
            case 5 :
                break;
            default:
                break;

        }
    }
}