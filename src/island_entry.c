#include "../inc/pathfinder.h"

bool islands_entry(char **islands, int count_islands, char *new_island) {
    for (int i = 0; i < count_islands; i++) {
        if (mx_strcmp(islands[i], new_island) == 0) {
            return true;
        }
    }

    return false;
}
