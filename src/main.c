#include "../inc/pathfinder.h"

int main(int argc, char *argv[]) {
    
    if (argc != 2) {
        mx_printerr("usage: ./pathfinder [filename]\n");
        return -1;
    }

    char *file = mx_file_to_str(argv[1]);
    char **islands = NULL;
    t_bridge **bridges = NULL;
    int count_islands = 0;
    int count_bridges = 0;

    mx_island_parser(file, &bridges, &islands, &count_islands, &count_bridges);
    mx_find_routes(bridges, islands, count_islands, count_bridges);

    delete_src(&file, &islands, &bridges, count_bridges, count_islands);
}
