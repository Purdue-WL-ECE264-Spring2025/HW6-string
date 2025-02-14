// Modify this file

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "str.h"

// ***
// *** DO NOT modify this function
// ***
char* read_string_from_file(const char* filename) {
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

// ***
// *** DO NOT modify this function
// ***
int read_strings_from_file(const char* filename, const char* const** strings, size_t* count, const char** separator) {
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

// ***
// *** DO NOT modify this function
// ***
void free_strings(const char* const* strings, size_t count, const char* separator) {
    for (size_t i = 0; i < count; i++) {
        free((void*)strings[i]);
    }
    free((void*)strings);
    free((void*)separator);
}


// Modify this function
/* copy_string creates a duplicate of a given C string without using built-in functions like strcpy or strlen. 
You have to manually calculate the length of the string and copy it. You need to manually calculate the length 
of the string and copy each character, including the null terminator. The function should correctly handle copying 
both empty strings and multi-line strings.
Do not use strcpy or strlen.
*/
char* copy_string(const char* source) {
    // If the input source is NULL, the function immediately returns NULL to avoid errors.
    
    
    // Manually count the characters in source until it encounters the null terminator ('\0')
    
    
    // Allocate memory for the new string, including space for the null terminator (length + 1 bytes).
    

    // If memory allocation fails, return NULL
    
    
    // Copy each character from source to the newly allocated memory, including the null terminator.
    
    
    // Return the pointer to the copied string
    
}

// Modify this function
/* join_strings concatenates an array of strings into a single string, inserting a specified separator between each original string.
Args:
    - `strings`: A pointer to an array of constant strings. Both the strings and the pointers are treated as read-only, 
       ensuring no modifications are made to the original data.
    - `num_strings`: The number of strings in the array.
    - `separator`: A constant string that will be inserted between each original string.
You can use strlen, strcpy and strcat.
When you allocate memory for a string, don't forget to allocate space for the null terminator!!!!
*/
char* join_strings(const char* const* strings, size_t num_strings, const char* separator) {
    // If num_strings is 0, return a newly allocated empty string.
    

    // If num_strings is 1, return a copy of the single string.
    // You can use the copy_string function you implemented earlier or use strcpy.
    

    // Calculate the total length needed for the new string, including separators.
    // You can use strlen to get the length of each string and separator.
    // Use a loop to sum up the lengths of all strings and separators.
    

    // Allocate memory for the new string including the null terminator
    
    
    // Copy each string to the new string, adding separators as needed.
    // You can use strcat to concatenate strings or manually copy characters.
    

    // Return the pointer to the new string
    
}

// Modify this function
/* split_string splits a string into substrings based on a given separator. It returns a Strings structure containing 
an array of dynamically allocated strings. Note: The caller is responsible for freeing the allocated memory.

Do not use strtok().
You can use strlen and strncpy.*/
struct Strings split_string(char const* text, char separator) {
    // Initialize a Strings structure, the array of strings should be NULL and the number of strings should be 0.
    struct Strings result;
    

    // If the input text is NULL, return an empty Strings structure.
    

    // Part1: Count the number of splits needed
    // Declare a variable to keep track of the number of splits
    // Initialize the variable to 1, as there will be at least one part
    size_t count = 1;  

    // Declare a pointer to traverse the input text
    // Iterate through the input text, incrementing the count each time the separator is encountered
    

    // Allocate memory for the array of strings
    

    // If memory allocation fails, return an empty Strings structure
    

    // Set the number of strings in the result
    

    // Part2: Split the string

    // Iterate through the text, copying each part before the separator to the array of strings
    // You need a size_t variable to keep track of the current position in the array of strings
    // You can use two pointers, one to keep track of the start of the current part and one to traverse the text
    // When the separator is encountered, calculate the length of the current part and allocate memory for it
    // Use strncpy to copy the current part to the array of strings
    // Don't forget to add the null terminator
    // After copying the current part, move the start pointer to the next character after the separator
    // Repeat until the end of the text is reached
    // Don't forget to copy the remaining part after the last separator

    // If malloc fails at any point, free all previously allocated memory and return an empty Strings structure
    
    


    // Return the Strings structure
    return result;
}
