/*
** list_cpy.c for list_cpy.c in /home/platel_k/projet/bistro/source
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Sat Nov  5 10:01:37 2011 kevin platel
** Last update Sun Nov  6 09:50:49 2011 kevin platel
*/

#include <stdlib.h>
#include "list.h"
#include "bistromathique.h"

t_list		*list_cpy(t_list *begin)
{
  t_list	*begin_cpy;

  begin_cpy = NULL;
  while (begin != NULL)
    {
      begin_cpy = add_in_list(&begin_cpy, begin->cha);
      begin = begin->next;
    }
  return (begin_cpy);
}

t_list		*list_ncpy(t_list *begin, int n)
{
  t_list	*begin_cpy;
  int		i;

  i = 0;
  begin_cpy = NULL;
  while (begin != NULL && i < n)
    {
      begin_cpy = add_in_list(&begin_cpy, begin->cha);
      begin = begin->next;
      i = i + 1;
    }
  return (begin_cpy);
}
