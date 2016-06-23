/*
** check_case.c for check_case in /home/gastal_r/rendu/dante/sources/maze
** 
** Made by remi gastal_r
** Login   <gastal_r@epitech.net>
** 
** Started on  Fri Apr 29 10:59:43 2016 remi gastal_r
** Last update Fri Apr 29 23:46:36 2016 gastal_r
*/

#include "generateur.h"

void    check_nbr0(int **maze, int x, int y, t_data *data)
{
  if (y - 2 > 0)
    {
      if (maze[y][x] != maze[y - 2][x] && maze[y - 2][x] != 0)
        {
          maze[y - 1][x] = maze[y][x];
          put_value(maze, data, maze[y - 2][x], maze[y][x]);
        }
    }
  else
    check_case(maze, x, y, data);
}

void    check_nbr1(int **maze, int x, int y, t_data *data)
{
  if (x + 2 < data->width)
    {
      if (maze[y][x] != maze[y][x + 2]  && maze[y][x + 2] != 0)
        {
          maze[y][x + 1] = maze[y][x];
          put_value(maze, data, maze[y][x + 2], maze[y][x]);
        }
    }
  else
    check_case(maze, x, y, data);
}

void    check_nbr2(int **maze, int x, int y, t_data *data)
{
  if (y + 2 < data->length)
    {
      if (maze[y][x] != maze[y + 2][x] && maze[y + 2][x] != 0)
        {
          maze[y + 1][x] = maze[y][x];
          put_value(maze, data, maze[y + 2][x], maze[y][x]);
        }
    }
  else
    check_case(maze, x, y, data);
}

void    check_nbr3(int **maze, int x, int y, t_data *data)
{
  if (x - 2 > 0)
    {
      if (maze[y][x] != maze[y][x - 2] && maze[y][x - 2] != 0)
        {
          maze[y][x - 1] = maze[y][x];
          put_value(maze, data, maze[y][x - 2], maze[y][x]);
        }
    }
  else
    check_case(maze, x, y, data);
}

void    check_case(int **maze, int x, int y, t_data *data)
{
  int   nbr;

  nbr = rand()%4;
  if (nbr == 0)
    check_nbr0(maze, x, y, data);
  else if (nbr == 1)
    check_nbr1(maze, x, y, data);
  else if (nbr == 2)
    check_nbr2(maze, x, y, data);
  else if (nbr == 3)
    check_nbr3(maze, x, y, data);
}
