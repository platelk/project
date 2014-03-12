/*
** replace.c for bistro in /home/przyby_m/projet/bistro/source
** 
** Made by matthieu przybylski
** Login   <przyby_m@epitech.net>
** 
** Started on  Thu Nov  3 14:15:05 2011 matthieu przybylski
** Last update Sat Nov  5 11:38:15 2011 matthieu przybylski
*/

#include <stdlib.h>
#include "list.h"
#include "bistromathique.h"
#include "my.h"

void		put_result(t_list **list, t_list *new, char *ref_op)
{
  if (*list == NULL)
    {
      *list = init_list(list, new->cha);
      new = new->next;
    }
  else if (*list != NULL && (*list)->befo == NULL)
    {
      *list = add_before_list(list, new->cha);
      new = new->next;
    }
  if ((*list)->befo != NULL && isop((*list)->cha, ref_op) == 5)
    *list = (*list)->befo;
  else if (*list != NULL && (*list)->befo != NULL && (*list)->next != NULL)
    *list = (*list)->befo;
  while (new != NULL)
    {
      add_one_in_list(list, new->cha);
      *list = (*list)->next;
      new = new->next;
    }
  if ((*list)->next != NULL)
    ((*list)->next)->befo = (*list);
}

t_list          *replace(t_list **list, t_list *new, char *refnum, char *ref_op)
{
  t_list        *begin;

  begin = *list;
  while ((*list)->next != NULL && isnum(((*list)->next)->cha, refnum) == 1)
    *list = (*list)->next;
  while ((*list)->next != NULL && isnum(((*list)->next)->cha, refnum) == 0)
    *list = (*list)->next;
  while ((*list)->next != NULL && isnum(((*list)->next)->cha, refnum) == 1)
    *list = (*list)->next;
  *list = del_in_list(&begin, list);
  put_result(list, new, ref_op);
  while ((*list)->befo != NULL)
    (*list) = (*list)->befo;
  return (*list);
}
