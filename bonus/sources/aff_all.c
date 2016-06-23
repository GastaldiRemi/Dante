/*
** aff_all.c for aff_all in /home/gastal_r/rendu/dante/bonus
** 
** Made by 
** Login   <gastal_r@epitech.net>
** 
** Started on  Thu May 12 11:57:22 2016 
** Last update Sun May 22 04:10:42 2016 
*/

#include "bonus.h"
#include "profondeur.h"

void            aff_path(t_data *data)
{
  int           i;
  int           j;

  i = 0;
  j = 0;
  data->gen.wall_pos.x = 20;
  data->gen.wall_pos.y = 20;
  while (data->maze_p[j] != NULL)
    {
      while (data->maze_p[j][i])
	{
	  if (data->prof.check == 1 && data->maze_p[j][i] == 'o')
	    bb(wb, data->prof.path, &data->gen.wall_pos);
	  if (data->larg.check == 1 && data->maze_l[j][i] == 'o')
	    bb(wb, data->larg.path, &data->gen.wall_pos);
	  if (data->ast.check == 1 && data->maze_a[j][i] == 'o')
	    bb(wb, data->ast.path, &data->gen.wall_pos);
	  i++;
	  data->gen.wall_pos.x += 15;
	}
      data->gen.wall_pos.x = 20;
      data->gen.wall_pos.y += 15;
      i = 0;
      j++;
    }
}

void            aff_essais(t_data *data, t_path **path, int x, int y)
{
  if (data->prof.essais == 1)
    {
      data->prof.essais_pos.x = (((*path)->x) * 15) + 20;
      data->prof.essais_pos.y = (((*path)->y) * 15) + 20;
      data->prof.path_essais->color_mask.argb[3] = 230;
      bb(wb, data->prof.path_essais, &data->prof.essais_pos);
    }
  else if (data->larg.essais == 1)
    {
      data->prof.essais_pos.x = (((*path)->x) * 15) + 20;
      data->prof.essais_pos.y = (((*path)->y) * 15) + 20;
      data->larg.path_essais->color_mask.argb[3] = 230;
      bb(wb, data->larg.path_essais, &data->prof.essais_pos);
    }
  else if (data->ast.essais == 1)
    {
      data->ast.path_essais->color_mask.argb[0] = data->h * -1;
      data->ast.path_essais->color_mask.argb[1] = data->h * -2;
      data->ast.path_essais->color_mask.argb[2] = data->h * -2;
      data->ast.path_essais->color_mask.argb[3] = 230;
      data->prof.essais_pos.x = x * 15 + 20;
      data->prof.essais_pos.y = y * 15 + 20;
      bb(wb, data->ast.path_essais, &data->prof.essais_pos);
    }
  bunny_display(data->win);
  (data->prof.essais == 1 ? usleep(6000) : 0);
  (data->ast.essais == 1 ? usleep(2000) : 0);
}

void		aff_all3(t_data *data)
{
  if (data->ast.essais == 1)
    {
      data->menu.check.x = 1744;
      data->menu.check.y = 866;
      bb(wb, data->menu.checkbox, &data->menu.check);
    }
  if (data->gen.check == 1)
    {
      aff_maze(data);
      aff_border(data, 0);
    }
  if (data->gen.check == 1)
    aff_path(data);
}

void            aff_all2(t_data *data)
{
  if (data->larg.check == 1)
    {
      data->menu.check.x = 1820;
      data->menu.check.y = 711;
      bb(wb, data->menu.checkbox, &data->menu.check);
    }
  if (data->larg.essais == 1)
    {
      data->menu.check.x = 1744;
      data->menu.check.y = 752;
      bb(wb, data->menu.checkbox, &data->menu.check);
    }
  if (data->ast.check == 1)
    {
      data->menu.check.x = 1820;
      data->menu.check.y = 816;
      bb(wb, data->menu.checkbox, &data->menu.check);
    }
  aff_all3(data);
}

void            aff_all(t_data *data)
{
  bb(wb, data->menu.menu_fond, &data->gen.fond_pos);
  if (data->gen.parfait == 1)
    {
      data->menu.check.x = 1820;
      data->menu.check.y = 270;
      bb(wb, data->menu.checkbox, &data->menu.check);
    }
  if (data->prof.check == 1)
    {
      data->menu.check.x = 1820;
      data->menu.check.y = 560;
      bb(wb, data->menu.checkbox, &data->menu.check);
    }
  if (data->prof.essais == 1)
    {
      data->menu.check.x = 1744;
      data->menu.check.y = 605;
      bb(wb, data->menu.checkbox, &data->menu.check);
    }
  if (data->prof.opt == 1)
    {
      data->menu.check.x = 1760;
      data->menu.check.y = 650;
      bb(wb, data->menu.checkbox, &data->menu.check);
    }
  aff_all2(data);
}
