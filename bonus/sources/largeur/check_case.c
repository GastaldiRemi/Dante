/*
** check_case.c for check_case in /home/gastal_r/rendu/dante/sources/largeur
** 
** Made by 
** Login   <gastal_r@epitech.net>
** 
** Started on  Tue May  3 11:32:04 2016 
** Last update Mon May  9 23:44:12 2016 
*/

#include "largeur.h"

int     check_up_l(char **maze, t_path **path, t_check *data)
{
  if ((*path)->y - 1 < 0)
    return (0);
  if (maze[(*path)->y - 1][(*path)->x] == '*')
    add_coor_l(path, data, (*path)->y - 1, (*path)->x);
  return (0);
}

int     check_right_l(char **maze, t_path **path, t_check *data)
{
  if ((*path)->x + 1 >= data->width)
    return (0);
  if (maze[(*path)->y][(*path)->x + 1] == '*')
    add_coor_l(path, data, (*path)->y, (*path)->x + 1);
  return (0);
}

int     check_down_l(char **maze, t_path **path, t_check *data)
{
  if ((*path)->y + 1 >= data->length)
    return (0);
  if (maze[(*path)->y + 1][(*path)->x] == '*')
    add_coor_l(path, data, (*path)->y + 1, (*path)->x);
  return (0);
}

int     check_left_l(char **maze, t_path **path, t_check *data)
{
  if ((*path)->x - 1 < 0)
    return (0);
  if (maze[(*path)->y][(*path)->x - 1] == '*')
    add_coor_l(path, data, (*path)->y, (*path)->x - 1);
  return (0);
}

int     check_case_l(char **maze, t_path **path, t_check *data)
{
  check_up_l(maze, path, data);
  check_right_l(maze, path, data);
  check_down_l(maze, path, data);
  check_left_l(maze, path, data);
  return (0);
}
