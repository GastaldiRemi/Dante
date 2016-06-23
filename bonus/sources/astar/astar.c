/*
** main.c for main in /home/gastal_r/rendu/dante/sources/astar
** 
** Made by 
** Login   <gastal_r@epitech.net>
** 
** Started on  Wed May  4 15:49:27 2016 
** Last update Thu May 12 12:30:17 2016 
*/

#include	"astar.h"
#include	"bonus.h"

void    free_fonc_a(t_list *open, t_list *closed)
{
  t_list        *curr;

  while ((curr = open) != NULL)
    {
      open = open->next;
      free (curr);
    }
  while ((curr = closed) != NULL)
    {
      closed = closed->next;
      free (curr);
    }
}

int		astar(t_data *data)
{
  t_list	*closed;
  t_list	*open;

  closed = NULL;
  open = NULL;
  find_path_a(data, data->maze_a, &closed, &open);
  free_fonc_a(open, closed);
  return (0);
}
