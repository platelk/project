/*
** rotate.c for rotate.c in /home/platel_k/projet/pushswap/source
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Tue Dec 20 10:36:09 2011 kevin platel
** Last update Sun Jan  8 11:27:15 2012 kevin platel
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "pushswap.h"

void	rra(t_nbr **list_a)
{
  t_nbr	*tmp;

  tmp = (*list_a);
  if ((*list_a) != NULL && tmp != NULL && (*list_a)->next != NULL)
    {
      (*list_a) = (*list_a)->prev;
      if ((*list_a)->prev != NULL)
	(*list_a)->prev->next = NULL;
      (*list_a)->next = tmp;
      tmp->prev = (*list_a);
      write(1, "rra ", 4);
    }
}

void	rrb(t_nbr **list_b)
{
  t_nbr	*tmp;

  tmp = (*list_b);
  if ((*list_b) != NULL && tmp != NULL && (*list_b)->next != NULL)
    {
      (*list_b) = (*list_b)->prev;
      if ((*list_b)->prev != NULL)
	(*list_b)->prev->next = NULL;
      (*list_b)->next = tmp;
      tmp->prev = (*list_b);
      write(1, "rrb ", 4);
    }
}

void	rrr(t_nbr **list_a, t_nbr **list_b)
{
  rrb(list_b);
  rra(list_a);
}

t_nbr   *del_one(t_nbr *list)
{
  t_nbr *tmp;

  tmp = list;
  if (list != NULL)
    {
      if (list->next != NULL)
	list = list->next;
      else
	list = NULL;
      if (tmp->prev != NULL && list != tmp->prev)
	tmp->prev->next = list;
      if (list != NULL && tmp->prev != list)
	list->prev = tmp->prev;
      if (list != NULL && list == tmp->prev)
	list->next = NULL;
      free(tmp);
    }
  return (list);
}
