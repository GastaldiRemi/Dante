/*
** astar.h for astar in /home/gastal_r/rendu/dante
** 
** Made by 
** Login   <gastal_r@epitech.net>
** 
** Started on  Wed May  4 15:38:22 2016 
** Last update Sun May 29 17:13:09 2016 
*/

#define		 _GNU_SOURCE

#ifndef		 ASTAR_H_
# define	_ASTAR_H_

#include	<stdlib.h>
#include	<stdio.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<time.h>
#include	<unistd.h>
#include	<string.h>
#include	<math.h>

typedef	struct	s_list
{
  int		p_x;
  int		p_y;
  int		x;
  int		y;
  int		cout;
  int		h;
  struct s_list *prev;
  struct s_list *next;
}		t_list;

typedef	struct	s_data
{
  int		p_x;
  int		p_y;
  int		x;
  int		y;
  int		cout;
  int		h;
  int		width;
  int		length;
}		t_data;

/* Function(s) in file main.c */
int		main();

/* Function(s) in file utils.c */
char		*my_strcat(char *dest, char *src, int i, int j);
int		my_strlen(char *buff);
int		get_width(char *maze);
int		get_length(char **maze);

/* Function(s) in file check_list.c */
int		check_closed_list(t_list *closed, t_data *data, int x, int y);
int		check_open_list(t_list *open, t_data *data, int x, int y);

/* Function(s) in file list_fonc.c */
void		aff_tab(char**maze);
int		add_node(t_list **node, t_data *data, int x, int y);
int		add_node_c(t_list **node, t_data *data);
void		remove_node2(t_data *node, t_list *currP);
void		remove_node(t_list **open, t_data *node, float h);

/* Function(s) in file check_dir.c */
int		check_up(char **maze, t_list **closed,
			 t_list **open, t_data *node);
int		check_right(char **maze, t_list **closed,
			    t_list **open, t_data *node);
int		check_down(char **maze, t_list **closed,
			   t_list **open, t_data *node);
int		check_left(char **maze, t_list **closed,
			   t_list **open, t_data *node);
int		check_dir(char **maze, t_list **closed,
			  t_list **open, t_data *node);

/* Function(s) in file get_path.c */
void		init_path(char **maze, t_data *data);
void		get_less_h(t_list **open, t_data *node);
void		calc_final_path(char **maze, t_list **closed);
int		find_path(char **maze, t_list **closed, t_list **open);

/* Function(s) in file my_math.c */
int		my_sqrt(int x);
int		my_pow(int x, int n);

char		**my_str_to_wordtab(char *);

#endif		/* _ASTAR_H_ */
