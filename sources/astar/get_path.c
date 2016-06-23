/*
** get_path.c for get_path in /home/gastal_r/rendu/dante/sources/astar
** 
** Made by 
** Login   <gastal_r@epitech.net>
** 
** Started on  Wed May  4 17:41:38 2016 
** Last update Fri May 27 15:00:25 2016 
*/

#include "astar.h"

void		init_path(char **maze, t_data *data)
{
  data->p_x = 0;
  data->p_y = 0;
  data->x = 0;
  data->y = 0;
  data->width = get_width(maze[0]);
  data->length = get_length(maze);
  data->cout = 0.0;
  data->h = data->cout + my_sqrt(my_pow(((data->width - 1) - data->x), 2)
				 + my_pow(((data->length - 1) - data->y), 2));
}

void		get_less_h(t_list **open, t_data *node)
{
  float		h;
  t_list	*tmp;

  tmp = *open;
  h = tmp->h;
  while (tmp->prev != NULL)
    {
      if (tmp->h < h)
	h = tmp->h;
      tmp = tmp->prev;
    }
  remove_node(open, node, h);
}

void		calc_final_path(char **maze, t_list **closed)
{
  int		tmp_x;
  int		tmp_y;

  tmp_x = (*closed)->x;
  tmp_y = (*closed)->y;
  while ((*closed)->prev != NULL)
    {
      if ((*closed)->x == tmp_x && (*closed)->y == tmp_y)
	{
	  maze[tmp_y][tmp_x] = 'o';
	  tmp_x = (*closed)->p_x;
	  tmp_y = (*closed)->p_y;
	}
      *closed = (*closed)->prev;
    }
  aff_tab(maze);
}

int		find_path(char **maze, t_list **closed, t_list **open)
{
  t_data	node;

  init_path(maze, &node);
  add_node(open, &node, node.x, node.y);
  add_node_c(closed, &node);
  while ((*open))
  {
    get_less_h(open, &node);
    if (node.x == node.width - 1 && node.y == node.length -1)
      {
	add_node_c(closed, &node);
	calc_final_path(maze, closed);
	return (0);
      }
    check_dir(maze, closed, open, &node);
    add_node_c(closed, &node);
  }
  dprintf(2, "No solution found\n");
  return (0);
}
