#include "3-calc.h"
#include <stdlib.h>

/**
* get_op_func - Choose the right function for user's operation.
* @op_ch: Operator given as input.
*
* Return: Pointer to the matching function based on input operator.
*/
int (*get_op_func(char *op_ch))(int, int)
{
op_t operations[] = {
{"+", op_add},
{"-", op_sub},
{"*", op_mul},
{"/", op_div},
{"%", op_mod},
{NULL, NULL}
};

int idx = 0;

while (operations[idx].op != NULL && *(operations[idx].op) != *op_ch)
idx++;

return (operations[idx].f);
}
