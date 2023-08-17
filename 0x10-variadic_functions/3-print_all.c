#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_all - Outputs various data types based on a format string.
 * @fmt: A string dictating the types of subsequent arguments.
 */
void print_all(const char * const fmt, ...)
{
	int idx = 0;
	char *current_str, *delimiter = "";

	va_list args;

	va_start(args, fmt);

	if (fmt)
	{
		while (fmt[idx])
		{
			switch (fmt[idx])
			{
				case 'c':
					printf("%s%c", delimiter, va_arg(args, int));
					break;
				case 'i':
					printf("%s%d", delimiter, va_arg(args, int));
					break;
				case 'f':
					printf("%s%f", delimiter, va_arg(args, double));
					break;
				case 's':
					current_str = va_arg(args, char *);
					if (!current_str)
						current_str = "(nil)";
					printf("%s%s", delimiter, current_str);
					break;
				default:
					idx++;
					continue;
			}
			delimiter = ", ";
			idx++;
		}
	}

	printf("\n");
	va_end(args);
}
