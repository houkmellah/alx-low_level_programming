#ifndef CALC_H
#define CALC_H

/**
* struct op - A data structure.
* @operator: The operator.
* @func: The function linked to the operator.
*/
typedef struct op
{
char *operator;
int (*func)(int x, int y);
} op_t;

int op_add(int x, int y);
int op_sub(int x, int y);
int op_mul(int x, int y);
int op_div(int x, int y);
int op_mod(int x, int y);
int (*get_op_func(char *symbol))(int, int);

#endif
