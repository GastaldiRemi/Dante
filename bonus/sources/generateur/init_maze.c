/*
** init_maze.c for init_maze in /home/gastal_r/rendu/dante/sources/maze
** 
** Made by remi gastal_r
** Login   <gastal_r@epitech.net>
** 
** Started on  Fri Apr 29 11:34:42 2016 remi gastal_r
** Last update Sun May  8 03:11:49 2016 
*/

#include "bonus.h"

int     **init_maze(int **maze, t_data *data)
{
  int   i;

  i = 0;
  if ((maze = malloc(sizeof(int *) * data->gen.length)) == NULL)
    exit(0);
  while (i < data->gen.length)
    {
      if ((maze[i] = malloc(sizeof(int) * data->gen.width)) == NULL)
        exit(0);
      i++;
    }
  return (maze);
}

void    init_wall(int **maze, t_data *data)
{
  int   i;
  int   j;

  j = 0;
  i = 0;
  while (j < data->gen.length)
    {
      while (i < data->gen.width)
        {
          maze[j][i] = 0;
          i++;
        }
      i = 0;
      j++;
    }
}

void    generate_wall(int **maze, t_data *data)
{
  int   i;
  int   j;
  int   nbr;

  nbr = 1;
  i = 0;
  j = 0;
  while (i < data->gen.length)
    {
      while (j < data->gen.width)
        {
          if (i % 2 == 0)
            {
              ((j % 2 == 1) ? (maze[i][j] = 0) : (maze[i][j] = nbr));
              (j % 2 == 1 ? nbr++ : 0);
            }
	  else
	    maze[i][j] = 0;
          j++;
        }
      (data->gen.width % 2 == 1 ?
       (i % 2 == 0 ? nbr++ : 0) : 0);
      j = 0;
      i++;
    }
}
