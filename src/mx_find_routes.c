#include "../inc/pathfinder.h"

void mx_find_routes(t_bridge **bridges, char **islands, int count_islands){
    int **matrix = to_matrix(bridges, islands, count_islands);
    
    for (int begin_index = 0; begin_index < count_islands; begin_index++) {
        for (int end_index = begin_index + 1; end_index < count_islands; end_index++) {
            long d[count_islands];
            int v[count_islands];
            long temp;
            long minindex = 0;
            long min;
            for (int i = 0; i < count_islands; i++) {
                d[i] = LONG_MAX;
                v[i] = 1;
            }
            d[begin_index] = 0;

            while (minindex < LONG_MAX) {
                minindex = LONG_MAX;
                min = LONG_MAX;
                for (int i = 0; i < count_islands; i++) { 
                    if ((v[i] == 1) && (d[i] < min)) { 
                        min = d[i];
                        minindex = i;
                    }
                }
                if (minindex != LONG_MAX) {
                    for (int i = 0; i < count_islands; i++) {
                        if (matrix[minindex][i] > 0) {
                            temp = min + matrix[minindex][i];
                            if (temp > INT_MAX) {
                                mx_printerr("error: sum of bridges lengths is too big\n");
                                exit(-1);
                            }
                            if (temp < d[i]) {
                                d[i] = temp;
                            }
                        }
                    }
                    v[minindex] = 0;
                }
            } 
            int end = end_index;
            bool all_is_start = false;
            t_path* firstPath = NULL;
            new_path(&firstPath, islands[begin_index]);
            firstPath ->weight = d[end];
            t_list* all_paths = NULL;
            mx_push_front(&all_paths, firstPath);
            mx_push_front(&(((t_path *)(all_paths -> data)) ->path), islands[end]);
            t_list* temp_paths;

            while (!all_is_start) {
                temp_paths = all_paths;
                all_is_start = true;
                
                while (temp_paths) {
                    if (!((t_path *)(temp_paths -> data)) ->is_start) {
                        all_is_start = false;
                    }
                    temp_paths = temp_paths -> next;
                }
                
                temp_paths = all_paths;
                while (temp_paths) {
                    
                    if (!((t_path *)(temp_paths -> data)) -> is_start) {
                            
                            int current = island_to_index(islands, count_islands, (((t_path *)(temp_paths -> data)) ->path)->data);
                            int temp_weight = ((t_path *)(temp_paths -> data)) -> weight;
                            int count_branches = 1;
                            
                            for (int i = 0; i < count_islands; i++) {
                                if (matrix[i][current] != 0) {
                                    int temp = temp_weight - matrix[i][current];
                                    if (temp == d[i]) {   
                                        if (count_branches > 1) {
                                            t_path *new;
                                            new_path_from_list(&new, ((t_path *)(temp_paths -> data))->start, ((t_path *)(temp_paths -> data)) ->path);
                                            mx_push_front(&(new ->path), islands[i]);
                                            new->weight = temp;
                                            new->count_isl = ((t_path *)(temp_paths -> data)) -> count_isl;
                                            count_branches++;
                                            mx_push_back(&all_paths, new);
                                        }
                                        else {
                                            ((t_path *)(temp_paths -> data)) -> weight = temp;
                                            ((t_path *)(temp_paths -> data)) -> count_isl++;
                                            mx_push_front(&(((t_path *)(temp_paths -> data)) ->path), islands[i]);
                                            count_branches++;
                                        }
                                    }
                                }
                                
                            }
                        
                        if (mx_strcmp((((t_path *)(temp_paths -> data))->path) -> data, ((t_path *)(temp_paths -> data))->start) == 0) {
                            ((t_path *)(temp_paths -> data)) -> is_start = true;
                        }
                    }
                    temp_paths = temp_paths -> next;
                }
            }
            
            temp_paths = all_paths;
            int size = mx_list_size(all_paths);
            for (int i = 0; i < size - 1; i++) {
                for (int j = 0; j < size - 1; j++) {
                    if (temp_paths -> next) {
                    if (((t_path *)(temp_paths -> data))->count_isl < ((t_path *)(temp_paths ->next-> data))->count_isl) {
                        t_path *temp = ((t_path *)(temp_paths -> data));
                        (temp_paths -> data) = (temp_paths -> next -> data);
                        (temp_paths -> next -> data) = temp;
                    }
                    temp_paths = temp_paths -> next;
                    }
                }
            }
            temp_paths = all_paths;
            output_paths(temp_paths, d, matrix, islands, count_islands,end_index);
            
            mx_clear_list(&all_paths);
            all_paths = NULL;
        }
    }

    delete_matrix(matrix, count_islands);
}
