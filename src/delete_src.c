#include "../inc/pathfinder.h"

void delete_src(char **file, char ***islands, t_bridge ***bridges, int count_bridges, int count_islands) {
    for (int i = 0; i < count_bridges; i++) {
        free((*bridges)[i]->start);
        free((*bridges)[i]->end);
        if(malloc_size((*bridges)[i]))
            free((*bridges)[i]);
    }
    free(*bridges);
    for (int i = 0; i < count_islands; i++) {
        mx_strdel(&(*islands)[i]);
    }
    free(*islands);
    free(*file);
}
