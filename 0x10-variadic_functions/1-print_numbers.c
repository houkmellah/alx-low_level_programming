#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_numbers - Outputs numbers, followed by a newline.
 * @sep: String printed between numbers.
 * @num: Count of integers supplied to the function.
 * @...: Variable list of numbers for printing.
 */
void print_numbers(const char *sep, const unsigned int num, ...)
{
	va_list number_list;
	unsigned int idx;

	va_start(number_list, num);

	for (idx = 0; idx < num; idx++)
	{
		printf("%d", va_arg(number_list, int));

		if (idx != (num - 1) && sep != NULL)
			printf("%s", sep);
	}

	printf("\n");

	va_end(number_list);
}
