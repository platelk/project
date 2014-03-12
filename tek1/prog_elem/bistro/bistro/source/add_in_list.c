/*
** add_in_list.c for add_in_list in /home/platel_k//projet/piscine/eval
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Fri Oct 28 10:02:19 2011 kevin platel
** Last update Fri Nov  4 09:58:54 2011 matthieu przybylski
*/

#include <stdlib.h>
#include "list.h"
#include "bistromathique.h"

t_list          *add_in_list(t_list **list, char value)
{
  t_list        *new;
  t_list        *temp;

  temp = (*list);
  if (temp == NULL)
    (*list) = init_list(list, value);
  else
  {
    while(temp->next != NULL)
      temp = temp->next;
    new = malloc(sizeof(*new));
    if (new == NULL)
      return (NULL);
    if (temp != NULL)
      temp->next = new;
    new->cha = value;
    new->next = NULL;
    new->befo = temp;
  }
  return ((*list));
}
