/*
** main.c for dante in /home/gastal_r/rendu/dante/sources/profondeur
**
** Made by gastal_r
** Login   <gastal_r@epitech.net>
**
** Started on  Sat Apr 30 11:18:18 2016 gastal_r
** Last update Thu May 12 12:32:55 2016 
*/

#include "largeur.h"
#include "bonus.h"

void    free_fonc_l(t_path *path)
{
  t_path        *curr;

  while ((curr = path) != NULL)
    {
      path = path->next;
      free (curr);
    }
}

int		largeur(t_data *data)
{
  t_path	*path;

  path = NULL;
  find_path_l(data, data->maze_l, &path);
  free_fonc_l(path);
  return 0;
}
