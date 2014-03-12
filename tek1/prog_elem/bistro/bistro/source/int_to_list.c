/*
** int_to_list.c for int_to_list in /home/przyby_m/projet/bistro/source
** 
** Made by matthieu przybylski
** Login   <przyby_m@epitech.net>
** 
** Started on  Wed Nov  2 10:58:47 2011 matthieu przybylski
** Last update Thu Nov  3 12:39:22 2011 matthieu przybylski
*/

#include <stdlib.h>
#include "list.h"
#include "bistromathique.h"
#include "my.h"

t_list		*add_digit_in_list(t_list **list, char digit, int *nbr)
{
  t_list        *new;

  while ((*list)->befo != NULL)
    *list = (*list)->befo;
  new = malloc(sizeof(*new));
  if (new == NULL)
    return (NULL);
  if (list != NULL)
    (*list)->befo = new;
  new->cha = digit;
  new->next = *list;
  new->befo = NULL;
  *nbr = *nbr / 10;
  return (new);
}

t_list		*int_to_list(int nbr)
{
  t_list	*list;
  int		neg;

  neg = 0;
  if (nbr < 0)
    {
      nbr = nbr * -1;
      neg = 1;
    }
  list = NULL;
  list = init_list(&list, ((nbr % 10) + '0'));
  nbr = nbr / 10;
  while (list->befo != NULL)
    list = list->befo;
  while (nbr >= 10)
    list = add_digit_in_list(&list, ((nbr % 10) + '0'), &nbr);
  add_digit_in_list(&list, (nbr + '0'), &nbr);
  if (neg == 1)
    list = add_digit_in_list(&list, '-', &nbr);
  while (list->befo != NULL)
    list = list->befo;
  return (list);
}
