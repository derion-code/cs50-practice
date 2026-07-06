#include <stdio.h>
#include <stdbool.h>

float average(int SIZE, int* numbers);
int get_int(char* prompt);
void print_int_array(int SIZE, int* arr);
void fill_int_array(int SIZE, int* arr);
int find_min(int SIZE, int* arr);
int find_max(int SIZE, int* arr);
bool contains(int SIZE, int* arr, int value);
bool confirm();

int main(void) {
    const int SCORES_SIZE = get_int("Enter size for list: ");
    if (SCORES_SIZE < 1)
    {
        printf("The size must be more than 0\n");
        return -1;
    }
    int scores[SCORES_SIZE];

    fill_int_array(SCORES_SIZE, scores);    
    print_int_array(SCORES_SIZE, scores);

    printf("Min score: %d\n", find_min(SCORES_SIZE, scores));
    printf("Max score: %d\n", find_max(SCORES_SIZE, scores));
    printf("Average: %0.2f\n", average(SCORES_SIZE, scores));
    if (confirm("Want to know if there is a specific score? (Y/n): "))
    {
        int score = get_int("Enter score: "); 
        if (contains(SCORES_SIZE, scores, score))
        {
            printf("The score exists in the list.\n");
        }
        else
        {
            printf("Score not found.\n");
        }
    }

    return 0;
}

float average(int SIZE, int* numbers)
{
    int sum = 0;
    for (int i = 0; i < SIZE; i++)
    {
        sum += numbers[i];
    }

    return sum / (float) SIZE;
}

int get_int(char* prompt)
{
    printf("%s", prompt);

    int value = 0;
    scanf("%d", &value);

    return value;
}

void print_int_array(int SIZE, int* arr)
{
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d - %d\n", i + 1, arr[i]);
    }
}

void fill_int_array(int SIZE, int* arr)
{
    for (int i = 0; i < SIZE; i++)
    {
        printf("Enter value for %d score: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

int find_min(int SIZE, int* arr)
{
    int min = arr[0];
    for (int i = 0; i < SIZE; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }

    return min;
}

int find_max(int SIZE, int* arr)
{
    int max = arr[0];
    for (int i = 0; i < SIZE; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    return max;
}

bool contains(int SIZE, int* arr, int value)
{
    for (int i = 0; i < SIZE; i++)
    {
        if (value == arr[i])
        {
            return true;
        }
    }
    return false;
}

bool confirm(char* prompt)
{
    printf("%s", prompt);
    char character;
    scanf(" %c", &character);
    if (character == 'y' || character == 'Y')
    {
        return true;
    }
    return false;
}
