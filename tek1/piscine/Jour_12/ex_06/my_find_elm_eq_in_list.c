/*
** my_find_elm_eq_in_list.c for my_find_elm_eq_in_list.c in /home/platel_k//projet/piscine/Jour_12
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Tue Oct 25 15:10:39 2011 kevin platel
** Last update Tue Oct 25 15:13:06 2011 kevin platel
*/
#include <stdlib.h>
#include "my.h"
#include "stru.h"

void	*my_find_elm_eq_in_list(t_list *begin, void *data_ref, int (*cmp)())
{
  while (begin != NULL)
    {
      if (!(*cmp)(begin->data, data_ref))
	return (begin->data);
      begin = begin->next;
    }
  return (0);
}
