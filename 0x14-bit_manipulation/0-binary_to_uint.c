#include "main.h"

/**
 * convert_bin_to_uint - transforme un nombre binaire en unsigned int
 * @binary: chaîne contenant le nombre binaire
 *
 * Return: le nombre converti
 */
unsigned int convert_bin_to_uint(const char *binary)
{
int index;
unsigned int decimal_value = 0;

if (!binary)
return (0);

for (index = 0; binary[index]; index++)
{
if (binary[index] < '0' || binary[index] > '1')
return (0);
decimal_value = 2 * decimal_value + (binary[index] - '0');
}

return (decimal_value);
}
