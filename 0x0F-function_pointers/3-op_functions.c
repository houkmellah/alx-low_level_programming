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
#include "3-calc.h"

int op_add(int a, int b);
int op_sub(int a, int b);
int op_mul(int a, int b);
int op_div(int a, int b);
int op_mod(int a, int b);

/**
 * op_add - Returns the sum of two numbers.
 * @a: The first number.
 * @b: The second number.
 *
 * Return: The sum of a and b.
 */
int op_add(int a, int b)
{
	return (a + b);
}
/**
 * op_sub - Returns the difference of two numbers.
 * @a: The first number.
 * @b: The second number.
 *
 * Return: The difference of a and b.
 */
int op_sub(int a, int b)
{
	return (a - b);
}
/**
 * op_mul - Returns the product of two numbers.
 * @a: The first number.
 * @b: The second number.
 *
 * Return: The product of a and b.
 */
int op_mul(int a, int b)
{
	return (a * b);
}
/**
 * op_div - Returns the division of two numbers.
 * @a: The first number.
 * @b: The second number.
 *
 * Return: The quotient of a and b.
 */
int op_div(int a, int b)
{
	return (a / b);
}
/**
 * op_mod - Returns the remainder of the division of two numbers.
 * @a: The first number.
 * @b: The second number.
 *
 * Return: The remainder of the division of a by b.
 */
int op_mod(int a, int b)
{
	return (a % b);
}
