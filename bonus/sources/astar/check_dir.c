/*
** check_dir.c for check_dir in /home/gastal_r/rendu/dante/sources/astar
** 
** Made by 
** Login   <gastal_r@epitech.net>
** 
** Started on  Thu May  5 12:29:48 2016 
** Last update Sat May 21 23:44:54 2016 
*/

#include "astar.h"

int		check_up_a(t_data *data, t_list **closed,
			   t_list **open, t_node *node)
{
  if (node->y - 1 < 0)
    return (0);
  if (data->maze_a[node->y - 1][node->x] != '*')
    return (0);
  if (check_closed_list((*closed), node->x, node->y - 1) == -1 ||
      check_open_list((*open), node->x, node->y - 1) == -1)
    return (0);
  node->cout++;
  add_node(open, node, node->x, node->y - 1);
  if (data->ast.essais == 1)
    {
      data->h = (*open)->h - (*open)->cout;
      aff_essais(data, NULL, node->x, node->y -1);
    }
  node->cout--;
  return (0);
}

int		check_right_a(t_data *data, t_list **closed,
			      t_list **open, t_node *node)
{
  if (node->x + 1 >= node->width)
    return (0);
  if (data->maze_a[node->y][node->x + 1] != '*')
    return (0);
  if (check_closed_list((*closed), node->x + 1, node->y) == -1 ||
      check_open_list((*open), node->x + 1, node->y) == -1)
    return (0);
  node->cout++;
  add_node(open, node, node->x + 1, node->y);
  if (data->ast.essais == 1)
    {
      data->h = (*open)->h - (*open)->cout;
      aff_essais(data, NULL, node->x + 1, node->y);
    }
  node->cout--;
  return (0);
}

int		check_down_a(t_data *data, t_list **closed,
			     t_list **open, t_node *node)
{
  if (node->y + 1 >= node->length)
    return (0);
  if (data->maze_a[node->y + 1][node->x] != '*')
    return (0);
  if (check_closed_list((*closed), node->x, node->y + 1) == -1 ||
      check_open_list((*open), node->x, node->y + 1) == -1)
    return (0);
  node->cout++;
  add_node(open, node, node->x, node->y + 1);
  if (data->ast.essais == 1)
    {
      data->h = (*open)->h - (*open)->cout;
      aff_essais(data, NULL, node->x, node->y + 1);
    }
  node->cout--;
  return (0);
}

int		check_left_a(t_data *data, t_list **closed,
			     t_list **open, t_node *node)
{
  if (node->x - 1 < 0)
    return (0);
  if (data->maze_a[node->y][node->x - 1] != '*')
    return (0);
  if (check_closed_list((*closed), node->x - 1, node->y) == -1 ||
      check_open_list((*open), node->x - 1, node->y) == -1)
    return (0);
  node->cout++;
  add_node(open, node, node->x - 1, node->y);
  if (data->ast.essais == 1)
    {
      data->h = (*open)->h - (*open)->cout;
      aff_essais(data, NULL, node->x - 1, node->y);
    }
  node->cout--;
  return (0);
}

int		check_dir_a(t_data *data, t_list **closed,
			    t_list **open, t_node *node)
{
  check_up_a(data, closed, open, node);
  check_right_a(data, closed, open, node);
  check_down_a(data, closed, open, node);
  check_left_a(data, closed, open, node);
  return (0);
}
