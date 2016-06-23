/*
** bunny_response.c for bunny_response in /home/gastal_r/rendu/gfx/gfx_tekadventure/Remi
** 
** Made by remi gastal_r
** Login   <gastal_r@epitech.net>
** 
** Started on  Tue Apr 12 15:07:45 2016 remi gastal_r
** Last update Wed May 11 00:49:13 2016 
*/

#include "bonus.h"

t_bunny_response response_key(t_bunny_event_state              state,
                              t_bunny_keysym                   sym,
                              void                             *_data)
{
  t_data *data;

  data = _data;
  (void)data;
  (void)state;
  (void)sym;
  if (bunny_get_keyboard()[BKS_ESCAPE] == 1)
    return (0);
  return (GO_ON);
}

t_bunny_response response_click(t_bunny_event_state state,
                                t_bunny_mousebutton button,
                                void *_data)
{
  t_data *data;

  data = _data;
  (void)state;
  (void)button;
  (void)data;
  if (bunny_get_mouse_button()[BMB_LEFT] == 1)
    menu_click(data);
  return (GO_ON);
}

t_bunny_response response_move(const t_bunny_position *relative,
                               void *_data)
{
  t_data *data;

  (void)relative;
  data = _data;
  data->mouse = bunny_get_mouse_position();
  return (GO_ON);
}
