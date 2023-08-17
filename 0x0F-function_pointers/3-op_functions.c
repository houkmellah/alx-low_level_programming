#include "3-calc.h"

int op_add(int a, int b);
int op_sub(int a, int b);
int op_mul(int a, int b);
int op_div(int a, int b);
int op_mod(int a, int b);

/**
* op_add - Computes sum of two integers.
* @a: First integer.
* @b: Second integer.
*
* Return: Sum of a and b.
*/
int op_add(int a, int b)
{
	return (a + b);
}

/**
* op_sub - Computes difference between two integers.
* @a: First integer.
* @b: Second integer.
*
* Return: Difference between a and b.
*/
int op_sub(int a, int b)
{
	return (a - b);
}

/**
* op_mul - Computes product of two integers.
* @a: First integer.
* @b: Second integer.
*
* Return: Product of a and b.
*/
int op_mul(int a, int b)
{
	return (a * b);
}

/**
* op_div - Computes division result of two integers.
* @a: Numerator.
* @b: Denominator.
*
* Return: Quotient of a divided by b.
*/
int op_div(int a, int b)
{
	return (a / b);
}

/**
* op_mod - Computes modulus of two integers.
* @a: Dividend.
* @b: Divisor.
*
* Return: Remainder when a is divided by b.
*/
int op_mod(int a, int b)
{
	return (a % b);
}
