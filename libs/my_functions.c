#include "my_functions.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 256

// Get functions
int get_int(const char *prompt)
{
    int c;
    int value;
    while (1)
    {
        if (prompt)
        {
            printf("%s", prompt);
            fflush(stdout);
        }
        if (scanf("%d", &value) == 1)
        {
            while ((c = getchar()) != '\n' && c != EOF);
            return value;
        } 
        else
        {
            printf("Error! Enter int number.\n");
            while (getchar() != '\n');
        }
    }
}

char* get_string(const char* prompt) 
{
    static char buffer[BUFFER_SIZE];

    if (prompt)
    {
        printf("%s", prompt);
        fflush(stdout);
    }

    if (fgets(buffer, sizeof(buffer), stdin) == NULL)
    {
        return NULL;
    }

    buffer[strcspn(buffer, "\n")] = '\0';

    return buffer;
}

int get_char(const char *prompt)
{
    if (prompt)
    {
        printf("%s", prompt);
        fflush(stdout);
    }

    int ch = getchar(); // Read the first character

    // Clear buffer: read and remove all symbols before \n or EOF
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}

    return ch; // Return readed symbol
}

// Arrays functions
void print_int_array(int *array, size_t SIZE)
{
    for (size_t i = 0; i < SIZE; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void print_char_array(char *array, size_t SIZE)
{
    for (size_t i = 0; i < SIZE; i++)
    {
        printf("%c ", array[i]);
    }
    printf("\n");
}

void print_str_array(char **array, size_t SIZE)
{
    for (size_t i = 0; i < SIZE; i++)
    {
        printf("%s ", array[i]);
    }
    printf("\n");
}

// String manipulations
char* to_upr(char *str)
{
    static char buffer[BUFFER_SIZE];
    size_t i;
    for (i = 0; str[i]; i++)
    {
        buffer[i] = toupper((unsigned char)str[i]);
    }
    buffer[i] = '\0';
    return buffer;
}

char* to_lwr(char *str)
{
    static char buffer[BUFFER_SIZE];
    size_t i;
    for (i = 0; str[i]; i++)
    {
        buffer[i] = tolower((unsigned char)str[i]);
    }
    buffer[i] = '\0';
    return buffer;
}
