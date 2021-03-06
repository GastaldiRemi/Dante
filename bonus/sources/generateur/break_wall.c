/*
** break_wall.c for break_wall in /home/gastal_r/rendu/dante/sources/maze/imperfect
** 
** Made by remi gastal_r
** Login   <gastal_r@epitech.net>
** 
** Started on  Fri Apr 29 11:52:53 2016 remi gastal_r
** Last update Thu May 12 12:00:23 2016 
*/

#include "bonus.h"

int	count_wall(int *maze, t_data *data)
{
  int	i;
  int	nbr;

  nbr = 0;
  i = 1;
  while (i < data->gen.width)
    {
      (maze[i] == 0 ? nbr++ : 0);
      i++;
    }
  return (nbr);
}

int	break_one(int *maze, t_data *data)
{
  int	nbr;
  int	i;
  int	wall;

  wall = -1;
  i = 0;
  nbr = count_wall(maze, data);
  if (nbr == 0)
    return (0);
  nbr = rand() % nbr;
  if (maze[i] == 0 && nbr == 0)
    {
      maze[i] = 1;
      return (0);
    }
  while (wall != nbr)
    {
      (maze[i] == 0 ? wall++ : 0);
      i++;
    }
  maze[i - 1] = 1;
  return (0);
}

void	break_length(int **maze, t_data *data)
{
  int	i;

  i = 0;
  while (i < data->gen.width -1)
    {
      if (data->gen.parfait == 1)
	(maze[data->gen.length - 2][i] != 0 ?
	 maze[data->gen.length - 1][i] = 1 : 0);
      else
	(maze[data->gen.length - 3][i] != 0 ?
	 maze[data->gen.length - 1][i] = 1 : 0);
      i++;
    }
}

void	break_width(int **maze, t_data *data)
{
  int	j;

  j = 0;
  while (j < data->gen.length -1)
    {
      if (data->gen.parfait == 1)
	(maze[j][data->gen.width - 3] != 0 ? maze[j][data->gen.width - 1] = 1 : 0);
      else
	(maze[j][data->gen.width - 3] != 0 ? maze[j][data->gen.width - 1] = 1 : 0);
      j++;
    }
}

void	break_wall(int **maze, t_data *data)
{
  int	j;

  j = 1;
  while (j < data->gen.length)
    {
      break_one(maze[j], data);
      j++;
    }
}
