/*
** del_in_list.c for del_in_list in /home/platel_k/projet/bistro
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Tue Nov  1 11:05:59 2011 kevin platel
** Last update Fri Nov  4 10:21:42 2011 matthieu przybylski
*/

#include <stdlib.h>
#include "list.h"
#include "bistromathique.h"

t_list		*del_in_list(t_list **begin, t_list **end)
{
  t_list	*temp;
  t_list	*tmp;

  if ((*begin)->befo == NULL && (*end)->next == NULL)
    return (NULL);
  temp = *begin;
  while (temp != *end)
    {
      del_one_in_list(&temp);
      tmp = temp;
    }
  del_one_in_list(&temp);
  tmp = temp;
  return (tmp);
}
