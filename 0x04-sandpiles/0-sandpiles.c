#include "sandpiles.h"

/**
 * sandpiles_sum - stabilize 2 sand piles trhough addition
 * @grid1: pile 1
 * @grid2: pile 2
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i;
	int j;

	for (i = 0; i < len; i++)
	{
		for (j = 0; j < len; j++)
			grid1[i][j] += grid2[i][j];
	}

	while (ifunstable(grid1, grid2))
	{
		printf("=\n");
		i = 0;
		while (i < len)
		{
			for (j = 0; j < len; j++)
				printf((j == len - 1) ? "%d\n" : "%d ", grid1[i][j]);
			i++;
		}
		for (i = 0; i < len; i++)
		{
			for (j = 0; j < len; j++)
			{
				if (grid2[i][j] > 3)
				{
					grid1[i][j] -= 4;
					if (i > 0)
						++grid1[i - 1][j];
					if (i < len - 1)
						++grid1[i + 1][j];
					if (j > 0)
						++grid1[i][j - 1];
					if (j < len - 1)
						++grid1[i][j + 1];
				}
			}
		}
	}
}

/**
 * ifunstable - Checks if a sandpile is unstable
 * @grid: sandpile
 * @backup: copy of sandpile to check
 * Return: 1 if unstable 0 if stable
 */
int ifunstable(int grid[3][3], int backup[3][3])
{
	int i = 0;
	int j;
	int unstable = 0;

	while (i < len)
	{
		for (j = 0; j < len; j++)
		{
			backup[i][j] = grid[i][j];
			if (backup[i][j] > 3)
				unstable = 1;
		}
		i++;
	}

	return (unstable);
}
