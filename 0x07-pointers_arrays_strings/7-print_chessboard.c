#include "main.h"
/**
 * print_chessboard - Print the chessboard represented by the 2D array.
 * @a: The 2D array representing the chessboard.
 *
 * Return: void (no return value).
 */
void print_chessboard(char (*a)[8])
{
int row, column;

for (row = 0; row < 8; row++)
{
for (column = 0; column < 8; column++)
_putchar(a[row][column]);
_putchar('\n');
}
}
