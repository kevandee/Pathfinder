#include "../inc/pathfinder.h"

int **to_matrix(t_bridge **bridges, char **islands, int count_islands) {
    int **temp_matrix = (int **)malloc(count_islands * sizeof(int *));
    for (int i = 0; i < count_islands; i++) {
        temp_matrix[i] = (int *)malloc(count_islands * sizeof(int));
    }

    for (int i = 0; i < count_islands; i++) {
        for (int j = 0; j < count_islands; j++) {
            temp_matrix[i][j] = 0;
        }
    }
    int count_bridges = 0;
    t_bridge **first = bridges;
    while (*bridges) {
        int first_ind = 0;
        int sec_ind = 0;
        for (int i = 0; i < count_islands; i++) {
            if (mx_strcmp((*bridges)->start, islands[i]) == 0) {
                first_ind = i;
            }
            if (mx_strcmp((*bridges)->end, islands[i]) == 0) {
                sec_ind = i;
            }
        }

        temp_matrix[first_ind][sec_ind] = (*bridges) -> length;
        temp_matrix[sec_ind][first_ind] = (*bridges) -> length;

        bridges++;
        count_bridges++;
    }
    bridges = first;

    return temp_matrix;
}
