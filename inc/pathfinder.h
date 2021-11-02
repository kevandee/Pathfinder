#ifndef PATHFINDER_H
#define PATHFINDER_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include "../libmx/inc/libmx.h"

typedef struct s_bridge {
    char* start;
    char* end;
    int length;
}              t_bridge;

typedef struct s_path {
    t_list* path;
    char *start;
    bool is_start;
    int weight;
    int count_isl;
}              t_path;

void mx_island_parser(const char *file, t_bridge*** bridges, char*** islands, int* count_islands, int* count_bridges);
int mx_parser_validation(char **file, int *count_lines);
void mx_find_routes(t_bridge **bridges, char **islands, int count_islands, int count_bridges);
void output_paths(t_list* paths, long *d, int **matrix, char **islands, int count_islands, int end_index);

bool is_bridge_dup(t_bridge **bridges, int i, int j);
int **to_matrix(t_bridge **bridges, char **islands, int count_islands, int count_bridges);
int island_to_index(char **islands, int count_islands, char *name);
bool islands_entry(char **islands, int count_islands, char *new_island);

void new_path(t_path** path, char *name);
void new_path_from_list(t_path** path, char *name, t_list* old_path);

void delete_matrix(int **matrix, int size);
void delete_src(char **file, char ***islands, t_bridge ***bridges, int count_bridges, int count_islands);

#endif
