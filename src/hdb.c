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

int different_letters(char* data) {
    int size = strlen(data);
    int alpha[26];
    int letters = 0;
    for (int i = 0; i < size; i++) {
        if (alpha[data[i] - 'a'] == 0) {
            alpha[data[i] - 'a'] = 1;
            letters++;
        }
    }
    return letters;
}

float* probabilities(char* data) {
    int size = strlen(data);
    int letters = different_letters(data);
    float probs[26];
    float finalprobs[letters];

    for (int i = 0; i < 26; i++) {
        probs[i] = 0.0;
    }

    for (int i = 0; i < size; i++) {
        probs[data[i] - 'a']++;
    }

    int j = 0;
    for (int i = 0; i < 26; i++) {
        if (probs[i] == 0) continue;
        finalprobs[j++] = (i == 0 ? 0 : probs[i - 1]) + probs[i] / size;
    }

    for (int i = 0; i < letters; i++) {
        printf("%f\n", finalprobs[i]);
    }
    return finalprobs;
}

float arithmetique(char* data) {
    float* probs = probabilities(data);
    int letters = different_letters(data);

    for (int i = 0; strlen(data); i++) {
        
    }

    return 0.0;
}

void process_hdb() {
    int select;
    char data[] = "coucou";
    while (select = process_menu(hdb_menu)) {
        switch(select) {
            case 1 :
                printf("%f", arithmetique(data));
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