#include "main.h"
#include <stdlib.h>

/**
 * alloc_grid - Creates a 2D array (grid) with specified width and height.
 * @width: Width input.
 * @height: Height input.
 *
 * Return: Pointer to the 2D array, or NULL if alloc fails or inp are invalid.
 */
int **alloc_grid(int width, int height)
{
	int **mee;
	int x, y;

	if (width <= 0 || height <= 0)
		return (NULL);

	mee = malloc(sizeof(int *) * height);

	if (mee == NULL)
		return (NULL);

	for (x = 0; x < height; x++)
	{
		mee[x] = malloc(sizeof(int) * width);

		if (mee[x] == NULL)
		{
			for (; x >= 0; x--)
				free(mee[x]);

			free(mee);
			return (NULL);
		}
	}

	for (x = 0; x < height; x++)
	{
		for (y = 0; y < width; y++)
			mee[x][y] = 0;
	}

	return (mee);
}
