#include <stdio.h>

/**
 * main - causes a loop
 * Return: 0
 */
int main(void)
{
    int i;

    printf("Loop incoming :(\n");
    i = 0;
    while (i < 10)
    {
        putchar('0' + i);
        i++;
    }
    printf("\nLoop avoided! \\o/\n");
    return (0);
}
