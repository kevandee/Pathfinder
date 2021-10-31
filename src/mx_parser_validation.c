#include "../inc/pathfinder.h"

int mx_parser_validation(char **file, int count_lines) {
    int i = 0;
    while (file[0][i] != '\0') {
        if (!mx_isdigit(file[0][i])) {
            return 1;
        }
        i++;
    }

    for (int i = 1; i < count_lines; i++) {
        int len = mx_strlen(file[i]);
        int word_num = 0;
        int start_word = 0;
        if (len == 0) {
            return i + 1;
        }

        for (int j = 0; j < len; j++) {
            switch (word_num) {
                case 0:
                        if (file[i][j + 1] == '\0') {
                            return i + 1;
                        }
                        if (file[i][j] == '-' && j > start_word) {
                            start_word = j + 1;
                            word_num++;
                            break;
                        }
                        if (!mx_isalpha(file[i][j])) {
                            return i + 1;
                        }
                        break;
                case 1:
                        if (file[i][j + 1] == '\0') {
                            return i + 1;
                        }
                        if (file[i][j] == ',' && j > start_word) {
                            start_word = j + 1;
                            word_num++;
                            break;
                        }
                        if (!mx_isalpha(file[i][j])) {
                            return i + 1;
                        }
                        break;
                case 2:
                        if (!mx_isdigit(file[i][j])) {
                            return i + 1;
                        }
                        break;
            }
        }
    }

    return 0;
}
