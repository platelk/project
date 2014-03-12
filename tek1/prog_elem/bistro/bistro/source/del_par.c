/*
** del_par.c for bistro in /home/przyby_m/projet/bistro/source
** 
** Made by matthieu przybylski
** Login   <przyby_m@epitech.net>
** 
** Started on  Fri Nov  4 15:28:52 2011 matthieu przybylski
** Last update Sat Nov  5 11:00:08 2011 matthieu przybylski
*/

#include <stdlib.h>
#include "list.h"
#include "bistromathique.h"

#define NO_OP_IN_PAR	remaining_op_par(list, ref_op, ref_num) == 0

/*
** RETURN VALUES :
** if parenthesis are deleted, del_par will return 1.
** Else, it will return 0.
*/

int    del_par(t_list **list, char *ref_num, char *ref_op)
{
  while ((*list)->next != NULL && isop((*list)->cha, ref_op) != 5)
    *list = (*list)->next;
  while ((*list)->befo != NULL && isop((*list)->cha, ref_op) != 4)
    *list = (*list)->befo;
  if (isop((*list)->cha, ref_op) == 4 && NO_OP_IN_PAR)
    {
      while ((*list)->next != NULL && isop((*list)->cha, ref_op) != 5)
        *list = (*list)->next;
      del_one_in_list(list);
      while ((*list)->befo != NULL && isop((*list)->cha, ref_op) != 4)
        *list = (*list)->befo;
      del_one_in_list(list);
      if ((*list)->befo != NULL)
	*list = (*list)->befo;
      while ((*list)->befo != NULL)
	*list = (*list)->befo;
      return (1);
    }
  while ((*list)->befo != NULL)
    *list = (*list)->befo;
  return (0);
}
