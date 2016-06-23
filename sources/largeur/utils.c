/*
** utils.c for utils in /home/gastal_r/rendu/dante/sources/profondeur
** 
** Made by remi gastal_r
** Login   <gastal_r@epitech.net>
** 
** Started on  Sat Apr 30 14:04:59 2016 remi gastal_r
** Last update Sun May 15 17:14:07 2016 
*/

#include "profondeur.h"

char            *my_strcat(char *dest, char *src, int i, int j)
{
  char          *tmp;
  int           len_src;
  int           len_dest;

  if ((len_src = my_strlen(src)) < 0)
    return (NULL);
  if (dest == NULL)
    {
      if ((dest = malloc((len_src + 1))) == NULL)
        return (NULL);
      while (src[++i])
        dest[i] = src[i];
      dest[i] = '\0';
      return (dest);
    }
  len_dest = my_strlen(dest);
  if ((tmp = malloc((len_src + len_dest + 1))) == NULL)
    return (NULL);
  while (dest[++j])
    tmp[j] = dest[j];
  while (src[++i])
    tmp[j++] = src[i];
  tmp[j] = '\0';
  free(dest);
  return (tmp);
}

int             my_strlen(char *buff)
{
  int   i;

  i = 0;
  if (buff == NULL)
    return (0);
  while (buff[i] != '\0')
    i++;
  return (i);
}

int     get_width(char *maze)
{
  int   i;

  i = 0;
  while (maze[i] != '\0')
    i++;
  return (i);
}

int     get_length(char **maze)
{
  int   i;

  i = 0;
  while (maze[i] != NULL)
    i++;
  return (i);
}
