/*
** sort_list_a.c for sort_list_a in /home/platel_k/projet/prog_elem/pushswap/source
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Tue Jan  3 09:43:51 2012 kevin platel
** Last update Sun Jan  8 11:28:16 2012 kevin platel
*/

#include <stdlib.h>
#include "my.h"
#include "pushswap.h"

int	choice_val(t_nbr *list)
{
  int	nb1;
  int	nb2;
  int	nb3;

  nb1 = 0;
  nb2 = 0;
  nb3 = 0;
  if (list != NULL)
    {
      if (list->next != NULL)
	list = list->next;
      nb2 = list->nbr;
      if (list->prev != NULL)
	nb1 = list->prev->nbr;
      if (list->next != NULL)
	nb3 = list->next->nbr;
    }
  nb1 = moy_val(nb1, nb2, nb3);
  if (nb1 != 0)
    return (nb1);
  if (list != NULL && nb1 == nb2 && nb2 == nb3)
    return (list->nbr);
  return (0);
}

int	moy_val(int nb1, int nb2, int nb3)
{
  if (nb1 <= nb2 && nb2 <= nb3)
    return (nb2);
  if (nb3 <= nb2 && nb2 <= nb1)
    return (nb2);
  if (nb2 <= nb1 && nb1 <= nb3)
    return (nb1);
  if (nb3 <= nb1 && nb1 <= nb2)
    return (nb1);
  if (nb1 <= nb3 && nb3 <= nb2)
    return (nb3);
  if (nb2 <= nb3 && nb3 <= nb1)
    return (nb3);
  return (0);
}

void	sort_list_a(t_nbr **list_a, t_nbr **list_b, int piv)
{
  if ((*list_a)->nbr > val_of_end((*list_a)) && (*list_a)->next != NULL
      && val_of_end((*list_a)) < piv)
    rra(list_a);
  if (piv == (*list_a)->nbr)
    pb(list_a, list_b);
  else if (piv > (*list_a)->nbr)
    if ((*list_b) != NULL && (*list_b)->next != NULL
	&& val_of_end((*list_b)) > (*list_a)->nbr
	&& val_of_end((*list_b)) != piv)
      {
	rrb(list_b);
	pb(list_a, list_b);
	rb(list_b);
	rb(list_b);
      }
    else
      {
	pb(list_a, list_b);
	if ((*list_b)->next != NULL)
	  rb(list_b);
      }
  else
    ra(list_a);
}

void	sort_list_b(t_nbr **list_a, t_nbr **list_b, int piv)
{
  if ((*list_b)->nbr > val_of_end((*list_b)) && (*list_b)->next != NULL
      && val_of_end((*list_b)) < piv)
      rrb(list_b);
  if (piv == (*list_b)->nbr)
    pa(list_a, list_b);
  else if (piv > (*list_b)->nbr)
    if ((*list_a) != NULL && (*list_a)->next != NULL
	&& val_of_end((*list_a)) > (*list_b)->nbr
	&& val_of_end((*list_a)) != piv)
      {
	rra(list_a);
	pa(list_a, list_b);
	ra(list_a);
	ra(list_a);
      }
    else
      {
	pa(list_a, list_b);
	if ((*list_a)->next != NULL)
	  ra(list_a);
      }
  else
    rb(list_b);
}
