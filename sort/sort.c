#include <stdio.h>
#include "libs/my_functions.h"

void bubble_sort(int* array, size_t SIZE);

int main(void)
{
    const size_t SIZE = 7;
    int array[] = {2, 7, 5, 3, 4, 6, 1};
    bubble_sort(array, SIZE);
    print_int_array(array, SIZE);
}

void bubble_sort(int* array, size_t SIZE)
{
    int tmp;
    for (size_t j = 0; j < (SIZE - 1); j++)
    {
        printf("%d cycle: \n", j + 1);
        for (size_t i = 0; i < (SIZE - 1 - j); i++)
        {
            if (array[i] > array[i + 1])
            {
                tmp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = tmp;
            }
            print_int_array(array, SIZE);
        }
    }
}
