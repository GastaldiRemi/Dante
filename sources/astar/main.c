/*
** main.c for main in /home/gastal_r/rendu/dante/sources/astar
** 
** Made by 
** Login   <gastal_r@epitech.net>
** 
** Started on  Wed May  4 15:49:27 2016 
** Last update Mon May 30 17:18:54 2016 
*/

#include	"astar.h"

void		free_fonc(char **maze, t_list *open, t_list *closed)
{
  int           i;
  t_list        *curr;

  i = 0;
  while (maze[i] != NULL)
    {
      free(maze[i]);
      i++;
    }
  free(maze);
  if (open)
    while (open->prev != NULL)
      open = open->prev;
  while ((curr = open) != NULL)
    {
      open = open->next;
      free (curr);
    }
  while (closed->prev != NULL)
    closed = closed->prev;
  while ((curr = closed) != NULL)
    {
      closed = closed->next;
      free (curr);
    }
}

int		main(int ac, char **av)
{
  t_list	*closed;
  t_list	*open_list;
  char		**maze;
  char		*line;
  int		fd;
  struct stat	fileStat;

  if (ac != 2)
    {
      printf("Utilisation : ./solver maze.txt,\n");
      return (0);
    }
  if ((fd = open(av[1], O_RDONLY)) < -1 || fstat(fd, &fileStat) < 0)
    return (0);
  closed = NULL;
  open_list = NULL;
  line = NULL;
  line = malloc(sizeof(char) * (fileStat.st_size + 1));
  read(fd, line, fileStat.st_size);
  line[fileStat.st_size] = '\0';
  maze = my_str_to_wordtab(line);
  find_path(maze, &closed, &open_list);
  free_fonc(maze, open_list, closed);
  free(line);
  return (0);
}
