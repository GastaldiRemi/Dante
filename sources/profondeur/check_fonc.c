/*
** check_fonc.c for check_fonc in /home/gastal_r/rendu/dante/sources/profondeur
** 
** Made by remi gastal_r
** Login   <gastal_r@epitech.net>
** 
** Started on  Sun May  1 00:37:09 2016 remi gastal_r
** Last update Sat May 14 22:03:01 2016 
*/

#include "profondeur.h"

int     check_path(t_path *path, int y, int x)
{
  while (path->prev != NULL)
    {
      if (path->x == x && path->y == y)
        return (0);
      path = path->prev;
    }
  return (1);
}

void    check_node(char **maze, t_path **path, t_check *check)
{
  int   node;

  node = 0;
  if ((*path)->y - 1 >= 0)
    if (maze[(*path)->y - 1][(*path)->x] == '*')
      node++;
  if ((*path)->x + 1 < check->width)
    if (maze[(*path)->y][(*path)->x + 1] == '*')
      node++;
  if ((*path)->y + 1 < check->length)
    if (maze[(*path)->y + 1][(*path)->x] == '*')
      node++;
  if ((*path)->x - 1 >= 0)
    if (maze[(*path)->y][(*path)->x - 1] == '*')
      node++;
  if (node >= 3)
    (*path)->node = 1;
  else
    (*path)->node = 0;
}

int     check_remove(char**maze, t_path **path, t_check *check)
{
  check->check = -1;
  if ((*path)->node == 1)
    {
      maze[(*path)->y][(*path)->x] = 'R';
      remove_last(path);
    }
  while ((*path)->node != 1 && ((*path)->x != 0 || (*path)->y != 0))
    {
      maze[(*path)->y][(*path)->x] = 'R';
      remove_last(path);
    }
  return (0);
}

int     check_case(char **maze, t_path **path, t_check *check)
{
  check_node(maze, path, check);
  check->check++;
  if (check->check == 0)
    check_down(maze, path, check);
  if (check->check == 1)
    check_right(maze, path, check);
  if (check->check == 2)
    check_up(maze, path, check);
  if (check->check == 3)
    check_left(maze, path, check);
  if (check->check == 4)
    return (check_remove(maze, path, check));
  check->check = -1;
  return (0);
}
