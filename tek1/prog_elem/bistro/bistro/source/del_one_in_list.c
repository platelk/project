/*
** del_one_in_list.c for del_one_in_list in /home/platel_k//projet/piscine/eval
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Fri Oct 28 10:00:11 2011 kevin platel
** Last update Sun Nov  6 10:33:14 2011 matthieu przybylski
*/

#include <stdlib.h>
#include "list.h"
#include "bistromathique.h"

t_list	        *del_one_in_list(t_list **list)
{
  t_list        *temp;

  temp = (*list);
  if ((*list) != NULL)
    {
      if ((*list)->befo != NULL && (*list)->next != NULL)
	{
	  (*list) = (*list)->befo;
	  (*list)->next = temp->next;
	  (temp->next)->befo = *list;
	  (*list) = (*list)->next;
	}
      else if ((*list)->befo == NULL && (*list)->next != NULL)
	{
	  ((*list)->next)->befo = NULL;
	  *list = (*list)->next;
	}
      else if ((*list)->befo != NULL && (*list)->next == NULL)
	{
	  *list = (*list)->befo;
	  (*list)->next = NULL;
	}
      else
	*list = NULL;
      free(temp);
    }
  return (*list);
}
