/*
** del_useless_par.c for Bistromathique in /home/przyby_m/projet/bistro/source
** 
** Made by matthieu przybylski
** Login   <przyby_m@epitech.net>
** 
** Started on  Sat Nov  5 10:32:58 2011 matthieu przybylski
** Last update Sat Nov  5 12:11:52 2011 matthieu przybylski
*/

#include <stdlib.h>
#include "list.h"
#include "bistromathique.h"

#define		NO_NULL		temp->next != NULL && (*list)->befo != NULL
#define		BE4_PAR_OPEN	isop(((*list)->befo)->cha, ref_op) == 4
#define		NXT_PAR_CLOSE	isop((temp->next)->cha, ref_op) == 5

void		del_useless_par(t_list **list, char *ref_num, char *ref_op)
{
  t_list	*temp;
  int		ret;

  ret = 1;
  while (ret)
    {
      ret = del_par(list, ref_num, ref_op);
      if (ret == 0)
	{
	  while ((*list)->next != NULL && isop((*list)->cha, ref_op) != 5)
	    *list = (*list)->next;
	  temp = *list;
	  while ((*list)->befo != NULL && isop((*list)->cha, ref_op) != 4)
            *list = (*list)->befo;
	  if (NO_NULL && BE4_PAR_OPEN && NXT_PAR_CLOSE)
	    {
	      *list = (*list)->befo;
	      temp = temp->next;
	      del_one_in_list(list);
	      del_one_in_list(&temp);
	      ret = 1;
	    }
	}
    }
}
