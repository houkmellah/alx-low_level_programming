#include "variadic_functions.h"
#include <stdarg.h>

/**
 * sum_them_all - Computes the total of all its arguments.
 * @num_args: Count of arguments provided to the function.
 * @...: A variable list of arguments for summation.
 *
 * Return: 0 if num_args == 0.
 *         Otherwise, the total of all arguments.
 */
int sum_them_all(const unsigned int num_args, ...)
{
	va_list args;
	unsigned int idx, total = 0;

	va_start(args, num_args);

	for (idx = 0; idx < num_args; idx++)
		total += va_arg(args, int);

	va_end(args);

	return (total);
}
