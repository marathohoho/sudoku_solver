#include "functions.h"

int	empty_cell_exists(int *i, int *j, char sudoku[9][9])
{
	int x;
	int y;

	x = 0;
	while (x < 9)
	{
		y = 0;
		while (y < 9)
		{
			if (sudoku[x][y] == '.')
			{
				*i = x;
				*j = y;
				return (1);
			}
			y++;
		}
		x++;
	}
	return (0);
}

int	backtrack(char sudoku[9][9])
{
	int		i;
	int		j;
	char	c;

	if (!empty_cell_exists(&i, &j, sudoku))
		return (1);
	c = '1';
	while (c <= '9')
	{
		if(char_is_unique(c, i, j, sudoku))
		{
			sudoku[i][j] = c;
			if (backtrack(sudoku))
				return (1);
			else
			{
				sudoku[i][j] = '.';
			}
		}
		c++;
	}
	return (0);
}

int	print_table(char sudoku[9][9])
{
	int	i;
	int	j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			write (1, &sudoku[i][j], 1);
			if (j < 8)
				write (1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	return (0);
}

int	solve(char solve_me[9][9])
{
	if (!backtrack(solve_me))
		return (write(1, "Error3\n", 6));
	return (print_table(solve_me));
}
