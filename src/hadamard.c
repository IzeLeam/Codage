#include <stdio.h>
#include <stdlib.h>

#include "../include/utils.h"
#include "../include/hadamard.h"
#include "../include/matrix.h"
#include "../include/menu.h"

Hadamard* hadamard = NULL;

void init_hadamard() {
    if (hadamard == NULL) {
        hadamard = malloc(sizeof(Hadamard));
    }
    int users = 0;
    while (users < 1 || users > MAX_USERS) {
        printf("Combien d'utilisateurs (max = %d): ", MAX_USERS);
        scanf("%d", &users);
    }
    hadamard->users = users;
    hadamard->size = next_base_2(users) * 2;
    hadamard->matrix = create_squared_matrix(hadamard->size);
    for (int i = 0; i < MAX_MESSAGE_LEN*32; i++) {
        hadamard->etalement[i] = 0;
    }
    generate_hadamard();
}

int get_user_canal(int user) {
    return user * 2;
}

int ask_user() {
    int user = 0;
    while(user < 1 || user > hadamard->users) {
    printf("Selection de l'utilisateur : ");
    scanf("%d", &user);
    }
    return user;
}

void print_etalement() {
    for (int i = 0; i < MAX_MESSAGE_LEN*32; i++) {
        printf("%d ", hadamard->etalement[i]);
    }
}

void sendMessage() {
    int user = ask_user();
    user--;
    char message[MAX_MESSAGE_LEN];
    printf("Message à envoyer : ");
    scanf("%s", message);
    int index = 0;
    for (int i = 0; message[i] && i < MAX_MESSAGE_LEN; i++) {
        for (int j = 0; j < hadamard->size; j++) {
            hadamard->etalement[index] += (hadamard->matrix[user][j] * (char_to_int(message[i]) == 0 ? -1 : 1));
            index++;
        }
    }
}

void getMessage() {
    int user = ask_user();
    printf("Message de l'utilisateur %d : \n", user);
    user--;
    int index = 0;
    for (int i = 0; i < MAX_MESSAGE_LEN*32; i++) {
        int sum = 0;
        for (int j = 0; j < hadamard->size; j++) {
            sum += hadamard->etalement[index] * hadamard->matrix[user][j];
            index++;
        }
        int bit = (int)sum/hadamard->size;
        if (bit == 0) return;
        printf("%d ", (bit == -1 ? 0 : bit));
    }
    printf("\n");
}

void process_hadamard() {
    int select;
    while (select = process_menu(hadamard_menu)) {
        switch (select) {
        case 1:
            init_hadamard();
            break;
        case 2:
            if (hadamard == NULL) {
                printf("Veuillez d'abord initialiser Hadamard\n");
                break;
            }
            print_squared_matrix(hadamard->size, hadamard->matrix);
            break;
        case 3: 
            if (hadamard == NULL) {
                printf("Veuillez d'abord initialiser Hadamard\n");
                break;
            }
            sendMessage();
            break;
        case 4:
            if (hadamard == NULL) {
                printf("Veuillez d'abord initialiser Hadamard\n");
                break;
            }
            getMessage();
            break;
        case 5:
            if (hadamard == NULL) {
                printf("Veuillez d'abord initialiser Hadamard\n");
                break;
            }
            print_etalement();
            break;
        default:
            break;
        }
    }
}

int** get_baby_hadamard(int size) {
    int** baby = create_squared_matrix(size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            baby[i][j] = hadamard->matrix[i][j];
        }
    }
    return baby;
}

void generate_hadamard() {
    int iterative = from_base_2(hadamard->size);
    hadamard->matrix[0][0] = 1;
    
    for (int i = 0; i < iterative; i++) {
        int length = to_base_2(i);
        int** baby = get_baby_hadamard(length);

        for (int k = 0; k < length; k++) {
            for (int l = 0; l < length; l++) {
                hadamard->matrix[k+length][l] = baby[k][l];
            }
        }

        for (int k = 0; k < length; k++) {
            for (int l = 0; l < length; l++) {
                hadamard->matrix[k][l+length] = baby[k][l];
            }
        }

        for (int k = 0; k < length; k++) {
            for (int l = 0; l < length; l++) {
                hadamard->matrix[k+length][l+length] = -baby[k][l];
            }
        }
        free_squared_matrix(length, baby);
    }
}