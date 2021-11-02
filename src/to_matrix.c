#include "../inc/pathfinder.h"

int **to_matrix(t_bridge **bridges, char **islands, int count_islands, int count_bridges) {
    int **temp_matrix = (int **)malloc(count_islands * sizeof(int *));
    for (int i = 0; i < count_islands; i++) {
        temp_matrix[i] = (int *)malloc(count_islands * sizeof(int));
    }

    for (int i = 0; i < count_islands; i++) {
        for (int j = 0; j < count_islands; j++) {
            temp_matrix[i][j] = 0;
        }
    }

    for(int i = 0; i < count_bridges; i++) {
        int first_ind = 0;
        int sec_ind = 0;
        for (int j = 0; j < count_islands; j++) {
            if (mx_strcmp((bridges[i])->start, islands[j]) == 0) {
                first_ind = j;
            }
            if (mx_strcmp((bridges[i])->end, islands[j]) == 0) {
                sec_ind = j;
            }
        }

        temp_matrix[first_ind][sec_ind] = (bridges[i]) -> length;
        temp_matrix[sec_ind][first_ind] = (bridges[i]) -> length;
    }

    return temp_matrix;
}
