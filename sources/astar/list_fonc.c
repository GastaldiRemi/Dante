/*
** list_fonc.c for list_fonc in /home/gastal_r/rendu/CPE_2015/CPE_2015_Lemin/remi
** 
** Made by remi gastal_r
** Login   <gastal_r@epitech.net>
** 
** Started on  Tue Apr 19 19:00:03 2016 remi gastal_r
** Last update Mon May 30 17:21:46 2016 
*/

#include "astar.h"

void	aff_tab(char	**maze)
{
  int	i;

  i = 0;
  while (maze[i] != NULL)
    {
      printf("%s\n", maze[i]);
      i++;
    }
}

int		add_node(t_list **node, t_data *data, int x, int y)
{
  t_list	*new;

  if ((new = malloc(sizeof(t_list))) == NULL)
    return (0);
  while ((*node) != NULL && (*node)->next != NULL)
    *node = (*node)->next;
  new->next = NULL;
  new->p_x = data->x;
  new->p_y = data->y;
  new->x = x;
  new->y = y;
  new->cout = data->cout;
  new->h = new->cout + my_sqrt(my_pow(((data->width - 1) - data->x), 2)
			       + my_pow(((data->length - 1) - data->y), 2));
  new->prev = *node;
  if ((*node) != NULL)
    (*node)->next = new;
  *node = new;
  return (0);
}

int		add_node_c(t_list **node, t_data *data)
{
  t_list	*new;

  if ((new = malloc(sizeof(t_list))) == NULL)
    return (0);
  while ((*node) != NULL && (*node)->next != NULL)
    *node = (*node)->next;
  new->next = NULL;
  new->p_x = data->p_x;
  new->p_y = data->p_y;
  new->x = data->x;
  new->y = data->y;
  new->cout = data->cout;
  new->h = new->cout + my_sqrt(my_pow(((data->width - 1) - data->x), 2)
			       + my_pow(((data->length - 1) - data->y), 2));
  new->prev = *node;
  if ((*node) != NULL)
    (*node)->next = new;
  *node = new;
  return (0);
}

void		remove_node2(t_data *node, t_list *currP)
{
  node->p_x = currP->p_x;
  node->p_y = currP->p_y;
  node->x = currP->x;
  node->y = currP->y;
  node->cout = currP->cout;
  node->h = node->cout + my_sqrt(my_pow(((node->width - 1) - node->x), 2)
				 + my_pow(((node->length - 1) - node->y), 2));
}

void            remove_node(t_list **open, t_data *node, float h)
{
  t_list   *currP;
  t_list   *prevP;

  prevP = NULL;
  currP = *open;
  while (currP != NULL)
    {
      if (currP->h == h)
	{
	  remove_node2(node, currP);
	  if (prevP == NULL)
	    {
	      *open = currP->prev;
	      if (*open != NULL)
	      	(*open)->next = NULL;
	    }
	  else
	      prevP->prev = currP->prev;
	  currP = NULL;
	  free(currP);
	  return;
	}
      prevP = currP;
      currP = currP->prev;
    }
}
