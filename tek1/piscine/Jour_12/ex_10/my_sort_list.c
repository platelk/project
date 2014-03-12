/*
** my_sort_list.c for my_sort_list in /home/platel_k//projet/piscine/Jour_12
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Tue Oct 25 17:05:27 2011 kevin platel
** Last update Tue Oct 25 19:30:57 2011 kevin platel
*/

#include <stdlib.h>
#include "my.h"
#include "stru.h"

t_list		*add_new(t_list **list, char *value)
{
  t_list	*new;

  new = malloc(sizeof(*new));
  if (new == NULL)
    return (0);
  new->data = value;
  new->next = *list;

  return (*list = new);
}

int		my_list_swap(t_list *begin, t_list *ant_begin)
{
  t_list        *temp;
  t_list	*temp2;

  temp = begin;
  begin = begin->next;
  temp2 = begin->next;

  begin->next = temp;
  temp->next = temp2;
  ant_begin->next = begin;
  return (1);
}

int		my_sort_list(t_list **begin, int (*cmp)())
{
  t_list	*temp;
  t_list	*ant_temp;

  temp = (*begin);
  ant_temp = add_new(begin, " ");
  if ((*begin)->next == NULL)
    return (0);
  while (temp->next != NULL)
    {
      if ((*cmp)(temp->data, temp->next->data) > 0)
	{
	  my_list_swap(temp, ant_temp);
	  temp = (*begin)->next;
	  ant_temp = (*begin);
	}
      else
	{
	  ant_temp = temp;
	  temp = temp->next;
	}
    }
  (*begin) = (*begin)->next;
}
