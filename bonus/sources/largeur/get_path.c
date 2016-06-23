/*
** get_path.c for get_path in /home/gastal_r/rendu/dante/sources/largeur
**
** Made by
** Login   <gastal_r@epitech.net>
**
** Started on  Mon May  2 21:27:29 2016
** Last update Mon May  9 23:44:30 2016 
*/

#include "largeur.h"

void	init_data(char **maze, t_path **path, t_check *data)
{
  data->first = 1;
  data->width = get_width(maze[0]);
  data->length = get_length(maze);
  data->x = 0;
  data->y = 0;
  add_coor_l(path, data, 0, 0);
}

void	get_path(char **maze, t_path **path, t_check *data)
{
  int	from_x;
  int	from_y;

  maze[0][0] = 'o';
  maze[data->length - 1][data->width - 1] = 'o';
  from_x = (*path)->from_x;
  from_y = (*path)->from_y;
  while ((*path)->x != 0 || (*path)->y != 0)
    {

      if ((*path)->y == from_y && (*path)->x == from_x)
	{
	  maze[(*path)->y][(*path)->x] = 'o';
	  from_x = (*path)->from_x;
	  from_y = (*path)->from_y;
	}
      *path = (*path)->prev;
    }
}

int	find_path_l(t_data *bonus, char **maze, t_path **path)
{
  t_check	data;

  init_data(maze, path, &data);
  while ((*path)->x != data.width - 1 || (*path)->y != data.length -1)
    {
      maze[(*path)->y][(*path)->x] = 'M';
      (bonus->larg.essais == 1 ? aff_essais(bonus, path, 0, 0) : (void)0);
      data.x = (*path)->x;
      data.y = (*path)->y;
      check_case_l(maze, path, &data);
      if ((*path) == NULL)
	{
	  puts("No solution found");
	  return (0);
	}
      *path = (*path)->next;
      (*path)->current = 1;
    }
  get_path(maze, path, &data);
  return (0);
}
