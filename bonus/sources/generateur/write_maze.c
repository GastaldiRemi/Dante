/*
** write_maze.c for write_maze in /home/gastal_r/rendu/dante/sources/maze
** 
** Made by remi gastal_r
** Login   <gastal_r@epitech.net>
** 
** Started on  Fri Apr 29 00:13:49 2016 remi gastal_r
** Last update Sun May  8 06:39:38 2016 
*/

#include "bonus.h"

void	init_maze_tab(t_data *data)
{
  int	i;

  i = -1;
  if ((data->maze = malloc(sizeof(char *) * (data->gen.length + 1))) == NULL)
    exit (0);
  while (++i < data->gen.length)
    data->maze[i] = malloc(sizeof(char) * (data->gen.width + 1));
}

int	write_maze(int **maze, t_data *data)
{
  int   i;
  int   j;

  j = 0;
  i = 0;
  init_maze_tab(data);
  while (i < data->gen.length)
    {
      while (j < data->gen.width)
        {
          if (maze[i][j] == 0)
	    data->maze[i][j] = 'X';
	  else
	    data->maze[i][j] = '*';
          j++;
        }
      data->maze[i][j] = '\0';
      j = 0;
      i++;
    }
  data->maze[i]= NULL;
  return (0);
}
