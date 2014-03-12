/*
** create_list.c for create_list in /home/platel_k/projet/pushswap/source
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Mon Dec 19 13:38:25 2011 kevin platel
** Last update Sun Jan  8 11:26:22 2012 kevin platel
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "pushswap.h"

t_nbr	*add_in_list(int nbr, t_nbr *begin)
{
  t_nbr	*new;

  new = malloc(sizeof(*new));
  new->nbr = nbr;
  new->next = begin;
  new->prev = NULL;
  if (begin != NULL)
    begin->prev = new;
  return (new);
}

t_nbr	*sb(t_nbr *list)
{
  int	nbr_a;

  if (list != NULL)
    {
      nbr_a = list->nbr;
      if (list->next != NULL)
	{
	  list->nbr = list->next->nbr;
	  list->next->nbr = nbr_a;
	  write(1, "sb ", 3);
	}
    }
  return (list);
}

t_nbr	*sa(t_nbr *list)
{
  int	nbr_a;

  if (list != NULL)
    {
      nbr_a = list->nbr;
      if (list->next != NULL)
	{
	  list->nbr = list->next->nbr;
	  list->next->nbr = nbr_a;
	  write(1, "sa ", 3);
	}
    }
  return (list);
}

t_nbr   *create_list(int ac, char **av)
{
  int	i;
  t_nbr	*list_a;
  t_nbr *tmp;

  list_a = NULL;
  i = ac - 1;
  list_a = add_in_list(my_getnbr(av[i]), list_a);
  tmp = list_a;
  i--;
  while (i > 0 && list_a != NULL)
    {
      list_a = add_in_list(my_getnbr(av[i]), list_a);
      if (list_a->next != NULL && list_a->nbr > list_a->next->nbr)
	list_a = sa(list_a);
      i--;
    }
  if (list_a != NULL)
    list_a->prev = tmp;
  return (list_a);
}
