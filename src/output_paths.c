#include "../inc/pathfinder.h"

void output_paths(t_list* paths, long *d, int **matrix, char **islands, int count_islands, int end_index) {
    while (paths) {
                t_list* first = ((t_path *)(paths -> data)) ->path;
                mx_printstr("========================================\n");
                mx_printstr("Path: ");
                mx_printstr(((t_path *)(paths -> data)) -> start);
                mx_printstr(" -> ");
                mx_printstr(islands[end_index]);
                mx_printchar('\n');
                mx_printstr("Route: ");
                while (((t_path *)(paths -> data)) ->path) {
                    mx_printstr(((t_path *)(paths -> data)) ->path -> data);
                    if (((t_path *)(paths -> data)) ->path -> next) {
                        mx_printstr(" -> ");
                    }
                    else {
                        mx_printchar('\n');
                    }
                    ((t_path *)(paths -> data)) ->path = (((t_path *)(paths -> data)) ->path)->next;
                }
                ((t_path *)(paths -> data)) ->path = first;
                mx_printstr("Distance: ");
                
                while (((t_path *)(paths -> data)) ->path) {
                    if (matrix[island_to_index(islands, count_islands, ((t_path *)(paths -> data)) ->path -> data)][island_to_index(islands, count_islands, ((t_path *)(paths -> data)) ->path->next -> data)] == d[end_index]) {
                        mx_printint(d[end_index]);
                        mx_printchar('\n');
                        break;
                    }
                    if (!((t_path *)(paths -> data)) -> path -> next -> next) {
                        mx_printint(matrix[island_to_index(islands, count_islands, ((t_path *)(paths -> data)) ->path -> data)][island_to_index(islands, count_islands, ((t_path *)(paths -> data)) ->path->next -> data)]);
                        mx_printstr(" = ");
                        mx_printint(d[end_index]);
                        mx_printchar('\n');
                        break;
                    }
                    mx_printint(matrix[island_to_index(islands, count_islands, ((t_path *)(paths -> data)) ->path -> data)][island_to_index(islands, count_islands, ((t_path *)(paths -> data)) ->path->next -> data)]);
                    mx_printstr(" + ");
                    ((t_path *)(paths -> data)) ->path = (((t_path *)(paths -> data)) ->path)->next;
                }
                mx_printstr("========================================\n");
                ((t_path *)(paths -> data)) ->path = first;
                paths = paths -> next;
            }
}
