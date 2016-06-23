/*
** x_fonction.c for x_fonction in /home/gastal_r/rendu/dante/bonus/sources
** 
** Made by 
** Login   <gastal_r@epitech.net>
** 
** Started on  Sun May  8 01:55:38 2016 
** Last update Sun May  8 02:01:35 2016 
*/

#include	"bonus.h"

t_bunny_picture		*x_blp(char *path)
{
  t_bunny_picture *picture;

  if ((picture = bunny_load_picture(path)) == NULL)
    exit (0);
  return (picture);
}
