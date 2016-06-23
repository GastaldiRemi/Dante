/*
** check_case.c for check_case in /home/gastal_r/rendu/dante/sources/largeur
** 
** Made by 
** Login   <gastal_r@epitech.net>
** 
** Started on  Tue May  3 11:32:04 2016 
** Last update Sun May  8 01:05:21 2016 
*/

#include "largeur.h"

int     check_up(char **maze, t_path **path, t_data *data)
{
  if ((*path)->y - 1 < 0)
    return (0);
  if (maze[(*path)->y - 1][(*path)->x] == '*')
    add_coor(path, data, (*path)->y - 1, (*path)->x);
  return (0);
}

int     check_right(char **maze, t_path **path, t_data *data)
{
  if ((*path)->x + 1 >= data->width)
    return (0);
  if (maze[(*path)->y][(*path)->x + 1] == '*')
    add_coor(path, data, (*path)->y, (*path)->x + 1);
  return (0);
}

int     check_down(char **maze, t_path **path, t_data *data)
{
  if ((*path)->y + 1 >= data->length)
    return (0);
  if (maze[(*path)->y + 1][(*path)->x] == '*')
    add_coor(path, data, (*path)->y + 1, (*path)->x);
  return (0);
}

int     check_left(char **maze, t_path **path, t_data *data)
{
  if ((*path)->x - 1 < 0)
    return (0);
  if (maze[(*path)->y][(*path)->x - 1] == '*')
    add_coor(path, data, (*path)->y, (*path)->x - 1);
  return (0);
}

int     check_case(char **maze, t_path **path, t_data *data)
{
  check_up(maze, path, data);
  check_right(maze, path, data);
  check_down(maze, path, data);
  check_left(maze, path, data);
  return (0);
}
