#ifndef MATRIX_H
#define MATRIX_H

int** create_squared_matrix(int size);

int** create_matrix(int height, int width);

void print_squared_matrix(int size, int** matrix);

void print_matrix(int height, int width, int** matrix);

void free_squared_matrix(int size, int** matrix);

void free_matrix(int width, int** matrix);

#endif