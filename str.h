// Modify this file

// The Strings struct is used to store an array of strings and the number of strings in the array.
struct Strings {
    // Modify this struct
};


struct Strings split_string(char const* text, char separator);

char* read_string_from_file(const char* filename);
int read_strings_from_file(const char* filename, const char* const** strings, size_t* count, const char** separator);
void free_strings(const char* const* strings, size_t count, const char* separator);

char* copy_string(const char* source);
char* join_strings(const char* const* strings, size_t num_strings, const char* separator);
