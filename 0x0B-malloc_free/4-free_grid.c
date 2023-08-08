#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * free_grid - Frees the memory allocated for a 2D array (grid).
 * @grid: The 2D array (grid) to be freed.
 * @height: The height dimension of the grid.
 *
 * Description: This function frees the memory allocated for a 2D array (grid).
 *
 * Return: Nothing (void).
 */
void free_grid(int **grid, int height)
{
	int i;

	for (i = 0; i < height; i++)
	{
		free(grid[i]);
	}
	free(grid);
}
