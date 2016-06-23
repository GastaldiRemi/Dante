/*
** check_dir.c for check_dir in /home/gastal_r/rendu/dante/sources/profondeur
** 
** Made by remi gastal_r
** Login   <gastal_r@epitech.net>
** 
** Started on  Sun May  1 00:34:40 2016 remi gastal_r
** Last update Sat May 14 15:17:19 2016 
*/

#include "profondeur.h"

int     check_up(char **maze, t_path **path, t_check *check)
{
  if ((*path)->prev->y == (*path)->y - 1)
    return (check_case(maze, path, check));
  if ((*path)->y - 1 >= 0)
    {
      if (maze[(*path)->y - 1][(*path)->x] == '*')
        {
          if (check_path(*path, (*path)->y - 1, (*path)->x) == 0)
            return (check_case(maze, path, check));
          add_coor(path, (*path)->x, (*path)->y - 1);
        }
      else
        check_case(maze, path, check);
    }
  else
    check_case(maze, path, check);
  return (0);
}

int     check_right(char **maze, t_path **path, t_check *check)
{
  if ((*path)->prev->x == (*path)->x + 1)
    return (check_case(maze, path, check));
  if ((*path)->x + 1 <= check->width - 1)
    {
      if (maze[(*path)->y][(*path)->x + 1] == '*')
        {
          if (check_path(*path, (*path)->y, (*path)->x  + 1) == 0)
            return (check_case(maze, path, check));
          add_coor(path, (*path)->x + 1, (*path)->y);
        }
      else
        check_case(maze, path, check);
    }
  else
    check_case(maze, path, check);
  return (0);
}

int     check_down(char **maze, t_path **path, t_check *check)
{
  if ((*path)->prev->y == (*path)->y + 1)
    return (check_case(maze, path, check));
  if ((*path)->y + 1 <= check->length - 1)
    {
      if (maze[(*path)->y + 1][(*path)->x] == '*')
        {
          if (check_path(*path, (*path)->y + 1, (*path)->x) == 0)
            return (check_case(maze, path, check));
          add_coor(path, (*path)->x, (*path)->y + 1);
        }
      else
        check_case(maze, path, check);
    }
  else
    check_case(maze, path, check);
  return (0);
}

int     check_left(char **maze, t_path **path, t_check *check)
{
  if ((*path)->prev->x == (*path)->x - 1)
    return (check_case(maze, path, check));
  if ((*path)->x - 1 >= 0)
    {
      if (maze[(*path)->y][(*path)->x  - 1] == '*')
        {
          if (check_path(*path, (*path)->y, (*path)->x  - 1) == 0)
            return (check_case(maze, path, check));
          add_coor(path, (*path)->x - 1, (*path)->y);
        }
      else
        check_case(maze, path, check);
    }
  else
    check_case(maze, path, check);
  return (0);
}
