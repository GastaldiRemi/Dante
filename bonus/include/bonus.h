/*
** bonus.h for bonus in /home/gastal_r/rendu/dante/bonus/include
** 
** Made by 
** Login   <gastal_r@epitech.net>
** 
** Started on  Wed May  4 04:32:12 2016 
** Last update Sun May 22 04:10:31 2016 
*/

#ifndef _BONUS_H_
# define _BONUS_H_

#include		<fcntl.h>
#include		<lapin.h>
#include		<math.h>
#include		<stdio.h>
#include		<stdlib.h>
#include		<lapin.h>
#include		<time.h>
#include		<unistd.h>

#define blp		bunny_load_picture
#define wb		&data->win->buffer
#define bb		bunny_blit

typedef struct		s_menu
{
  bool			prof;
  bool			larg;
  bool			ast;
  t_bunny_position	fond_pos;
  t_bunny_picture	*menu_fond;
  t_bunny_picture	*checkbox;
  t_bunny_position	check;
}			t_menu;

typedef struct		s_generateur
{
  int			length;
  int			width;
  int			parfait;
  t_bunny_picture	*fond;
  t_bunny_position	fond_pos;
  t_bunny_picture	*wall;
  t_bunny_position	wall_pos;
  bool			value;
  bool			check;
}			t_generateur;

typedef struct		s_profondeur
{
  bool			opt;
  bool			check;
  bool			essais;
  t_bunny_picture	*path;
  t_bunny_picture	*path_essais;
  t_bunny_position	path_pos;
  t_bunny_position	essais_pos;
}			t_profondeur;

typedef struct		s_largeur
{
  bool			check;
  bool			essais;
  t_bunny_picture	*path;
  t_bunny_picture	*path_essais;
  t_bunny_position	path_pos;
}			t_largeur;

typedef struct		s_astar
{
  bool			check;
  bool			essais;
  t_bunny_picture	*path;
  t_bunny_picture	*path_essais;
  t_bunny_position	path_pos;
}			t_astar;

typedef struct		s_data
{
  int			h;
  char			**maze;
  char			**maze_p;
  char			**maze_l;
  char			**maze_a;
  t_bunny_window	*win;
  t_menu		menu;
  t_generateur		gen;
  t_profondeur		prof;
  t_largeur		larg;
  t_astar		ast;
  const t_bunny_position*mouse;
}			t_data;

t_bunny_response		response_key(t_bunny_event_state              state,
					     t_bunny_keysym                   sym,
					     void                             *_data);
t_bunny_response		response_click(t_bunny_event_state state,
					       t_bunny_mousebutton button,
					       void *_data);
t_bunny_response		response_move(const t_bunny_position *relative,
					      void *_data);

t_bunny_picture			*x_blp(char *path);

/* Function(s) in file gen_maze_size.c */
void			put_value(int **maze, t_data *data, int value, int replace);
void			pick_random_case(int **maze, t_data *data);
int			check_end(int **maze, t_data *data);
int			**gen_maze_size(t_data *data);

/* Function(s) in file generateur.c */
char			**maze_cp(t_data *data, char **dest, char **src);
void			generate(t_data *data);
void			init_generateur(t_data *data);
int			generater(t_data *data);
void		        aff_maze(t_data *data);
int			generateur(t_data *data);

/* Function(s) in file check_case.c */
void			check_nbr0(int **maze, int x, int y, t_data *data);
void			check_nbr1(int **maze, int x, int y, t_data *data);
void			check_nbr2(int **maze, int x, int y, t_data *data);
void			check_nbr3(int **maze, int x, int y, t_data *data);
void			check_case_g(int **maze, int x, int y, t_data *data);

/* Function(s) in file main.c */
void			menu(t_data *data);
t_bunny_response	mainloop(void *_data);
void			init_values(t_data *data);
int			main();

/* Function(s) in file break_wall.c */
int			count_wall(int *maze, t_data *data);
int			break_one(int *maze, t_data *data);
void			break_width(int **maze, t_data *data);
void			break_length(int **maze, t_data *data);
void			break_wall(int **maze, t_data *data);

/* Function(s) in file init_maze.c */
int			**init_maze(int **maze, t_data *data);
void			init_wall(int **maze, t_data *data);
void			generate_wall(int **maze, t_data *data);

/* Function(s) in file write_maze.c */
void			init_maze_tab(t_data *data);
int			write_maze(int **maze, t_data *data);
void			aff_tab(char **maze);

void			aff_border(t_data *data, int i);
void			menu_click(t_data *data);
void			aff_all(t_data *data);
int			astar(t_data *data);
int			largeur(t_data *data);
void			aff_path(t_data *data);
int			profondeur(t_data *data);
#endif /* _BONUS_H_ */
