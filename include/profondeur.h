/*
** my.h for my in /home/gastal_r/rendu/dante
** 
** Made by remi gastal_r
** Login   <gastal_r@epitech.net>
** 
** Started on  Tue Apr 26 14:28:45 2016 remi gastal_r
** Last update Sun May 22 10:22:42 2016 remi gastal_r
*/

#define _GNU_SOURCE

#ifndef _PROFONDEUR_H_
# define _PROFONDEUR_H_

#include	<stdlib.h>
#include	<stdio.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<time.h>
#include	<unistd.h>
#include	<string.h>
#include	<stdbool.h>

typedef struct	s_path
{
  int		x;
  int		y;
  bool		node;
  struct s_path *next;
  struct s_path *prev;
}		t_path;

typedef struct s_check_case
{
  int		check;
  int		width;
  int		length;
}		t_check;

typedef struct	s_current
{
  int		x;
  int		y;
}		t_current;

/* Function(s) in file get_path.c */
void		aff_tab(char **maze);
void		init_fonc(char **maze, t_check *check, t_path **path);
int		find_path(char **maze, t_path **path);

/* Function(s) in file check_fonc.c */
int		check_path(t_path *path, int y, int x);
void		check_node(char **maze, t_path **path, t_check *check);
int		check_remove(char**maze, t_path **path, t_check *check);
int		check_case(char **maze, t_path **path, t_check *check);

/* Function(s) in file main.c */
void		free_fonc(char **maze, t_path *path);
int		main();

/* Function(s) in file check_dir.c */
int		check_up(char **maze, t_path **path, t_check *check);
int		check_right(char **maze, t_path **path, t_check *check);
int		check_down(char **maze, t_path **path, t_check *check);
int		check_left(char **maze, t_path **path, t_check *check);

/* Function(s) in file utils.c */
char            *my_strcat(char *dest, char *src, int i, int j);
int		my_strlen(char *buff);
int	        get_width(char *maze);
int		get_length(char **maze);
void		aff_finalmaze(char **maze, t_path *path);

/* Function(s) in file my_str_to_wordtab.c */
int		char_isalpha(char str);
int		my_count_word(char *str);
char		**init_tab(char *str);
char		**my_str_to_wordtab(char *str);

/* Function(s) in file list_fonc.c */
void		view(t_path *path);
int		add_coor(t_path **path, int x, int y);
void		remove_coor(t_path **path, int x, int y);
void		remove_last(t_path **path);

#endif /*_PROFONDEUR_H_*/
