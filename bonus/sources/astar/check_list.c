/*
** check_list.c for check_list in /home/gastal_r/rendu/dante/sources/astar
** 
** Made by 
** Login   <gastal_r@epitech.net>
** 
** Started on  Sat May  7 17:10:45 2016 
** Last update Sun May  8 00:54:35 2016 
*/

#include	"astar.h"

int		check_closed_list(t_list *closed, int x, int y)
{
  while (closed != NULL && closed->prev != NULL)
    {
      if (closed->x == x && closed->y == y)
	return (-1);
      closed = closed->prev;
    }
  return (0);
}

int		check_open_list(t_list *open, int x, int y)
{
  while (open != NULL && open->prev != NULL)
    {
      if (open->x == x && open->y == y)
	return (-1);
      open = open->prev;
    }
  return (0);
}
