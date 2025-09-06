#include <stdio.h>
#include <stdlib.h>

#include "str_functions.h"



int my_puts ( const char* string ) {

    int index = 0;

    if ( string == nullptr ) {

        return -1;

    }

    while ( string[index] != '\0' ) {

        putchar (string[index]);
        index++;

    }

    putchar('\n');

    return 0;

}



char* my_strchr ( const char* string, int symbol ) {

    int index = 0;

    while ( string[index] && string[index] != symbol ) ++index;

    return symbol == string[index] ? (char*)string + index : nullptr;

}



int my_strlen( const char* string ) {

    int index = 0;

    while (string[index]) ++index;

    return index;

}



char* my_strcpy ( char* string_1, const char* string_2 ) {

    char* symbol = string_1;

    while ( *symbol != '\0' ) {

        while ( *string_2 != '\0' ) {
        
            *symbol = *string_2;

            string_2++;
            symbol++;
            
        }

        *symbol = '\0';
        symbol++;

    }

    return string_1;

}



char* my_strncpy ( char* string_1, const char* string_2, size_t number ) {

    char* symbol = string_1;
    size_t index = 0;

    while ( *symbol != '\0' ) {

        while ( *string_2 != '\0' && index < number ) {
        
            *symbol = *string_2;

            string_2++;
            symbol++;
            index++;
            
        }

        *symbol = '\0';
        symbol++;

    }

    return string_1;

}



char* my_strcat ( char* string_1, const char* string_2 ) {

    char* symbol = string_1;

    while ( *symbol != '\0' ) {

        symbol++;

    } 
    while ( *string_2 != '\0' ) {
        
        *symbol = *string_2;

        string_2++;
        symbol++;
            
    }


    return string_1;

}



char* my_strncat ( char* string_1, const char* string_2, size_t number ) {

    size_t index = 0;
    char* symbol = string_1;

    while ( *symbol != '\0' ) {

        symbol++;

    } 

    while ( *string_2 != '\0' && index < number ) {
        
        *symbol = *string_2;

        index++;
        string_2++;
        symbol++;
            
    }


    return string_1;

}



char* my_fgets ( char* string, int number_chars, FILE *stream ) {
 
    char* symbol       = string;
    int   index        = 0;
    int   check_symbol = 0;

    while ( index < number_chars-1) {

        check_symbol = getc(stream);

        if (check_symbol != -1) {

            *symbol = (char)check_symbol;

            symbol++;
            index++;

        } else break;

    }

    *symbol = '\0';

    return string;

}



char* my_strdup ( const char* string ) {

    int num_char = my_strlen (string) + 1;

    char* new_string = (char*)malloc( num_char*sizeof(char) );

    return my_strcpy ( new_string, string );

    free(new_string);

}



size_t my_getline ( char* string, size_t* num_char, FILE* stream ) {

    size_t num_scan       = 1;
    char*  symbol         = string;
    int    check_symbol   = 0;
    int    local_num_char = 0;

    while(1) {

        check_symbol = getc(stream);

        if ( check_symbol == -1 ||
             check_symbol == '\n' ) {

            *symbol = '\n';
            *(symbol + 1) = '\0';

            return num_scan;

        }

        if ( *num_char == num_scan + 1 ) {

            string = (char*)realloc( string, sizeof(char)*num_scan );
            symbol = string + num_scan;
            printf("%p\n", string); 
            num_char++;

        }

        *symbol = (char)check_symbol;

        num_scan++;
        symbol++;

    }

}