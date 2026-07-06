#ifndef MY_FUNCTIONS_H
#define MY_FUNCTIONS_H
#include <string.h>
#include <ctype.h>

// Get functions
int get_int(const char *prompt);
char *get_string(const char *prompt);
int get_char(const char *prompt);

// Arrays functions
void print_int_array(int *array, size_t SIZE);
void print_str_array (char **array, size_t SIZE);
void print_char_array (char *array, size_t SIZE);

// String manipulations
char* to_upr(char *str);
char* to_lwr(char *str);

#endif
