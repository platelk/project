/*
** function.c for function in /home/platel_k/projet/prog_elem/pushswap/source
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Sat Dec 24 14:09:35 2011 kevin platel
** Last update Sun Jan  8 11:43:22 2012 kevin platel
*/

#include <stdlib.h>
#include "my.h"
#include "pushswap.h"

int	init_sort(t_nbr **list_a)
{
  t_nbr		*tmp;
  static int	piv;
  int		new;

  if (val_of_end((*list_a)) < (*list_a)->nbr && val_of_end((*list_a)) != piv)
    rra(list_a);
  if ((*list_a)->next != NULL && (*list_a)->next->nbr < (*list_a)->nbr)
    (*list_a) = sa((*list_a));
  tmp = (*list_a);
  while (tmp != NULL)
    {
      new = choice_val(tmp);
      if (new != piv)
	{
	  piv = new;
	  return (piv);
	}
      tmp = tmp->next;
    }
  return (piv);
}

void	restart(t_nbr **list_a, t_nbr **list_b)
{
  int	piv;
  if (end_of_sort((*list_b)) == 1 && (*list_b) != NULL)
    {
      while ((*list_b) != NULL)
	{
	  piv = init_sort_list_b(list_b);
	  while ((*list_b) != NULL && nothing_less(piv, (*list_b)) == 1)
	    {
	      if ((*list_b)->next != NULL && (*list_b)->nbr > (*list_b)->next->nbr)
		(*list_b) = sb((*list_b));
	      if ((*list_b)->prev != NULL && (*list_b)->prev->nbr < piv)
		rrb(list_b);
	      while ((*list_b)->nbr > piv)
		rb(list_b);
	      sort_list_b(list_a, list_b, piv);
	    }
	  while ((*list_a)->next != NULL && (*list_a)->nbr == piv)
	    ra(list_a);
	  if ((*list_a)->next != NULL && (*list_a)->nbr > (*list_a)->next->nbr)
	    (*list_a) = sa((*list_a));
	}
    }
  empty_the_list(list_b, list_a);
}

void	empty_the_list(t_nbr **list_b, t_nbr **list_a)
{
  while ((*list_b) != NULL)
    {
      rrb(list_b);
      pa(list_a, list_b);
    }
}

int	init_sort_list_b(t_nbr **list_b)
{
  t_nbr		*tmp;
  static int	piv;
  int	new;

  if ((*list_b) != NULL)
    {
      if (val_of_end((*list_b)) < (*list_b)->nbr
	  && val_of_end((*list_b)) != piv)
	rrb(list_b);
      if ((*list_b)->next != NULL && (*list_b)->next->nbr < (*list_b)->nbr)
	(*list_b) = sb((*list_b));
      tmp = (*list_b);
      while (tmp)
	{
	  new = choice_val(tmp);
	  if (new != piv)
	    {
	      piv = new;
	      return (piv);
	    }
	  tmp = tmp->next;
	}
    }
  return (piv);
}
