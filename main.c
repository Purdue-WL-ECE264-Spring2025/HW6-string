/*
** DO NOT MODIFY THIS FILE
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stringm.h"
#include "miniunit.h"
/*
** Below are the test cases, feel free to ignore them
** Note that the argument to mu_check() is the expected result for that test
*/
static int test1(void); 
static int test2(void);
static int test3(void);
static int test4(void);
/*
** strlen_m test cases
*/
static int test1(void) {
    mu_start();
    size_t size = strlen_m("");
    mu_check(size == 0);
    mu_end();
}

static int test2(void) {
    mu_start();
    size_t size = strlen_m("a");
    mu_check(size == 1);
    mu_end();
}

static int test3(void) {
    mu_start();
    size_t size = strlen_m("abcdefghijklmnopqrstuvwxyz");
    mu_check(size == 26);
    mu_end();
}

/*
** strncpy_m test cases
*/
static int test4(void) {
    mu_start();
    char *str = strncpy_m("", 0);
    mu_check_strings_equal(str, "");
    free(str);
    mu_end();
}
/*
strncpy_m (str will not be NULL and n <= strlen(str); need to add null terminator)
1. "", 0 - ""
2. "a", 0 - ""
3. "abcdefed", 5 - "abcde"
4. "aaaaaaaaaaaaaaaaaa", 18 - "aaaaaaaaaaaaaaaaaa"

split_m (str and pattern will not be NULL)
1. "", "" - { {""}, 1 }
2. "", "," - { {""}, 1 }
3. ",", "" - { {","}, 1 }
4. ",", "," - { {"",""}, 2}
5. "well,wall,,will,wull,,,woll,", "," - { {"well", "wall", "", "will", "wull", "", "", "woll", ""}, 9}

join_m (delimiter is not NULL, if strings.num_strings < 2 => return NULL (num == 0) or strings[0] (num == 1))
1. {{}, 0}, "abc" - NULL
2. {{"word"}, 1}, "noadd" - "word"
3. {{"a", "b", "c", "d", "e", "f"}, 6}, "" - "abcdef"
4. {{"a", "b", "c", "d", "e", "f"}, 6}, "x" - "axbxcxdxexf"
5. {{"Hello", "Hello", "Hello", "is", "there", "anybody", "in", "there", "?"}, 9}, " " = "Hello Hello Hello is there anybody in there ?"

find_and_replace_all_m(no string will be NULL) # Change this name to include the _m in the header file please
1. "", "", "" - ""
2. "abc", "z", "y" - "abc"
3. "aaa", "a", "" - ""
4. "aaa", "a", "b" - "bbb"
5. "aaa", "a", "xyz" - "xyzxyzxyz"
6. "mississippi", "issip", "gotcha?" - "missgotcha?pi"
*/
int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <test_num>", argv[0]);
        return EXIT_FAILURE;
    }

    // get desired test number, -1 = all tests
    const int test_num = atoi(argv[1]);
    if(test_num == 0) {
        fprintf(stderr, "Error, invalid test number. Must be an integer and non-zero.\n");
    }
    // define test functions
    int (*mu_test_functions[])(void) = 
                            { 
                            test1, 
                            test2,
                            test3,
                            test4,
                            };

    const int num_tests = sizeof(mu_test_functions) / sizeof(*mu_test_functions);

    if(test_num == -1) {
        for(int i = 0; i < num_tests; i++) {
            mu_run(mu_test_functions[i], i+1);
        }
    }
    else if(test_num > 0 && test_num <= num_tests) {
        mu_run(mu_test_functions[test_num - 1], test_num);
    }
    else {
        fprintf(stderr, "Please enter a valid test number (-1 for all, or in range 1 to %d\n", num_tests);
    }
    return EXIT_SUCCESS;
}
