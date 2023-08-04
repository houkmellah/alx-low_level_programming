#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
/**
 * check_num - Checks if the string contains only digits.
 * @str: The string to check.
 *
 * Return: 1 if the string contains only digits, 0 otherwise.
 */
int check_num(char *str)
{
    /* Declaring variables */
    unsigned int count;
    count = 0;
    
    while (count < strlen(str)) /* Count the characters in the string */
    {
        if (!isdigit(str[count])) /* Check if the string contains non-digit characters */
        {
            return (0);
        }
        count++;
    }
    return (1);
}

/**
 * main - Print the sum of the valid numbers in the arguments.
 * @argc: Count of arguments.
 * @argv: Array of arguments.
 *
 * Return: Always 0 (Success).
 */
int main(int argc, char *argv[])
{
    /* Declaring variables */
    int count;
    int str_to_int;
    int sum = 0;

    count = 1;
    while (count < argc) /* Go through the whole array of arguments */
    {
        if (check_num(argv[count]))
        {
            str_to_int = atoi(argv[count]); /* ATOI --> convert string to int */
            sum += str_to_int;
        }
        /* Condition if one of the numbers contains symbols that are not digits */
        else
        {
            printf("Error\n");
            return (1);
        }
        count++;
    }

    printf("%d\n", sum); /* Print the sum of valid numbers */
    return (0);
}
