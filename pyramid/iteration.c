#include <stdio.h>
#include <ctype.h>
#include "libs/my_functions.h"

int iteration_draw(int height);
int recursive_draw(int height);

int main(void)
{
    int draw_method = tolower(get_char("Choose pyramide draw method: Recusive or Iteration (R/I): "));
    
    if (draw_method == 'r')
    {
        int height = get_int("Height: ");
        int recursive_return_code = recursive_draw(height);
        printf("Recursive Pyramide exit code: %d\n", recursive_return_code);
    }
    else if (draw_method == 'i')
    {
        int height = get_int("Height: ");
        int iteration_return_code = iteration_draw(height);
        printf("Iteration Pyramide exit code: %d\n", iteration_return_code);
    }
    else 
    {
        printf("Exit.\n");
        return 1;
    }

    return 0;
}

int iteration_draw(int height)
{
    if (height < 1)
    {
        return 1;
    }

    for (size_t i = 0; i < height; i++)
    {
        for (size_t j = 0; j < i+1; j++)
        {
            printf("#");
        }
        printf("\n");
    }

    return 0;
}

int recursive_draw(int height)
{
    if (height < 1)
    {
        return 1;
    }
    if (height > 1) recursive_draw(height - 1);

    for (size_t i = 0; i < height; i++)
    {
        printf("#");
    }
    printf("\n");

    return 0;
}
