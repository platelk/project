/*
** function_push.c for function_push in /home/platel_k/projet/pushswap/source
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Mon Dec 19 15:27:30 2011 kevin platel
** Last update Sun Jan  8 11:27:35 2012 kevin platel
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "pushswap.h"

void	pa(t_nbr **list_a, t_nbr **list_b)
{
  t_nbr	*tmp;

  tmp = (*list_b);
  if ((*list_b) != NULL)
    {
      (*list_b) = (*list_b)->next;
      if ((*list_b) != NULL && (*list_b)->prev != NULL)
	(*list_b)->prev = (*list_b)->prev->prev;
      tmp->next = (*list_a);
      if ((*list_a) != NULL && (*list_a)->next != NULL)
	tmp->prev = (*list_a)->prev;
      else
	tmp->prev = (*list_a);
      if (list_a != NULL && (*list_a) != NULL)
	(*list_a)->prev = tmp;
      (*list_a) = tmp;
      write(1, "pa ", 3);
    }
}

void	pb(t_nbr **list_a, t_nbr **list_b)
{
  t_nbr	*tmp;

  tmp = (*list_a);
  if ((*list_a) != NULL)
    {
      (*list_a) = (*list_a)->next;
      tmp->next = (*list_b);
      if ((*list_a) != NULL && (*list_a)->prev != NULL)
	(*list_a)->prev = (*list_a)->prev->prev;
      if ((*list_b) != NULL && (*list_b)->next != NULL)
	tmp->prev = (*list_b)->prev;
      else
	tmp->prev = (*list_b);
      if ((*list_b) != NULL)
	(*list_b)->prev = tmp;
      (*list_b) = tmp;
      write(1, "pb ", 3);
    }
}

void   ra(t_nbr **list_a)
{
  t_nbr	*tmp;
  t_nbr	*new_first;

  tmp = (*list_a);
  new_first = NULL;
  if (tmp != NULL && tmp->next != NULL)
    {
      if (tmp->next != NULL)
	new_first = tmp->next;
      (*list_a) = (*list_a)->prev;
      if (new_first != NULL)
	new_first->prev = tmp;
      if (tmp != NULL)
	tmp->next = NULL;
      if (tmp != NULL)
	tmp->prev = (*list_a);
      if ((*list_a) != NULL)
	(*list_a)->next = tmp;
      (*list_a) = new_first;
      write(1, "ra ", 3);
    }
}

void   rb(t_nbr **list_b)
{
  t_nbr	*tmp;
  t_nbr	*new_first;

  tmp = (*list_b);
  new_first = NULL;
  if (tmp != NULL && tmp->next != NULL)
    {
      if (tmp->next != NULL)
	new_first = tmp->next;
      (*list_b) = (*list_b)->prev;
      if (new_first != NULL)
	new_first->prev = tmp;
      if (tmp != NULL)
	tmp->next = NULL;
      if (tmp != NULL)
	tmp->prev = (*list_b);
      if ((*list_b) != NULL)
	(*list_b)->next = tmp;
      (*list_b) = new_first;
      write(1, "rb ", 3);
    }
}

void	rr(t_nbr **list_b, t_nbr **list_a)
{
  ra(list_a);
  rb(list_b);
}
