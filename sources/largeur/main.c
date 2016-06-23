/*
** main.c for dante in /home/gastal_r/rendu/dante/sources/profondeur
**
** Made by gastal_r
** Login   <gastal_r@epitech.net>
**
** Started on  Sat Apr 30 11:18:18 2016 gastal_r
** Last update Thu Jun 23 10:15:37 2016 
*/

#include	"largeur.h"

void		free_fonc(char **maze, t_path *path)
{
  int           i;
  t_path        *curr;

  i = 0;
  while (maze[i] != NULL)
    {
      free(maze[i]);
      i++;
    }
  free(maze);
  if (path == NULL)
    return;
  while (path->prev != NULL)
    path = path->prev;
  while ((curr = path) != NULL)
    {
      path = path->next;
      free (curr);
    }
}

int		main(int ac, char **av)
{
  char		*line;
  char		**maze;
  t_path	*path;
  int           fd;
  struct stat   fileStat;

  if (ac != 2)
    {
      printf("Utilisation : ./solver maze.txt,\n");
      return (0);
    }
  if ((fd = open(av[1], O_RDONLY)) < -1)
    return (0);
  if (fstat(fd, &fileStat) < 0)
    return (0);
  path = NULL;
  line = NULL;
  line = malloc(sizeof(char) * (fileStat.st_size + 1));
  read(fd, line, fileStat.st_size);
  line[fileStat.st_size] = '\0';
  maze = my_str_to_wordtab(line);
  find_path(maze, &path);
  free_fonc(maze, path);
  free(line);
  return 0;
}
