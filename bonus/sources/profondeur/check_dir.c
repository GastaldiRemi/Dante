/*
** check_dir.c for check_dir in /home/gastal_r/rendu/dante/sources/profondeur
** 
** Made by remi gastal_r
** Login   <gastal_r@epitech.net>
** 
** Started on  Sun May  1 00:34:40 2016 remi gastal_r
** Last update Mon May 16 18:37:32 2016 
*/

#include "profondeur.h"

int     check_up(t_data *data, char **maze, t_path **path, t_check *check)
{
  if (data->prof.opt == 0)
    {
      if (check->up == 1)
	return (check_case(data, maze, path, check));
      check->up = 1;
    }
  if ((*path)->prev->y == (*path)->y - 1)
    return (check_case(data, maze, path, check));
  if ((*path)->y - 1 >= 0)
    {
      if (maze[(*path)->y - 1][(*path)->x] == '*')
        {
          if (check_path(*path, (*path)->y - 1, (*path)->x) == 0)
            return (check_case(data, maze, path, check));
          add_coor(path, (*path)->x, (*path)->y - 1);
	  (data->prof.essais == 1 ? aff_essais(data, path, 0, 0) : (void)0);
        }
      else
        check_case(data, maze, path, check);
    }
  else
    check_case(data, maze, path, check);
  return (0);
}

int     check_right(t_data *data, char **maze, t_path **path, t_check *check)
{
  if (data->prof.opt == 0)
    {
      if (check->right == 1)
	return (check_case(data, maze, path, check));
      check->right = 1;
    }
  if ((*path)->prev->x == (*path)->x + 1)
    return (check_case(data, maze, path, check));
  if ((*path)->x + 1 <= check->width - 1)
    {
      if (maze[(*path)->y][(*path)->x + 1] == '*')
        {
          if (check_path(*path, (*path)->y, (*path)->x  + 1) == 0)
            return (check_case(data, maze, path, check));
          add_coor(path, (*path)->x + 1, (*path)->y);
	  (data->prof.essais == 1 ? aff_essais(data, path, 0, 0) : (void)0);
        }
      else
        check_case(data, maze, path, check);
    }
  else
    check_case(data, maze, path, check);
  return (0);
}

int     check_down(t_data *data, char **maze, t_path **path, t_check *check)
{
  if (data->prof.opt == 0)
    {
      if (check->down == 1)
	return (check_case(data, maze, path, check));
      check->down = 1;
    }
  if ((*path)->prev->y == (*path)->y + 1)
    return (check_case(data, maze, path, check));
  if ((*path)->y + 1 <= check->length - 1)
    {
      if (maze[(*path)->y + 1][(*path)->x] == '*')
        {
          if (check_path(*path, (*path)->y + 1, (*path)->x) == 0)
            return (check_case(data, maze, path, check));
          add_coor(path, (*path)->x, (*path)->y + 1);
	  (data->prof.essais == 1 ? aff_essais(data, path, 0, 0) : (void)0);
        }
      else
        check_case(data, maze, path, check);
    }
  else
    check_case(data, maze, path, check);
  return (0);
}

int     check_left(t_data *data, char **maze, t_path **path, t_check *check)
{
  if (data->prof.opt == 0)
    {
      if (check->left == 1)
	return (check_case(data, maze, path, check));
      check->left = 1;
    }
  if ((*path)->prev->x == (*path)->x - 1)
    return (check_case(data, maze, path, check));
  if ((*path)->x - 1 >= 0)
    {
      if (maze[(*path)->y][(*path)->x  - 1] == '*')
        {
          if (check_path(*path, (*path)->y, (*path)->x  - 1) == 0)
            return (check_case(data, maze, path, check));
          add_coor(path, (*path)->x - 1, (*path)->y);
	  (data->prof.essais == 1 ? aff_essais(data, path, 0, 0) : (void)0);
        }
      else
        check_case(data, maze, path, check);
    }
  else
    check_case(data, maze, path, check);
  return (0);
}
