#include <stdio.h>
#include <stdlib.h>

/**
* main - displays its own opcodes.
* @arg_count: number of arguments.
* @args: argument array.
*
* Return: Always 0 (Success).
*/
int main(int arg_count, char *args[])
{
int byte_count, index;
char *opcode_ptr;

if (arg_count != 2)
{
printf("Error\n");
exit(1);
}

byte_count = atoi(args[1]);

if (byte_count < 0)
{
printf("Error\n");
exit(2);
}

opcode_ptr = (char *)main;

for (index = 0; index < byte_count; index++)
{
if (index == byte_count - 1)
{
printf("%02hhx\n", opcode_ptr[index]);
break;
}
printf("%02hhx ", opcode_ptr[index]);
}
return (0);
}
