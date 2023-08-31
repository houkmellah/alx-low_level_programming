#include "main.h"
/**
* binary_to_uint - Transforms binary string to unsigned int.
* @b: Binary string.
* Return: Transformed unsigned int.
*/
unsigned int binary_to_uint(const char *b)
{
int idx;
unsigned int uintVal = 0;
if (!b)
return (0);
for (idx = 0; b[idx]; idx++)
{
if (b[idx] < '0' || b[idx] > '1')
return (0);
uintVal = 2 * uintVal + (b[idx] - '0');
}
return (uintVal);
}
