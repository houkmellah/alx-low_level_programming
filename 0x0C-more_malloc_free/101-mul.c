#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#define ERR_MSG "Error"
/**
* is_digit - checks for non-digit in string
* @str: string to check
*
* Return: 0 if non-digit found, 1 otherwise
*/
int is_digit(char *str)
{
int index = 0;
while (str[index])
{
if (str[index] < '0' || str[index] > '9')
return (0);
index++;
}
return (1);
}
/**
* _strlen - finds string length
* @str: string to evaluate
*
* Return: string length
*/
int _strlen(char *str)
{
int index = 0;
while (str[index] != '\0')
{
index++;
}
return (index);
}
/**
* errors - handles errors for main function
*/
void errors(void)
{
printf("Error\n");
exit(98);
}
/**
* main - multiplies two positive numbers
* @argc: argument count
* @argv: argument vector
*
* Return: 0 (Success)
*/
int main(int argc, char *argv[])
{
char *num1, *num2;
int lenNum1, lenNum2, totalLen, index, overflow;
int val1, val2, *mulResult, flag = 0;
num1 = argv[1], num2 = argv[2];
if (argc != 3 || !is_digit(num1) || !is_digit(num2))
errors();
lenNum1 = _strlen(num1);
lenNum2 = _strlen(num2);
totalLen = lenNum1 + lenNum2 + 1;
mulResult = malloc(sizeof(int) * totalLen);
if (!mulResult)
return (1);
for (index = 0; index <= lenNum1 + lenNum2; index++)
mulResult[index] = 0;
for (lenNum1 = lenNum1 - 1; lenNum1 >= 0; lenNum1--)
{
val1 = num1[lenNum1] - '0';
overflow = 0;
for (lenNum2 = _strlen(num2) - 1; lenNum2 >= 0; lenNum2--)
{
val2 = num2[lenNum2] - '0';
overflow += mulResult[lenNum1 + lenNum2 + 1] + (val1 *val2);
mulResult[lenNum1 + lenNum2 + 1] = overflow % 10;
overflow /= 10;
}
if (overflow > 0)
mulResult[lenNum1 + lenNum2 + 1] += overflow;
}
for (index = 0; index < totalLen - 1; index++)
{
if (mulResult[index])
flag = 1;
if (flag)
_putchar(mulResult[index] + '0');
}
if (!flag)
_putchar('0');
_putchar('\n');
free(mulResult);
return (0);
}
