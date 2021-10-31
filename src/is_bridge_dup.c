#include "../inc/pathfinder.h"

bool is_bridge_dup(t_bridge **bridges, int i, int j) {
    return (mx_strcmp(bridges[i] -> start, bridges[j] -> start) == 0 
            && mx_strcmp(bridges[i] -> end, bridges[j] -> end) == 0) 
            || (mx_strcmp(bridges[i] -> start, bridges[j] -> end) == 0 
            && mx_strcmp(bridges[i] -> end, bridges[j] -> start) == 0);
}
