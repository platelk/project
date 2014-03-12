/*
** add_one_in_list.c for eval_expr in /home/przyby_m/projet/bistro/source
** 
** Made by matthieu przybylski
** Login   <przyby_m@epitech.net>
** 
** Started on  Thu Nov  3 09:34:58 2011 matthieu przybylski
** Last update Sat Nov  5 10:56:34 2011 matthieu przybylski
*/

#include <stdlib.h>
#include "list.h"
#include "bistromathique.h"

t_list          *add_one_in_list(t_list **list, char value)
{
  t_list        *new;
  t_list        *temp;

  temp = (*list);
  if (temp == NULL)
    return (NULL);
  else
    {
      new = malloc(sizeof(*new));
      if (new == NULL)
	return (NULL);
      new->next = temp->next;
      temp->next = new;
      new->cha = value;
      new->befo = temp;
    }
  return ((*list));
}
