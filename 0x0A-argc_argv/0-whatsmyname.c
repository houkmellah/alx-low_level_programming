# include <stdio.h>

/**
* main - this function will print the name of program followed by a new line
*@argc : count the argument
*@argv : list the values of arguments
*Return: 0 if is succed
*/

int main(int argc, char const *argv[])
{
(void)argc;
printf("%s", argv[0]);
return (0);
}
