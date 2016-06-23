/*
** largeur.h for my in /home/gastal_r/rendu/dante
** 
** Made by remi gastal_r
** Login   <gastal_r@epitech.net>
** 
** Started on  Sun May  1 01:28:04 2016 remi gastal_r
** Last update Sun May  8 18:52:11 2016 
*/

#define _GNU_SOURCE

#ifndef _LARGEUR_H_
# define _LARGEUR_H_

#include        <stdlib.h>
#include        <stdio.h>
#include        <sys/types.h>
#include        <sys/stat.h>
#include        <fcntl.h>
#include        <time.h>
#include        <unistd.h>
#include        <string.h>
#include        <stdbool.h>

typedef struct	s_path
{
  bool		current;
  int		x;
  int		y;
  int		from_x;
  int		from_y;
  struct s_path	*next;
  struct s_path	*prev;
}		t_path;

typedef struct	s_data
{
  bool		first;
  int		width;
  int		length;
  int		x;
  int		y;
}		t_data;

/* Function(s) in file check_case.c */
int		check_up(char **maze, t_path **path, t_data *data);
int		check_right(char **maze, t_path **path, t_data *data);
int		check_down(char **maze, t_path **path, t_data *data);
int		check_left(char **maze, t_path **path, t_data *data);
int		check_case(char **maze, t_path **path, t_data *data);

/* Function(s) in file main.c */
void		free_fonc(char **maze, t_path *path);
int		main(int ac, char **av);

/* Function(s) in file utils.c */
char            *my_strcat(char *dest, char *src, int i, int j);
int             my_strlen(char *buff);
int		get_width(char *maze);
int		get_length(char **maze);

/* Function(s) in file list_fonc.c */
void		view(t_path *path);
int             add_coor(t_path **path, t_data *data, int y, int x);
void            remove_coor(t_path **path, int x, int y);
void		remove_last(t_path **path);

/* Function(s) in file get_path.c */
void		aff_tab(char **maze);
void		init_data(char **maze, t_path **path, t_data *data);
void		get_path(char **maze, t_path **path, t_data *data);
int		find_path(char **maze, t_path **path);

char		**my_str_to_wordtab(char *str);

#endif /*_LARGEUR_H_*/
