#ifndef _STR_FUNCTIONS_
#define _STR_FUNCTIONS_

char*  my_strcpy  ( char* string_1, const char* string_2);
int    my_strlen  ( const char* string);
int    my_puts    ( const char* string);
char*  my_strchr  ( const char * string, int symbol);
char*  my_strncpy ( char* string_1, const char* string_2, size_t number);
char*  my_strcat  ( char* string_1, const char* string_2);
char*  my_strncat ( char* string_1, const char* string_2, size_t number);
char*  my_fgets   ( char* string, int number_chars, FILE *stream);
char*  my_strdup  ( const char* string);
size_t my_getline ( char* string, size_t* num_char, FILE* stream );

#endif