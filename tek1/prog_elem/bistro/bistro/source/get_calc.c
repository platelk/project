/*
** get_calc.c for Bistromathique in /home/przyby_m/projet/bistro/source
** 
** Made by matthieu przybylski
** Login   <przyby_m@epitech.net>
** 
** Started on  Sun Nov  6 14:18:47 2011 matthieu przybylski
** Last update Mon Nov  7 17:43:13 2011 matthieu przybylski
*/

#include <stdlib.h>
#include "list.h"
#include "bistromathique.h"
#include "my.h"

#define		NUM_OP	ref_num, ref_op

void            get_calc(t_list **list, char *ref_num, char *ref_op)
{
  char		op;
  t_list	*nb1;
  t_list	*nb2;

  *list = (*list)->befo;
  while ((*list)->befo != NULL && isnum((*list)->cha, ref_num) == 1)
    *list = (*list)->befo;
  if ((*list)->next != NULL && isop((*list)->cha, ref_op) == 2)
    {
      *list = (*list)->next;
      op = ((*list)->befo)->cha;
    }
  else
    op = (*list)->cha;
  nb2 = take_nb(*list, ref_num);
  *list = (*list)->befo;
  while ((*list) != NULL && isnum((*list)->cha, ref_num) == 0)
    *list = (*list)->befo;
  while ((*list)->befo != NULL && isnum(((*list)->befo)->cha, ref_num) == 1)
    *list = (*list)->befo;
  if ((*list)->befo != NULL && isop(((*list)->befo)->cha, ref_op) == 2)
    *list = (*list)->befo;
  nb1 = take_nb(*list, ref_num);
  *list = replace(list, calc(nb1, isop(op, ref_op), nb2, NUM_OP), NUM_OP);
  del_par(list, ref_num, ref_op);
}

void		get_prio_calc(t_list **list, char *ref_num, char *ref_op)
{
  char		op;
  t_list	*nb1;
  t_list	*nb2;

  op = (*list)->cha;
  *list = (*list)->next;
  nb2 = take_nb(*list, ref_num);
  *list = (*list)->befo;
  while ((*list) != NULL && isnum((*list)->cha, ref_num) == 0)
    *list = (*list)->befo;
  while ((*list)->befo != NULL && isnum(((*list)->befo)->cha, ref_num) == 1)
    *list = (*list)->befo;
  if ((*list)->befo != NULL && isop(((*list)->befo)->cha, ref_op) == 2)
    *list = (*list)->befo;
  nb1 = take_nb(*list, ref_num);
  *list = replace(list, calc(nb1, isop(op, ref_op), nb2, NUM_OP), NUM_OP);
  del_par(list, ref_num, ref_op);
}
