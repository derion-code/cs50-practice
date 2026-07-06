#include <stdio.h>
#include <stdbool.h>
#include "my_functions.h"

bool linear_search(int *arr, int N, int value);

int main(void)
{
    const int N = 7;
    int numbers[] = {1, 5, 3, 4, 8, 9, 2};
    int value = get_int("Search: ");
    printf("Linear | Value: %d | Status: %s\n", \
        value, linear_search(numbers, N, value) ? "true" : "false");
    
    printf("Before sort: ");
    print_int_array(numbers, N);
    printf("After sort: ");
    print_int_array(numbers, N);
}

bool linear_search(int *arr, int N, int value)
{
    for (int i = 0; i < N; i++)
    {
        if (arr[i] == value)
        {
            return true;
        }
    }
    return false;
}
