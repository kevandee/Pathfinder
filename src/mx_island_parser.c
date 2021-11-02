#include "../inc/pathfinder.h"

void mx_island_parser(const char *file, t_bridge*** bridges, char*** islands,  int* count_islands, int* count_bridges) {
    int count_lines = mx_count_lines(file, '\n');
    char **str_lines = mx_strsplitlines(file, '\n');
    *count_islands = mx_atoi(str_lines[0]);
    int temp_count_islands = 0;
    int error_line = mx_parser_validation(str_lines, &count_lines);
    if(error_line) {
        mx_printerr("error: line ");
        mx_printerr(mx_itoa(error_line));
        mx_printerr(" is not valid\n");
        exit(-1);
    }

    *islands = (char **)malloc((*count_islands) * sizeof(char *));

    *bridges = (t_bridge **)malloc((count_lines) * sizeof(t_bridge*));
    for (int i = 1; i < count_lines; i++) {
        (*bridges)[i - 1] = (t_bridge *)malloc(sizeof(t_bridge));
        
        char *temp = str_lines[i];
        
        for (int j = 0; j < 2; j++) {
            
            int len = 0;
            
            while(temp[len] != '-' && j == 0) {
                len++;
            }
            while(temp[len] != ',' && j == 1) {
                len++;
            }
            
            switch(j) {
                case 0:
                    (*bridges)[i - 1] -> start = mx_strndup(temp, len);
                    if (!islands_entry(*islands, temp_count_islands, (*bridges)[i - 1] -> start)) {
                        (*islands)[temp_count_islands] = mx_strdup((*bridges)[i - 1] -> start);
                        temp_count_islands++;
                    }
                    break;
                case 1:
                    (*bridges)[i - 1] -> end = mx_strndup(temp, len);
                    if (!islands_entry(*islands, temp_count_islands, (*bridges)[i - 1] -> end)) {
                        (*islands)[temp_count_islands] = mx_strdup((*bridges)[i - 1] -> end);
                        temp_count_islands++;
                    }
                    break;
            }

            temp += len + 1;
        }
        
        (*bridges)[i - 1] -> length = mx_atoi(temp);
    }
    
    if (temp_count_islands != *count_islands) {
        mx_printerr("error: invalid number of islands\n");
        exit(-1);
    }
    *count_bridges = count_lines - 1;
    for (int i = 0; i < *count_bridges; i++) {
        for(int j = i + 1; j < *count_bridges; j++) {
            if (is_bridge_dup(*bridges, i, j)) {
                mx_printerr("error: duplicate bridges\n");
                exit(-1);
            }
        }
    }
    for (int i = 0; i < count_lines; i++) {
        mx_strdel(&str_lines[i]);
    }
    free(str_lines);
}
