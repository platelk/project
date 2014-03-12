/*
** add_before_list.c for bistro in /home/przyby_m/projet/bistro/source
** 
** Made by matthieu przybylski
** Login   <przyby_m@epitech.net>
** 
** Started on  Fri Nov  4 11:26:48 2011 matthieu przybylski
** Last update Sat Nov  5 15:22:03 2011 matthieu przybylski
*/

#include <stdlib.h>
#include "list.h"
#include "bistromathique.h"

t_list		*add_before_list(t_list **list, char value)
{
  t_list	*new;

  new = malloc(sizeof(*new));
  if (new == NULL)
    return (NULL);
  if ((*list) == NULL)
    *list = init_list(list, value);
  else
    {
      if ((*list)->befo != NULL)
	{
	  new->befo = (*list)->befo;
	  ((*list)->befo)->next = new;
	}
      else
	new->befo = NULL;
      (*list)->befo = new;
      new->next = (*list);
      new->cha = value;
    }
  if ((*list)->befo != NULL)
    *list = (*list)->befo;
  return (*list);
}
