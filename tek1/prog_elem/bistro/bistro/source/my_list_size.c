/*
** my_list_size.c for my_list_size in /home/platel_k//projet/piscine/Jour_12
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Tue Oct 25 11:10:04 2011 kevin platel
** Last update Fri Nov  4 12:02:36 2011 kevin platel
*/

#include <stdlib.h>
#include "list.h"
#include "bistromathique.h"

int	my_list_size(t_list *begin)
{
  int	i;

  i = 0;
  while (begin != NULL)
    {
      begin = begin->next;
      i = i + 1;
    }
  return (i);
}
