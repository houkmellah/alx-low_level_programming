#include "function_pointers.h"
#include <stdlib.h>
#include <stdio.h>
#include "3-calc.h"

/**
 * main - Prints the result of basic calculations.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: Always 0.
 */
int main(int __attribute__((__unused__)) arg_count, char *arg_values[])
{
int first_number, second_number;
char *operator_sign;

if (arg_count != 4)
{
printf("Error\n");
exit(98);
}

first_number = atoi(arg_values[1]);
operator_sign = arg_values[2];
second_number = atoi(arg_values[3]);

if (get_op_func(operator_sign) == NULL || operator_sign[1] != '\0')
{
printf("Error\n");
exit(99);
}

if ((*operator_sign == '/' && second_number == 0) ||
(*operator_sign == '%' && second_number == 0))
{
printf("Error\n");
exit(100);
}

printf("%d\n", get_op_func(operator_sign)(first_number, second_number));

return (0);
}
