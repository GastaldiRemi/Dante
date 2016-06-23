/*
** check_dir.c for check_dir in /home/gastal_r/rendu/dante/sources/astar
** 
** Made by 
** Login   <gastal_r@epitech.net>
** 
** Started on  Thu May  5 12:29:48 2016 
** Last update Fri May 13 16:22:17 2016 
*/

#include "astar.h"

int		check_up(char **maze, t_list **closed,
			 t_list **open, t_data *node)
{
  if (node->y - 1 < 0 || maze[node->y - 1][node->x] != '*')
    return (0);
  if (check_closed_list((*closed), node, node->x, node->y - 1) == -1 ||
      check_open_list((*open), node, node->x, node->y - 1) == -1)
    return (0);
  node->cout++;
  add_node(open, node, node->x, node->y - 1);
  node->cout--;
  return (0);
}

int		check_right(char **maze, t_list **closed,
			    t_list **open, t_data *node)
{
  if (node->x + 1 >= node->width || maze[node->y][node->x + 1] != '*')
    return (0);
  if (check_closed_list((*closed), node, node->x + 1, node->y) == -1 ||
      check_open_list((*open), node, node->x + 1, node->y) == -1)
    return (0);
  node->cout++;
  add_node(open, node, node->x + 1, node->y);
  node->cout--;
  return (0);
}

int		check_down(char **maze, t_list **closed,
			   t_list **open, t_data *node)
{
  if (node->y + 1 >= node->length || maze[node->y + 1][node->x] != '*')
    return (0);
  if (check_closed_list((*closed), node, node->x, node->y + 1) == -1 ||
      check_open_list((*open), node, node->x, node->y + 1) == -1)
    return (0);
  node->cout++;
  add_node(open, node, node->x, node->y + 1);
  node->cout--;
  return (0);
}

int		check_left(char **maze, t_list **closed,
			   t_list **open, t_data *node)
{
  if (node->x - 1 < 0 || maze[node->y][node->x - 1] != '*')
    return (0);
  if (check_closed_list((*closed), node, node->x - 1, node->y) == -1 ||
      check_open_list((*open), node, node->x - 1, node->y) == -1)
    return (0);
  node->cout++;
  add_node(open, node, node->x - 1, node->y);
  node->cout--;
  return (0);
}

int		check_dir(char **maze, t_list **closed,
			  t_list **open, t_data *node)
{
  check_up(maze, closed, open, node);
  check_right(maze, closed, open, node);
  check_down(maze, closed, open, node);
  check_left(maze, closed, open, node);
  return (0);
}
