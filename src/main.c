#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "str_functions.h"



int main() {

    const char* test_str_1      = "Hello world";
    const char  test_char_1     = 'l';
    size_t      str_2_len       = 10;
    char        test_str_2[10] = "Meow";
    FILE*       test_file_1     = fopen("test.txt", "r");

    //printf( "%d", my_puts(test_str_1));

    //printf( "%c", *my_strchr(test_str_1, test_char_1));
    //printf ( "%d", my_strlen( test_str_1));

    //printf ( "%s", my_strcpy ( test_str_2, test_str_1));

    //printf ( "%s", my_strncpy ( test_str_2, test_str_1, 5));

    //printf ( "%s", my_strcat ( test_str_2, test_str_1));

    //printf ( "%s", my_strncat ( test_str_2, test_str_1, 5));

    // printf ( "%s", my_fgets ( test_str_2, 25, test_file_1));

    // printf ( "%s\n", my_strdup (test_str_1));
    // printf ( "%p %p\n", my_strdup ( test_str_1), test_str_1);

    printf ( "old: %p\n", test_str_2);
    printf ( "scaned: %d\n", my_getline( test_str_2, &str_2_len, test_file_1));
    printf ( "str_new: %s", test_str_2);
    printf ( "new: %p, %d\n", test_str_2, my_strlen(test_str_2));

    return 0;
}