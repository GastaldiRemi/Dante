/*
** main.c for main in /home/gastal_r/rendu/dante
** 
** Made by remi gastal_r
** Login   <gastal_r@epitech.net>
** 
** Started on  Tue Apr 26 14:24:52 2016 remi gastal_r
** Last update Mon May 30 17:13:40 2016 
*/

#include "generateur.h"

int	main(int ac, char *av[])
{
  t_data	data;

  if (ac < 3)
    {
      printf("Need two arguments\n");
      return (0);
    }
  if (ac == 4)
    ((strcmp(av[3], "parfait") == 0) ? data.parfait = 1 : 0);
  else
    data.parfait = 0;
  if (atol(av[1]) < 4 || atol(av[2]) < 4)
    {
      printf("Size is too low\n");
      return (0);
    }
  if (((data.length = atol(av[1])) >= 2147483647) ||
      ((data.width = atol(av[2])) >= 2147483647))
    return (0);
  data.start = 0;
  gen_maze_size( &data);
  return (0);
}
