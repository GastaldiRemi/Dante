/*
** generateur.c for generateur in /home/gastal_r/rendu/dante/bonus/sources
** 
** Made by 
** Login   <gastal_r@epitech.net>
** 
** Started on  Sun May  8 02:36:10 2016 
** Last update Tue May 10 22:08:15 2016 
*/

#include	"bonus.h"

char		**maze_cp(t_data *data, char **dest, char **src)
{
  int   i;
  int	j;

  j = 0;
  i = -1;
  if ((dest = malloc(sizeof(char *) * (data->gen.length + 1))) == NULL)
    exit (0);
  while (++i < data->gen.length)
    dest[i] = malloc(sizeof(char) * (data->gen.width + 1));
  i = 0;
  while (j < data->gen.length)
    {
      while (i < data->gen.width)
	{
	  dest[j][i] = src[j][i];
	  i++;
	}
      dest[j][i] = '\0';
      i = 0;
      j++;
    }
  dest[j] = NULL;
  return (dest);
}

void		init_generateur(t_data *data)
{
  data->gen.parfait = 0;
  data->gen.width = 97;
  data->gen.length = 67;
  data->gen.fond_pos.x = 0;
  data->gen.fond_pos.y = 0;
  data->gen.fond = x_blp("pictures/generateur.jpg");
  data->gen.wall= x_blp("pictures/wall.jpg");
}

void		aff_maze(t_data *data)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  data->gen.wall_pos.x = 20;
  data->gen.wall_pos.y = 20;
  while (data->maze[j] != NULL)
    {
      while (data->maze[j][i])
	{
	  if (data->maze[j][i] != '*')
	    bb(wb, data->gen.wall, &data->gen.wall_pos);
	  i++;
	  data->gen.wall_pos.x += 15;
	}
      data->gen.wall_pos.x = 20;
      data->gen.wall_pos.y += 15;
      i = 0;
      j++;
    }
}

void		generate(t_data *data)
{
  gen_maze_size(data);
  data->maze_p = maze_cp(data, data->maze_p, data->maze);
  data->maze_l = maze_cp(data, data->maze_l, data->maze);
  data->maze_a = maze_cp(data, data->maze_a, data->maze);
  aff_maze(data);
}
