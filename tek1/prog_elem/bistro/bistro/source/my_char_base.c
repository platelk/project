/*
** my_char_base.c for my_char_base in /home/platel_k/projet/bistro/source
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Sat Nov  5 12:11:34 2011 kevin platel
** Last update Sat Nov  5 13:49:38 2011 kevin platel
*/

#include <stdlib.h>
#include "list.h"
#include "bistromathique.h"

int	my_char_base(t_list *begin, char *base)
{
  int	nb;
  int	i;

  i = 0;
  nb = 0;
  if (begin == NULL)
    return (0);
  while (base[i] != '\0' && begin->cha != base[i])
    i = i + 1;
  if (base[i] == '\0')
    return (0);
  return (i);
}
