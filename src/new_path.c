#include "../inc/pathfinder.h"

void new_path(t_path **path, char *name) {
    *path = (t_path *)malloc(sizeof(t_path));
    (*path) -> path = NULL;
    (*path) -> start = name;
    (*path) -> is_start = false;
    (*path) -> weight = 0;
    (*path) -> count_isl = 0;
}
