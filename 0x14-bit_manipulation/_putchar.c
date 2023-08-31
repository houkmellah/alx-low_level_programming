#include "main.h"
#include <unistd.h>

/**
* _putchar - Outputs the char c to stdout.
* @c: Char to display.
* 
* Return: 1 if successful, -1 if error occurs.
*/
int _putchar(char c)
{
	return (write(1, &c, 1));
}

