#include "main.h"
/**
* binary_to_uint - Transforms binary string to unsigned int.
* @b: Binary string.
* Return: Transformed unsigned int.
*/
unsigned int binary_to_uint(const char *binStr) {
int idx;
unsigned int uintVal = 0;
if (!binStr)
return 0;
for (idx = 0; binStr[idx]; idx++) {
if (binStr[idx] < '0' || binStr[idx] > '1')
return 0;
uintVal = 2 * uintVal + (binStr[idx] - '0');
}
return uintVal;
}
