/* 
** -----------------------------------------------------------------
** IMPORTANT NOTE: For this assignment, you are not allowed to use
** string.h or any header file other than what is defined below
** -----------------------------------------------------------------
*/
#include "stringm.h"

/* 
** strlen_m calculates the length of a string
** const char *string - string to calculate length of
** return the size of the string
*/
size_t strlen_m(const char *string) {

}

/*
** strncpy_m copies n characters of string and returns it
** const char *string - string to copy
** size_t n - number of characters to copy (not including null character)
** return a copy of first n characters of string
*/
char * strncpy_m(const char *string, size_t n) {

}

/*
** split_m splits a string at any occurence of pattern
** const char *string - string that is searched for the pattern
** const char *pattern - pattern which string should be split
** return a String structure which contains an array of each string
*/
Strings split_m(const char *string, const char *pattern) {

}

/*
** join_m joins an array of strings separated by a delimiter
** Strings strings - structure that includes array of strings
** const char *delimiter - delimiter string which joins each string
** return the joined string
*/
char * join_m(Strings strings, const char *delimiter) {

}

/*
** find_and_replace_all finds each occurence of pattern in string and replaces it
** const char *string - string to search through
** const char *pattern - pattern to search for in string
** const char *replacement - replacement string for each occurence of pattern in string
** return a 
*/
char * find_and_replace_all(const char *string, const char *pattern, const char *replacement) {

}

/*
** THIS FUNCTION IS GIVEN TO YOU -- DO NOT MODIFY
*/
char * strstr_m(const char *haystack, const char *needle) {

}


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
