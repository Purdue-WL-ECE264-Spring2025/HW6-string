// ***
// *** DO NOT modify this file
// ***

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "str.h"

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file> <type>\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (strcmp(argv[2], "copy") == 0) {
        char * str = read_string_from_file(argv[1]);

        if (str == NULL) {
            fprintf(stderr, "Error reading file\n");
            return EXIT_FAILURE;
        }

        char * new_str = copy_string(str);
        printf("%s", new_str);
        free(new_str);
        free(str);
    }
    else if (strcmp(argv[2], "join") == 0) {
        const char* const* strings;
        const char* separator;
        size_t count;

        if (read_strings_from_file(argv[1], &strings, &count, &separator) == 0) {
            char* joined_string = join_strings(strings, count, separator);
            if (joined_string) {
                printf("%s", joined_string);
                free(joined_string);
            }
            free_strings(strings, count, separator);
        } else {
            printf("Error reading file\n");
            return EXIT_FAILURE;
        }
    }
    else if (strcmp(argv[2], "split") == 0) {
        char * str = read_string_from_file(argv[1]);

        if (str == NULL) {
            fprintf(stderr, "Error reading file\n");
            return EXIT_FAILURE;
        }

        struct Strings result = split_string(str, ',');
        if (result.strings) {
            for (size_t i = 0; i < result.num_strings; i++) {
                printf("%s\n", result.strings[i]);
                free(result.strings[i]);
            }
            free(result.strings);
        }
    }
    else {
        fprintf(stderr, "Invalid argument\n");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}