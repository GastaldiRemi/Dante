/*
** gen_waze_size.c for gen_waze_size in /home/gastal_r/rendu/dante/sources
** 
** Made by remi gastal_r
** Login   <gastal_r@epitech.net>
** 
** Started on  Tue Apr 26 15:32:19 2016 remi gastal_r
** Last update Sun May  8 10:07:34 2016 
*/

#include "bonus.h"

void	put_value(int **maze, t_data *data, int value, int replace)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (j < data->gen.length)
    {
      while (i < data->gen.width)
	{
	  (maze[j][i] == value ? maze[j][i] = replace : 0);
	  i++;
	}
      i = 0;
      j++;
    }
}

void	pick_random_case(int **maze, t_data *data)
{
  int	x;
  int	y;

  x = rand()%(data->gen.width - 1);
  y = rand()%(data->gen.length - 1);
  (x % 2 == 1 ? x++ : 0);
  (y % 2 == 1 ? y++ : 0);
  check_case_g(maze, x, y, data);
}

int	check_end(int **maze, t_data *data)
{
  int	tmp;
  int	i;
  int	j;

  i = 0;
  j = 0;
  tmp = maze[0][2];
  while (j < data->gen.length)
    {
      while (i < data->gen.width)
	{
	  if (maze[j][i] != 0)
	    if (maze[j][i] != tmp)
	      return (0);
	  i++;
	}
      i = 0;
      j++;
    }
  return (1);
}

int	**gen_maze_size(t_data *data)
{
  int	i;
  int	**maze;

  maze = NULL;
  i = data->gen.width - 1;
  srand(time(NULL));
  maze = init_maze(maze, data);
  generate_wall(maze, data);
  while (check_end(maze, data) == 0)
    pick_random_case(maze, data);
  maze[data->gen.length - 1][data->gen.width - 1] =  1;
  while (maze[data->gen.length -  2][i] == 0)
    {
      maze[data->gen.length - 1][i - 1] = 1;
      i--;
    }
  (data->gen.parfait == 0 ? break_wall(maze, data) : (void)0);
  (data->gen.length % 2 == 0 ? break_length(maze, data) : (void)0);
  (data->gen.width % 2 == 0 ? break_width(maze, data) : (void)0);
  write_maze(maze, data);
  return (maze);
}
