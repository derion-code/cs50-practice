#include <stdio.h>
#include <string.h>
#include "libs/my_functions.h"
#define SIZE 3

typedef struct
{
    char *name;
    char *number;
} person;

int main(void)
{
    char *names[SIZE] = {"Danya", "Dima", "Maksim"};
    char *numbers[SIZE] = {"+7-977-656-78-21", "+7-933-740-88-06", "+7-495-671-22-01"};
    
    person people[3];
    for (int i = 0; i < SIZE; i++)
    {
        people[i].name = names[i];
        people[i].number = numbers[i];
    }
    
    print_str_array(names, SIZE);
    char *name = get_string("Name: ");
    for (int i = 0; i < SIZE; i++)
    {
        if (strcmp(people[i].name, name) == 0)
        {
            printf("Found %s\n", people[i].number);
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}
