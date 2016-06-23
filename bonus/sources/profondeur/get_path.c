/*
** check_case.c for check_case in /home/gastal_r/rendu/dante/sources/profondeur
** 
** Made by remi gastal_r
** Login   <gastal_r@epitech.net>
** 
** Started on  Sat Apr 30 15:36:00 2016 remi gastal_r
** Last update Mon May 16 18:28:39 2016 
*/

#include "profondeur.h"

void	aff_tab(char **maze)
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

void	init_fonc(char **maze, t_check *check, t_path **path)
{
  check->check = -1;
  check->up = 0;
  check->right = 0;
  check->down = 0;
  check->left = 0;
  check->width = get_width(maze[0]);
  check->length = get_length(maze);
  add_coor(path, 0, 0);
  add_coor(path, 0, 0);
  srand(time(NULL));
}

int	find_path(t_data *data, char **maze, t_path **path)
{
  t_check	check;
  int		end;

  end = 0;
  init_fonc(maze, &check, path);
  while ((*path)->x != check.width - 1 || (*path)->y != check.length - 1)
    {
      check_case(data, maze, path, &check);
      if ((*path)->x == 0 && (*path)->y == 0)
	end++;
      if (end == 2)
      	{
      	  puts("NO SOLUTION");
      	  exit(0);
      	}
    }
  aff_finalmaze(maze, *path);
  return (0);
}
