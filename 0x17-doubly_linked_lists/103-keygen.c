#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Generates and prints passwords for the crackme5 executable.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: Always 0.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
char password[7], *codex;
int input_len = strlen(argv[1]), i, calc_val;

codex = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";

calc_val = (input_len ^ 59) & 63;
password[0] = codex[calc_val];

calc_val = 0;
for (i = 0; i < input_len; i++)
calc_val += argv[1][i];
password[1] = codex[(calc_val ^ 79) & 63];

calc_val = 1;
for (i = 0; i < input_len; i++)
calc_val *= argv[1][i];
password[2] = codex[(calc_val ^ 85) & 63];

calc_val = 0;
for (i = 0; i < input_len; i++)
{
if (argv[1][i] > calc_val)
calc_val = argv[1][i];
}
srand(calc_val ^ 14);
password[3] = codex[rand() & 63];

calc_val = 0;
for (i = 0; i < input_len; i++)
calc_val += (argv[1][i] * argv[1][i]);
password[4] = codex[(calc_val ^ 239) & 63];

for (i = 0; i < argv[1][0]; i++)
calc_val = rand();
password[5] = codex[(calc_val ^ 229) & 63];

password[6] = '\0';
printf("%s", password);
return (0);
}
