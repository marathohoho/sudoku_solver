#include "functions.h"

int	valid_char(char check_me)
{
	if (check_me == '.')
		return (1);
	else if (check_me >= '1' && check_me <= '9')
		return (1);
	else
	{
		return (0);
	}

}

int	array_length(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	create_matrix(char **argv, char table[9][9])
{
	int	i;
	int j;

	i = 1;
	while (i < 10)
	{
		if (array_length(argv[i]) != 9)
			return (0);
		j = 0;
		while (j < 9)
		{
			if (!valid_char(argv[i][j]))
				return (0);
			table[i - 1][j] = argv[i][j];
			j++;
		}
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	char	sudoku_table[9][9];

	if (argc != 10)
		return (write(1, "Error1\n", 6));
	if (!create_matrix(argv, sudoku_table))
		return (write(1, "Error2\n", 6));
	return (solve(sudoku_table));
}
