/*
** del_one_in_list.c for del_one_in_list in /home/platel_k//projet/piscine/eval
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Fri Oct 28 10:00:11 2011 kevin platel
** Last update Fri Oct 28 11:07:34 2011 kevin platel
*/
#include "list.h"
#include <stdlib.h>

t_list          *del_one_in_list(t_list **list)
{
  t_list        *temp;
  temp = (*list);
  (*list) = (*list)->befo;
  (*list)->next = temp->next;
  if(temp->next != NULL)
    (temp->next)->befo = (*list);
  free(temp);
  return ((*list));
}
