/*
** main.c for main in /home/gastal_r/rendu/dante/bonus/sources
** 
** Made by 
** Login   <gastal_r@epitech.net>
** 
** Started on  Wed May  4 04:43:11 2016 
** Last update Sat May 28 10:03:47 2016 
*/

#include "bonus.h"

t_bunny_response mainloop(void *_data)
{
  t_data        *data;

  data =_data;
  aff_all(data);
  bunny_display(data->win);
  return (GO_ON);
}

void		init_values(t_data *data)
{
  data->prof.opt = 0;
  data->gen.value = 0;
  data->gen.check = 0;
  data->prof.check = 0;
  data->prof.essais = 0;
  data->menu.prof = 0;
  data->larg.check = 0;
  data->larg.essais = 0;
  data->menu.larg = 0;
  data->ast.check = 0;
  data->ast.essais = 0;
  data->menu.ast = 0;
  init_generateur(data);
  data->gen.fond_pos.x = 0;
  data->gen.fond_pos.y = 0;
  data->prof.path = x_blp("pictures/profondeur.jpg");
  data->prof.path_essais = x_blp("pictures/profondeur_essais.jpg");
  data->larg.path = x_blp("pictures/largeur.jpg");
  data->larg.path_essais = x_blp("pictures/largeur_essais.jpg");
  data->ast.path = x_blp("pictures/astar.jpg");
  data->ast.path_essais = x_blp("pictures/astar_essais.jpg");
  data->menu.menu_fond = x_blp("pictures/menu.png");
  data->menu.checkbox = x_blp("pictures/check_g.png");
  bb(wb, data->gen.fond, &data->gen.fond_pos);
  bb(wb, data->menu.menu_fond, &data->gen.fond_pos);
}

void		free_all(t_data *data)
{
  int		i;

  i = 0;
  if (data->gen.value == 1)
  while (data->maze[i] != NULL)
    {
      free(data->maze[i]);
      free(data->maze_p[i]);
      free(data->maze_l[i]);
      free(data->maze_a[i]);
    }
}

int		main()
{

  t_data	data;
  t_bunny_music	*music;

  music = bunny_load_music("pictures/music.ogg");
  bunny_sound_play(&music->sound);
  data.win = bunny_start(1920, 1080, true, "Dante");
  bunny_set_move_response(response_move);
  bunny_set_click_response(response_click);
  bunny_set_key_response(response_key);
  bunny_set_loop_main_function((t_bunny_loop)mainloop);
  init_values(&data);
  bunny_loop(data.win, 60, &data);
  bunny_stop(data.win);
  bunny_delete_sound(&music->sound);
  free_all(&data);
  return (0);
}
