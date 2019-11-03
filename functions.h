#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <unistd.h>

char	create_matrix(char **argv, char table[9][9]);
int		array_length(char *str);
int		valid_char(char check_me);
int		solve(char solve_me[9][9]);
int		print_table(char sudoku[9][9]);
int		backtrack(char sudoku[9][9]);
int		unique_in_box(char c, int i, int j, char sudoku[9][9]);
int		unique_in_column(char c, int j, char sudoku[9][9]);
int		unique_in_row(char c, int i, char sudoku[9][9]);
int		char_is_unique(char c, int i, int j, char sudoku[9][9]);
int		empty_cell_exists(int *i, int *j, char sudoku[9][9]);

#endif
