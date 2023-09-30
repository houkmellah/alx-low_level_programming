#include "main.h"

/**
 * binary_to_uint - transforme un nombre binaire en unsigned int
 * @binary: chaîne contenant le nombre binaire
 *
 * Return: le nombre converti
 */
unsigned int binary_to_uint(const char *b)
{
int index;
unsigned int decimal_value = 0;

if (!b)
return (0);

for (index = 0; b[index]; index++)
{
if (b[index] < '0' || b[index] > '1')
return (0);
decimal_value = 2 * decimal_value + (b[index] - '0');
}

return (decimal_value);
}
