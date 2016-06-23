/*
** write_maze.c for write_maze in /home/gastal_r/rendu/dante/sources/maze
** 
** Made by remi gastal_r
** Login   <gastal_r@epitech.net>
** 
** Started on  Fri Apr 29 00:13:49 2016 remi gastal_r
** Last update Fri May 27 14:59:31 2016 
*/

#include "generateur.h"

void	aff_maze(int **maze, t_data *data)
{
  int	j;
  int	i;

  j = 0;
  i = 0;
  while (i < data->length)
    {
      (data->start == 1 ? write(1, "\n", 1) : (data->start = 1));
      while (j < data->width)
        {
          if (maze[i][j] == 0)
            write(1, "X", 1);
          else
            write(1, "*", 1);
          j++;
        }
      j = 0;
      i++;
    }
}

int	write_maze(int **maze, t_data *data)
{
  int	fd;
  int   i;
  int   j;

  j = 0;
  i = 0;
  if ((fd = open("maze.txt", O_WRONLY | O_TRUNC | O_CREAT, 0666)) == -1)
    return (0);
  while (i < data->length)
    {
      (data->start == 1 ? write(fd, "\n", 1) : (data->start = 1));
      while (j < data->width)
        {
          if (maze[i][j] == 0)
            write(fd, "X", 1);
          else
            write(fd, "*", 1);
          j++;
        }
      j = 0;
      i++;
    }
  data->start = 0;
  aff_maze(maze, data);
  return (0);
}
