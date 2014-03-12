/*
** add_in_list.c for add_in_list in /home/platel_k//projet/piscine/eval
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Fri Oct 28 10:02:19 2011 kevin platel
** Last update Fri Oct 28 11:07:33 2011 kevin platel
*/

#include "list.h"
#include <stdlib.h>

t_list          *add_in_list(t_list **list, char value)
{
  t_list        *new;
  t_list        *temp;

  temp = (*list);
  if (temp != NULL)
    while(temp->next != NULL)
      temp =temp->next;
  new = malloc(sizeof(*new));
  if (new == NULL)
    return (0);
  if(temp != NULL)
    temp->next = new;
  new->cha = value;
  new->next = NULL;
  new->befo = temp;
  return (*list);
}
