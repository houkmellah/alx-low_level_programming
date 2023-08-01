#include "main.h"

/**
 * set_string - Sets the value of a pointer to a char.
 * @s: Pointer to pointer whose value needs to be changed.
 * @to: Pointer to char with the new value.
 */
void set_string(char **s, char *to)
{
*s = to;
}
