/*
** menu.c for menu in /home/gastal_r/rendu/dante/bonus/sources
** 
** Made by 
** Login   <gastal_r@epitech.net>
** 
** Started on  Tue May 10 20:40:29 2016 
** Last update Sun May 22 04:10:01 2016 
*/

#include	"bonus.h"

void		aff_border(t_data *data, int i)
{
  data->gen.wall->color_mask.argb[0] = 255;
  data->gen.wall->color_mask.argb[1] = 150;
  data->gen.wall->color_mask.argb[2] = 150;
  while (i < data->gen.width + 2)
    {
      data->gen.wall_pos.y = 5;
      data->gen.wall_pos.x = 15 * i + 5;
      bb(wb, data->gen.wall, &data->gen.wall_pos);
      data->gen.wall_pos.y = (data->gen.length) * 15 + 20;
      bb(wb, data->gen.wall, &data->gen.wall_pos);
      i++;
    }
  i = 0;
  while (i < data->gen.length + 1)
    {
      data->gen.wall_pos.x = 5;
      data->gen.wall_pos.y = 15 * i + 5;
      bb(wb, data->gen.wall, &data->gen.wall_pos);
      data->gen.wall_pos.x = (data->gen.width * 15 + 20);
      bb(wb, data->gen.wall, &data->gen.wall_pos);
      i++;
    }
  data->gen.wall->color_mask.argb[1] = 255;
  data->gen.wall->color_mask.argb[2] = 255;
  data->gen.wall->color_mask.argb[3] = 255;
}

void		menu_click3(t_data *data)
{
  if ((data->mouse->x > 1746 && data->mouse->x < 1777) &&
      (data->mouse->y > 878 && data->mouse->y < 907))
    {
      (data->ast.essais == 1 ? data->ast.essais = 0 : (data->ast.essais = 1));
      (data->menu.ast == 1 ? data->menu.ast = 0 : (data->menu.ast = 1));
    }
  if ((data->mouse->x > 1544 && data->mouse->x < 1859) &&
      (data->mouse->y > 937 && data->mouse->y < 980) && data->gen.check == 1)
    {
      data->maze_p = maze_cp(data, data->maze_p, data->maze);
      data->maze_l = maze_cp(data, data->maze_l, data->maze);
      data->maze_a = maze_cp(data, data->maze_a, data->maze);
      bb(wb, data->gen.fond, &data->gen.fond_pos);
      aff_all(data);
      (data->prof.check == 1 ? profondeur(data) : 0);
      data->prof.essais = 0;
      (data->larg.check == 1 ? largeur(data) : 0);
      data->larg.essais = 0;
      (data->ast.check == 1 ? astar(data) : 0);
      (data->menu.prof == 1 ? data->prof.essais = 1 : 0);
      (data->menu.larg == 1 ? data->larg.essais = 1 : 0);
      (data->menu.ast == 1 ? data->ast.essais = 1 : 0);
    }
}

void		menu_click2(t_data *data)
{
  if ((data->mouse->x > 1818 && data->mouse->x < 1876) &&
      (data->mouse->y > 558 && data->mouse->y < 613))
    (data->prof.check == 1 ? data->prof.check = 0 : (data->prof.check = 1));
  if ((data->mouse->x > 1762 && data->mouse->x < 1793) &&
      (data->mouse->y > 661 && data->mouse->y < 690))
    (data->prof.opt == 1 ? data->prof.opt = 0 : (data->prof.opt = 1));
  if ((data->mouse->x > 1745 && data->mouse->x < 1775) &&
      (data->mouse->y > 617 && data->mouse->y < 645))
    {
      (data->prof.essais == 1 ?
       data->prof.essais = 0 : (data->prof.essais = 1));
      (data->menu.prof == 1 ? data->menu.prof = 0 : (data->menu.prof = 1));
    }
  if ((data->mouse->x > 1817 && data->mouse->x < 1873) &&
      (data->mouse->y > 709 && data->mouse->y < 765))
    (data->larg.check == 1 ? data->larg.check = 0 : (data->larg.check = 1));
  if ((data->mouse->x > 1745 && data->mouse->x < 1777) &&
      (data->mouse->y > 763 && data->mouse->y < 792))
    {
      (data->larg.essais == 1 ?
       data->larg.essais = 0 : (data->larg.essais = 1));
      (data->menu.larg == 1 ? data->menu.larg = 0 : (data->menu.larg = 1));
    }
  if ((data->mouse->x > 1817 && data->mouse->x < 1875) &&
      (data->mouse->y > 813 && data->mouse->y < 867))
    (data->ast.check == 1 ? data->ast.check = 0 : (data->ast.check = 1));
  menu_click3(data);
}

void		menu_click(t_data *data)
{
  if ((data->mouse->x > 1610 && data->mouse->x < 1640) &&
      (data->mouse->y > 217 && data->mouse->y < 249) && data->gen.width > 10)
    {
      data->gen.width -= 10;
      data->gen.length -= 7;
    }
  if ((data->mouse->x > 1759 && data->mouse->x < 1792) &&
      (data->mouse->y > 219 && data->mouse->y < 2250) && data->gen.width < 97)
    {
      data->gen.width += 10;
      data->gen.length += 7;
    }
  if ((data->mouse->x > 1817 && data->mouse->x < 1875) &&
      (data->mouse->y > 268 && data->mouse->y < 322))
    (data->gen.parfait == 1 ? data->gen.parfait = 0 : (data->gen.parfait = 1));
  if ((data->mouse->x > 1563 && data->mouse->x < 1841) &&
      (data->mouse->y > 368 && data->mouse->y < 407))
    {
      bb(wb, data->gen.fond, &data->gen.fond_pos);
      generate(data);
      data->gen.check = 1;
    }
  menu_click2(data);
}
