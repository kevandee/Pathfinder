#include "../inc/pathfinder.h"

int island_to_index(char **islands, int count_islands, char *name) {
    for (int i = 0; i < count_islands; i ++) {
        if (mx_strcmp(islands[i], name) == 0) {
            return i;
        }
    }

    return -1;
}
