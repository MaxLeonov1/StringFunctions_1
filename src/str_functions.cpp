#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "str_functions.h"

/*-----------------------------------------------------------------------------------------*/

/*!
    \brief Реализация стандартной функции puts()

    Выводит переданную строку в stdout с добавлением символа '\n'

    \param[in] string выводимая строка
    \return 0 если быливыведены символы -1 если нет
*/
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

/*-----------------------------------------------------------------------------------------*/

/*!
    \brief Реализация стандартной функции strchr

    Ищет вхождение переданного символа в переданную строку

    \param[in] string укакзатель на строку для поиска
    \param[in] symbol символ для поиска
    \return указатель на вхождение символа, если он найден, nullptr если нет
*/
char* my_strchr ( const char* string, int symbol ) {

    assert ( string == nullptr );

    int index = 0;

    while ( string[index] && string[index] != symbol ) ++index;

    return symbol == string[index] ? (char*)string + index : nullptr;

}

/*-----------------------------------------------------------------------------------------*/

/*!
    \brief Реализация стандартной функции strlen

    Определяет длину строки в символах
    
    \param[in] string передаваемая строка
    \return количество символов
*/
int my_strlen( const char* string ) {

    assert ( string == nullptr );

    int index = 0;

    while (string[index]) ++index;

    return index;

}

/*-----------------------------------------------------------------------------------------*/

/*!
    \brief Реализация стандартной функции strcpy

    Копирует строку 2 в строку 1
    \attention подразумевается что строка 1 >= строки 2

    \param[in] string_1 строка в которую будет совершено копирование
    \param[in] string_2 копируемая строка
    \return указатель на строку в которую совершено копирование
*/
char* my_strcpy ( char* string_1, const char* string_2 ) {

    assert ( string_1 == nullptr ||
             string_2 == nullptr);

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

/*-----------------------------------------------------------------------------------------*/

/*!
    \brief Реализация стандартной функции strncpy

    Копирует n символов строки 2 в строку 1
    \attention подразумевается что строка 1 >= строки 2

    \param[in] string_1 строка в которую будет совершено копирование
    \param[in] string_2 копируемая строка
    \param[in] number число символов для копирования
    \return указатель на строку в которую совершено копирование
*/
char* my_strncpy ( char* string_1, const char* string_2, size_t number ) {

    assert ( string_1 == nullptr ||
             string_2 == nullptr);

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

/*-----------------------------------------------------------------------------------------*/

/*!
    \brief Реализация стандартной функции strcat

    Копирует строку 2 в конец строки 1
    \attention подразумевается что строка 1 > длина строки 2 + длина строки 1

    \param[in] string_1 строка в конец которой будет совершено копирование
    \param[in] string_2 копируемая строка
    \return указатель на строку в которую совершено копирование
*/
char* my_strcat ( char* string_1, const char* string_2 ) {

    assert ( string_1 == nullptr ||
             string_2 == nullptr);

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

/*-----------------------------------------------------------------------------------------*/

/*!
    \brief Реализация стандартной функции strncat

    Копирует n символов строки 2 в конец строки 1
    \attention подразумевается что строка 1 > длина n символов строки 2 + длина строки 1

    \param[in] string_1 строка в конец которой будет совершено копирование
    \param[in] string_2 копируемая строка
    \param[in] number число символов для копирования
    \return указатель на строку в которую совершено копирование
*/
char* my_strncat ( char* string_1, const char* string_2, size_t number ) {

    assert ( string_1 == nullptr ||
             string_2 == nullptr );

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

/*-----------------------------------------------------------------------------------------*/

/*!
    \brief Реализация стандартной функции fgets

    Копирует n символов из переданого потока ввода в строку
    
    \param[in] string строка в которую будут скопированны символы
    \param[in] number_chars количество символов которое надо скопировать
    \param[in] stream поток из которого совершается копирование
    \return указатель на строку в которую совершено копирование 
*/ 
char* my_fgets ( char* string, int number_chars, FILE *stream ) {

    assert ( string == nullptr );
 
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

/*-----------------------------------------------------------------------------------------*/

/*!
    \brief Реализация стандартной функции strdup()

    Копирует строку с выделение под неё новой памяти через malloc()
    
    \param[in] string копируемая строка
    \return указатель на копию строки
*/
char* my_strdup ( const char* string ) {

    assert ( string == nullptr );

    int num_char = my_strlen (string) + 1;

    char* new_string = (char*)malloc( num_char*sizeof(char) );

    return my_strcpy ( new_string, string );

}

/*-----------------------------------------------------------------------------------------*/

/*!
    \brief Реализация стандартной функции getline

    Копирует строку, из переданного потока ввода, до конца файла или символа новой строки в переную строку
    \note при необходимости аллоцирует память если размера строки не хватает

    \param[in] string указатель на указатель начала строки
    \param[in] num_char указатель на изначальный размер строки
    \param[in] stream указатель на поток ввода
    \return количество считанных символов из потока ввода
*/
size_t my_getline ( char** string, size_t* num_char, FILE* stream ) {

    size_t num_scan       = 0;
    int    check_symbol   = 0;

    if ( *string == nullptr && *num_char == 0) { // Выделение памяти в случае если память под строку не аллоцированна

        *num_char = 8;
        *string = (char*)calloc( *num_char, sizeof(char) );

    }

    while ( ( check_symbol = getc(stream) ) != EOF && 
              check_symbol                  != '\n') { // Считывание символов из указанного файла

        if ( num_scan + 1 >= *num_char ) { // Выделение доп памяти в случае её нехватки

            *num_char *= 2;
            *string = (char*)realloc( *string, *num_char );

        }

        (*string)[num_scan++] = (char)check_symbol;

    }

    if ( num_scan < *num_char) { // Добавление '\0' и '\n' в конец строки

        (*string)[num_scan] = '\n';
        (*string)[num_scan + 1] = '\0';

    } else { // Выделение доп памяти в случае её нехватки для '\0' и '\n'

        *num_char += 2;
        *string = (char*)realloc( *string, *num_char );

        (*string)[num_scan] = '\n';
        (*string)[num_scan + 1] = '\0';

    }

    return num_scan;

}

/*-----------------------------------------------------------------------------------------*/

/*!
    \brief Реализация стандартной функции atoi

    Конвертирует найденые в строке числовые символы в одно число
    \note поиск символов совершается только до символа новой строки или пробела

    \param[in] указатель на строку для поиска
    \return полученое число, 0 если не было найдено числовых символов
*/
int my_atoi ( const char* string ) {

    int negative = 0;
    int result   = 0;

    assert ( string == nullptr );

    while ( *string != '\n' && *string != ' ' ) {

        if ( *string == '-' ) {

            negative = 1;

        }

        if ( *string >= '0' && *string <= '9' ) {

            result = ( result * 10 ) + *string - '0';

        }

        string++;

    }

    if ( negative ) result *= -1;
    return result;

}