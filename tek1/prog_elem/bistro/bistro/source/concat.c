/*
** concat.c for concat in /home/platel_k/projet/bistro/source
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Sun Nov  6 12:34:24 2011 kevin platel
** Last update Tue Nov  8 13:21:14 2011 kevin platel
*/

#include <stdlib.h>
#include "list.h"
#include "bistromathique.h"
#include "my.h"

t_list	*concat(t_list **list, t_list **list2)
{
  if ((*list) != NULL)
    {
      while ((*list)->befo != NULL)
	(*list) = (*list)->befo;
      if ((*list2) != NULL)
	while ((*list2)->next != NULL)
	  (*list2) = (*list2)->next;
      (*list)->befo = (*list2);
      if ((*list2) != NULL)
	(*list2)->next = (*list);
      while ((*list)->befo != NULL)
	(*list) = (*list)->befo;
    }
  return ((*list));
}
