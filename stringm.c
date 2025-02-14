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
    return 0;
}

/*
** strncpy_m copies n characters of string and returns it
** const char *string - string to copy
** size_t n - number of characters to copy (not including null character)
** return a copy of first n characters of string
*/
char *strncpy_m(const char *string, size_t n) {

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
char *join_m(Strings strings, const char *delimiter) {

}

/*
** find_and_replace_all finds each occurence of pattern in string and replaces it
** const char *string - string to search through
** const char *pattern - pattern to search for in string
** const char *replacement - replacement string for each occurence of pattern in string
** return a 
*/
char *find_and_replace_all(const char *string, const char *pattern, const char *replacement) {

}

/*
** this function is implemented for you to use -- do not modify
*/
const char *strstr_m(const char *haystack, const char *needle)
{
    size_t haystack_len = 0, needle_len = 0;
    for (const char *h = haystack; *h; h++)
        haystack_len++;
    for (const char *n = needle; *n; n++)
        needle_len++;

    if (needle_len > haystack_len)
        return NULL;

    char *lps_str = malloc(haystack_len + needle_len + 1);
    size_t i = 0;
    for (const char *n = needle; *n; n++, i++)
        lps_str[i] = *n;
    lps_str[i++] = '\1';
    for (const char *h = haystack; *h; h++, i++)
        lps_str[i] = *h;

    int *lps_arr = calloc((haystack_len + needle_len + 1), sizeof *lps_arr);
    size_t l = 0, r = 1;
    bool success = false;

    while (r < haystack_len + needle_len + 1)
    {
        if (lps_str[l] == lps_str[r])
        {
            l++;
            lps_arr[r] = l;
            r++;
        }
        else if (l)
            l = lps_arr[l-1];
        else
        {
            lps_arr[r] = 0;
            r++;
        }

        if (l == needle_len)
        {
            success = true;
            break;
        }
            
    }
    
    free(lps_arr);
    free(lps_str);
    if (success)
        return haystack + (r - l - needle_len - 1);
    return NULL;
}
