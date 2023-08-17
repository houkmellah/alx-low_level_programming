#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_strings - Displays strings, followed by a newline.
 * @sep: String used between displayed strings.
 * @num_strings: Count of strings given to the function.
 * @...: Variable list of strings for display.
 *
 * Note: If sep is NULL, it's not displayed.
 *       If any of the strings is NULL, (nil) is shown in its place.
 */
void print_strings(const char *sep, const unsigned int num_strings, ...)
{
	va_list str_list;
	char *current_str;
	unsigned int idx;

	va_start(str_list, num_strings);

	for (idx = 0; idx < num_strings; idx++)
	{
		current_str = va_arg(str_list, char *);

		if (current_str == NULL)
			printf("(nil)");
		else
			printf("%s", current_str);

		if (idx != (num_strings - 1) && sep != NULL)
			printf("%s", sep);
	}

	printf("\n");

	va_end(str_list);
}
