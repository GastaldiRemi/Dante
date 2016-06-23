/*
** list_fonc.c for list_fonc in /home/gastal_r/rendu/CPE_2015/CPE_2015_Lemin/remi
** 
** Made by remi gastal_r
** Login   <gastal_r@epitech.net>
** 
** Started on  Tue Apr 19 19:00:03 2016 remi gastal_r
** Last update Tue May 10 00:04:14 2016 
*/

#include "largeur.h"

int            add_coor_l(t_path **path, t_check *data, int y, int x)
{
  t_path        *new;

  if ((new = malloc(sizeof(t_path))) == NULL)
    return (0);
  while ((*path) != NULL && (*path)->next != NULL)
    (*path) = (*path)->next;
  new->next = NULL;
  new->current = 0;
  if (data->first == 1)
    {
      new->current = 1;
      data->first = 0;
    }
  new->prev = *path;
  new->from_x = data->x;
  new->from_y = data->y;
  new->x = x;
  new->y = y;
  if ((*path) != NULL)
    (*path)->next = new;
  (*path) = new;
  while ((*path)->current != 1)
    *path = (*path)->prev;
  return (0);
}
