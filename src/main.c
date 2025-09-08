#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "str_functions.h"



int main() {

    size_t      str_3_len      = 5;
    const char  test_char_1    = 'l';
    FILE*       test_file_1    = fopen("test.txt", "r");

    const char* test_str_1     = "Hello world";
    char        test_str_2[10] = "Meow";
    char*       test_str_3     = (char*) calloc ( str_3_len, sizeof(char));
    const char* test_str_4     = "ujqwc-jknqwf1v235nea42nwef2"; //-1235422

    // Пример работы my_puts
    // printf( "%d", my_puts(test_str_1));

    // Пример работы my_strchr
    // printf( "%c", *my_strchr(test_str_1, test_char_1));
    // printf ( "%d", my_strlen( test_str_1));

    // Пример работы my_strcpy  
    // printf ( "%s", my_strcpy ( test_str_2, test_str_1));

    // Пример работы my_strncpy
    // printf ( "%s", my_strncpy ( test_str_2, test_str_1, 5));

    // Пример работы my_strcat
    // printf ( "%s", my_strcat ( test_str_2, test_str_1));

    // Пример работы my_strncat
    // printf ( "%s", my_strncat ( test_str_2, test_str_1, 5));

    // Пример работы my_fgets
    // printf ( "%s", my_fgets ( test_str_2, 25, test_file_1));

    // Пример работы my_strdup
    // printf ( "%s\n", my_strdup (test_str_1));
    // printf ( "%p %p\n", my_strdup ( test_str_1), test_str_1);

    // Пример работы my_getline
    // printf ( "symbols scaned: %d\n", my_getline(&test_str_3, &str_3_len, test_file_1));
    // printf ( "scaned line: %s", test_str_3);

    // Пример работы my_atoi
    // printf ( "number: %d", my_atoi ( test_str_4 ));

    return 0;
}