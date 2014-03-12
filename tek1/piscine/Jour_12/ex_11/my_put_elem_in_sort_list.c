/*
** my_put_elem_in_sort_list.c for my_put_elem_in_sort_list in /home/platel_k//projet/piscine/Jour_12
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Tue Oct 25 19:36:49 2011 kevin platel
** Last update Tue Oct 25 20:28:11 2011 kevin platel
*/

#include <stdlib.h>
#include "my.h"
#include "stru.h"

int	my_put_elem_in_sort_list(t_list **begin, void *data, int (*cmp)())
{
  t_list *new;
  t_list *temp;

  temp = (*begin);
  new = malloc(sizeof(*new));
  if(new == NULL)
    return (0);
  new->data = data;
  while ((*begin)->next != NULL && ((*cmp)((*begin)->next->data, data) < 0))
    (*begin) = (*begin)->next;

  if ((*cmp)(temp->data, data) > 0)
    {
      (*begin) = temp;
      new->next = (*begin);
      (*begin)->next = temp->next;
      (*begin) = new;
    }
  else
    {
      new->next = (*begin)->next;
      (*begin)->next = new;
      (*begin) = temp;
    }
}
