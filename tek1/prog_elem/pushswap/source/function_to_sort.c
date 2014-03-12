/*
** function_to_sort.c for function_to_sort.c in /home/platel_k/projet/prog_elem/pushswap
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Fri Dec 23 16:14:10 2011 kevin platel
** Last update Sun Jan  8 11:46:55 2012 kevin platel
*/

#include <stdlib.h>
#include "my.h"
#include "pushswap.h"

void	main_function_sort(t_nbr *list_a, t_nbr *list_b)
{
  t_nbr	*tmp;
  int	piv;

  tmp = list_a;
  while (end_of_sort(list_a) == 1)
    {
      while (list_a != NULL)
	{
	  piv = init_sort(&list_a);
	  while (list_a != NULL && nothing_less(piv, list_a) == 1)
	    {
	      if (list_a->next != NULL && list_a->nbr > list_a->next->nbr)
		list_a = sa(list_a);
	      if (list_a->prev != NULL && list_a->prev->nbr < piv)
		rra(&list_a);
	      while (list_a->nbr > piv)
		ra(&list_a);
	      sort_list_a(&list_a, &list_b, piv);
	    }
	  while (list_b->next != NULL && list_b->nbr == piv)
	    rb(&list_b);
	  if (list_b->next != NULL && list_b->nbr > list_b->next->nbr)
	    list_b = sb(list_b);
	}
      restart(&list_a, &list_b);
    }
}

int	end_of_sort(t_nbr *list_a)
{
  while (list_a != NULL)
    {
      if (list_a->next != NULL && (list_a->nbr > list_a->next->nbr))
	return (1);
      list_a = list_a->next;
    }
  return (0);
}

int	inv_list(t_nbr *list_a)
{
  while (list_a != NULL)
    {
      if (list_a->next != NULL && (list_a->nbr < list_a->next->nbr))
	return (1);
      list_a = list_a->next;
    }
  return (0);
}

int	nothing_less(int val, t_nbr *list)
{
  while (list != NULL)
    {
      if (val >= list->nbr)
	return (1);
      list = list->next;
    }
  return (-1);
}

int	val_of_end(t_nbr *list)
{
  if (list != NULL)
    return (list->nbr);
  else
    return (0);
}
