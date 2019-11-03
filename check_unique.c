#include "functions.h"

int unique_in_box(char c, int i, int j, char sudoku[9][9])
{
	int	i_end;
	int j_end;
	int j_temp;

	i = (i / 3) * 3;
	j = (j / 3) * 3;
	i_end = i + 3;
	j_end = j + 3;
	j_temp = j;
	while (i < i_end)
	{
		j = j_temp;
		while (j < j_end)
		{
			if (sudoku[i][j] == c)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int unique_in_column(char c, int j, char sudoku[9][9])
{
	int i;

	i = 0;
	while (i < 9)
	{
		if (sudoku[i][j] == c)
			return (0);
		i++;
	}
	return (1);
}

int unique_in_row(char c, int i, char sudoku[9][9])
{
	int j;

	j = 0;
	while (j < 9)
	{
		if (sudoku[i][j] == c)
			return (0);
		j++;
	}
	return (1);
}

int	char_is_unique(char c, int i, int j, char sudoku[9][9])
{
	if (!unique_in_column(c, j, sudoku))
		return (0);
	if (!unique_in_row(c, i, sudoku))
		return (0);
	if (!unique_in_box(c, i, j, sudoku))
		return (0);
	return (1);
}
