// ***
// *** DO NOT modify this file
// ***

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stringm.h"

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

        Strings result = split_string(str, ',');
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

/*
* String functions used by main (Do NOT MODIFY)
*/
static char* read_string_from_file(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return NULL;
    }

    // Get file size
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    // Allocate memory for the string
    char* str = malloc(file_size + 1);
    if (str == NULL) {
        printf("Memory allocation failed\n");
        fclose(file);
        return NULL;
    }

    // Read entire file
    size_t bytes_read = fread(str, 1, file_size, file);
    str[bytes_read] = '\0';

    fclose(file);
    return str;
}

static int read_strings_from_file(const char* filename, const char* const** strings, size_t* count, const char** separator) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        return -1;
    }

    // First pass: count lines
    size_t total_lines = 0;
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), file)) {
        total_lines++;
    }

    if (total_lines < 1) {
        fclose(file);
        return -1; 
    }

    // Allocate memory for strings array
    *count = total_lines - 1;  // Exclude separator line
    char** temp_strings = malloc(sizeof(char*) * (*count));
    if (!temp_strings) {
        fclose(file);
        return -1;
    }

    // Reset file position
    rewind(file);

    // Second pass: read strings
    for (size_t i = 0; i < *count; i++) {
        if (!fgets(buffer, sizeof(buffer), file)) {
            // Error reading file
            for (size_t j = 0; j < i; j++) {
                free(temp_strings[j]);
            }
            free(temp_strings);
            fclose(file);
            return -1;
        }

        // Remove newline if present
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len-1] == '\n') {
            buffer[len-1] = '\0';
            len--;
        }

        // Allocate and copy string
        temp_strings[i] = malloc(len + 1);
        if (!temp_strings[i]) {
            for (size_t j = 0; j < i; j++) {
                free(temp_strings[j]);
            }
            free(temp_strings);
            fclose(file);
            return -1;
        }
        strcpy(temp_strings[i], buffer);
    }

    // Read separator (last line)
    if (!fgets(buffer, sizeof(buffer), file)) {
        for (size_t i = 0; i < *count; i++) {
            free(temp_strings[i]);
        }
        free(temp_strings);
        fclose(file);
        return -1;
    }

    // Remove newline from separator if present
    size_t len = strlen(buffer);
    if (len > 0 && buffer[len-1] == '\n') {
        buffer[len-1] = '\0';
        len--;
    }

    // Allocate and copy separator
    *separator = malloc(len + 1);
    if (!*separator) {
        for (size_t i = 0; i < *count; i++) {
            free(temp_strings[i]);
        }
        free(temp_strings);
        fclose(file);
        return -1;
    }
    strcpy((char*)*separator, buffer);

    *strings = (const char* const*)temp_strings;
    fclose(file);
    return 0;
}

static void free_strings(const char* const* strings, size_t count, const char* separator) {
    for (size_t i = 0; i < count; i++) {
        free((void*)strings[i]);
    }
    free((void*)strings);
    free((void*)separator);
}