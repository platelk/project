/*
** my_rev_list.c for my_rev_list in /home/platel_k//projet/piscine/Jour_12
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Tue Oct 25 11:18:08 2011 kevin platel
** Last update Tue Oct 25 17:09:13 2011 kevin platel
*/

#include <stdlib.h>
#include "my.h"
#include "stru.h"

int		my_swap_list(t_list *begin, t_list *ant_begin)
{
  t_list        *temp;

  if (begin == NULL)
    return (0);
  my_swap_list(begin->next, begin);
  begin->next = ant_begin;
  return (1);
}

int		my_rev_list(t_list **begin)
{
  t_list	*temp;
  t_list	*end;

  end = (*begin);
  while (end->next != NULL)
    end = end->next;
  temp = (*begin);
  my_swap_list((*begin)->next, (*begin));
  temp->next = NULL;
  (*begin) = end;
}
