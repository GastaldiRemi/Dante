/*
** my.h for my in /home/gastal_r/rendu/dante
** 
** Made by remi gastal_r
** Login   <gastal_r@epitech.net>
** 
** Started on  Tue Apr 26 14:28:45 2016 remi gastal_r
** Last update Sun May  8 01:37:35 2016 
*/

#ifndef _GENERATEUR_H_
# define _GENERATEUR_H_

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

typedef struct	s_data
{
  int		length;
  int		width;
  int		parfait;
  int		start;
}		t_data;

/* Function(s) in file break_wall.c */
void		break_wall(int **wall, t_data *data);
int		break_one(int *maze, t_data *data);
int		count_wall(int *maze, t_data *data);
void		break_length(int **maze, t_data *data);
void		break_width(int **maze, t_data *data);

/* Function(s) in file write_maze.c */
int		write_maze(int **maze, t_data *data);

/* Function(s) in file main.c */
void		free_fonc(int **maze, t_data *data);
int		main(int ac, char *av[]);

/* Function(s) in file check_case.c */
void		check_nbr0(int **maze, int x, int y, t_data *data);
void		check_nbr1(int **maze, int x, int y, t_data *data);
void		check_nbr2(int **maze, int x, int y, t_data *data);
void		check_nbr3(int **maze, int x, int y, t_data *data);
void		check_case(int **maze, int x, int y, t_data *data);

/* Function(s) in file gen_maze_size.c */
void		show_tab(int **maze);
void		show_convert_tab(int **maze);
int		**init_maze(int **maze, t_data *data);
void		init_wall(int **maze, t_data *data);
void		generate_wall(int **maze, t_data *data);
void		put_value(int **maze, t_data *data, int value, int replace);
void		pick_random_case(int **maze, t_data *data);
int		check_end(int **maze, t_data *data);
int		**gen_maze_size(t_data *data);

	/* LIB */
char		*get_next_line(const int fd);
void		my_printf(char *format, ...);
int		my_getnbr(char *);

#endif /*_GENERATEUR_H_*/
