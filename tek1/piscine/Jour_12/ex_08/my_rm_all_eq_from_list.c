/*
** my_rm_all_eq_from_list.c for my_rm_all_eq_from_list in /home/platel_k//projet/piscine/Jour_12
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Tue Oct 25 15:17:50 2011 kevin platel
** Last update Tue Oct 25 16:07:48 2011 kevin platel
*/

#include <stdlib.h>
#include "my.h"
#include "stru.h"

int	my_rm_all_eq_from_list(t_list **begin, void *data_ref, int (*cmp)())
{
  t_list *temp;
  t_list *start;

  temp = (*begin);
  start = (*begin);
  while ((*begin) != NULL)
    {
      if (!(*cmp)((*begin)->data, data_ref))
	{
	  temp->next = (*begin)->next;
	  free((*begin));
	}
      temp = (*begin);
      (*begin) = (*begin)->next;
    }
  (*begin) = start;
}
