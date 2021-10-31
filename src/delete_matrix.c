#include "../inc/pathfinder.h"

void delete_matrix(int **matrix, int size) {
    for (int i = 0; i < size; i++) {
        free(matrix[i]);
        matrix[i]=NULL;
    }
    free(matrix);
    matrix = NULL;

}
