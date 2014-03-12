/*
** remaining_op.c for Bistromathique in /home/przyby_m/projet/bistro
** 
** Made by matthieu przybylski
** Login   <przyby_m@epitech.net>
** 
** Started on  Tue Nov  1 11:18:23 2011 matthieu przybylski
** Last update Sat Nov  5 00:54:19 2011 matthieu przybylski
*/

#include <stdlib.h>
#include "list.h"
#include "bistromathique.h"

/*
** RETURN VALUES :
** if there's an op in the list gave in parameter,
** remaining_op returns 1. Else, it returns 0.
*/

int		remaining_op(t_list *begin, char *ref_op)
{
  t_list	*temp;
  int		i;

  i = 0;
  temp = begin;
  while (temp->befo != NULL)
    temp = temp->befo;
  while (temp->next != NULL)
    {
      if (isop(temp->cha, ref_op) != 2 && isop(temp->cha, ref_op) > 0)
	return (1);
      else if (temp->befo != NULL && isop(temp->cha, ref_op) == 2)
	{
	  i = i + 1;
	  if (isnum((temp->befo)->cha, "0123456789") == 1)
	    return (1);
	}
      if (i == 2)
	return (1);
      temp = temp->next;
    }
  return (0);
}

/*
** RETURN VALUES :
** if there's an op in the parenthesis choosen
** in the list gave in parameter, remaining_op
** returns 1. Else, it returns 0.
*/


int		remaining_op_par(t_list **begin, char *ref_op, char *ref_num)
{
  *begin = (*begin)->next;
  if (isop((*begin)->cha, ref_op) == 2)
    *begin = (*begin)->next;
  while ((*begin)->next != NULL && isnum((*begin)->cha, ref_num) == 1)
    *begin = (*begin)->next;
  if (isop((*begin)->cha, ref_op) == 5)
    return (0);
  else
    return (1);
}
