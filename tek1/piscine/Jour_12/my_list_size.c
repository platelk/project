/*
** my_list_size.c for my_list_size in /home/platel_k//projet/piscine/Jour_12
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Tue Oct 25 11:10:04 2011 kevin platel
** Last update Tue Nov  1 17:12:29 2011 kevin platel
*/

#include <stdlib.h>
#include "stru.h"
#include "my.h"

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
