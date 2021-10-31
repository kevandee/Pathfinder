#include "../inc/pathfinder.h"

void new_path_from_list(t_path** path, char *name, t_list* old_path) {
    new_path(path, name);
    old_path = old_path->next;
    while (old_path) {
        mx_push_back(&((*path)->path), old_path ->data);
        old_path = old_path->next;
    }
}
