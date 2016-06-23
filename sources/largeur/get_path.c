/*
** get_path.c for get_path in /home/gastal_r/rendu/dante/sources/largeur
**
** Made by
** Login   <gastal_r@epitech.net>
**
** Started on  Mon May  2 21:27:29 2016
** Last update Fri May 27 15:02:27 2016 
*/

#include "largeur.h"

void    aff_tab(char **maze)
{
  int   i;
  int   j;

  j = 0;
  i = 0;
  while (maze[j] != NULL)
    {
      while (maze[j][i])
	{
	  (maze[j][i] == 'X' ? printf("%c", maze[j][i]) :
	   (maze[j][i] == 'o' ? printf("%c", maze[j][i]) :
	    printf("*")));
	  i++;
	}
      printf("\n");
      i= 0;
      j++;
    }
}

void	init_data(char **maze, t_path **path, t_data *data)
{
  data->first = 1;
  data->width = get_width(maze[0]);
  data->length = get_length(maze);
  data->x = 0;
  data->y = 0;
  add_coor(path, data, 0, 0);
}

void	get_path(char **maze, t_path **path, t_data *data)
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

int	find_path(char **maze, t_path **path)
{
  t_data	data;

  init_data(maze, path, &data);
  while ((*path)->x != data.width - 1 || (*path)->y != data.length -1)
    {
      maze[(*path)->y][(*path)->x] = 'M';
      data.x = (*path)->x;
      data.y = (*path)->y;
      check_case(maze, path, &data);
      *path = (*path)->next;
      if ((*path) == NULL)
	{
	  dprintf(2, "No solution found\n");
	  return (0);
	}
      (*path)->current = 1;
    }
  get_path(maze, path, &data);
  aff_tab(maze);
  return (0);
}
