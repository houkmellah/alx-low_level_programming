#include "3-calc.h"

int op_add(int num1, int num2);
int op_sub(int num1, int num2);
int op_mul(int num1, int num2);
int op_div(int num1, int num2);
int op_mod(int num1, int num2);

/**
 * op_add - Calculate sum of two integers.
 * @num1: First integer.
 * @num2: Second integer.
 * Return: Sum of num1 and num2.
 */
int op_add(int num1, int num2)
{
	return (num1 + num2);
}

/**
 * op_sub - Calculate difference between two integers.
 * @num1: First integer.
 * @num2: Second integer.
 * Return: Difference between num1 and num2.
 */
int op_sub(int num1, int num2)
{
	return (num1 - num2);
}

/**
 * op_mul - Calculate product of two integers.
 * @num1: First integer.
 * @num2: Second integer.
 * Return: Product of num1 and num2.
 */
int op_mul(int num1, int num2)
{
	return (num1 * num2);
}

/**
 * op_div - Calculate quotient of two integers.
 * @num1: First integer.
 * @num2: Second integer.
 * Return: Quotient of num1 by num2.
 */
int op_div(int num1, int num2)
{
	return (num1 / num2);
}

/**
 * op_mod - Calculate remainder after dividing two integers.
 * @num1: First integer.
 * @num2: Second integer.
 * Return: Remainder of num1 divided by num2.
 */
int op_mod(int num1, int num2)
{
	return (num1 % num2);
}
