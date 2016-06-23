/*
** my_math.c for my_math in /home/gastal_r/rendu/dante/sources/astar
** 
** Made by 
** Login   <gastal_r@epitech.net>
** 
** Started on  Fri May  6 10:36:46 2016 
** Last update Fri May 13 16:53:34 2016 
*/

#include "astar.h"

int	my_sqrt(int x)
{
  int	prev;
  int	k;
  int	kmax;
  int	s;

  k = 0;
  kmax = 1000;
  s = 1;
  while (k < kmax)
    {
      prev = s;
      if (s == 0)
	return (0);
      s = (s + x/s)/2;
      if (prev == s)
	return (s);
      k++;
    }
  return (s);
}

int	my_pow(int x, int n)
{
  int i;
  int number;

  number = 1.0;
  i = 0;
  while (i < n)
    {
      number *= x;
      i++;
    }
  return (number);
}
