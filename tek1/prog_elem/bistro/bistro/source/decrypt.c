/*
** decrypt.c for Bistromathique in /home/przyby_m/projet/bistro/source
**
** Made by matthieu przybylski
** Login   <przyby_m@epitech.net>
**
** Started on  Sat Nov  5 12:15:59 2011 matthieu przybylski
** Last update Fri Nov  2 10:26:52 2012 kevin platel
*/

#include <stdlib.h>
#include "list.h"
#include "bistromathique.h"

#define	OP	isop((*list)->cha, op) > 0
#define	NO_PAR	isop((*list)->cha, op) != 4 && isop((*list)->cha, op) != 5
#define P_OR_M	isop((*list)->cha, op) == 2 || isop((*list)->cha, op) == 1
#define NXT	((*list)->next)

#define PRIO(x)	(isop(x, op) % 7 == 0)
#define NUM(x)	isnum(x, num) == 1
#define	ISOP(x)	isop((x)->cha, op) > 0

void		put_sign(t_list **list, int count, char *op, char *num)
{
  t_list	*end;
  char		operator;

  if ((*list)->befo != NULL && isop((*list)->cha, op) == 4)
    *list = (*list)->befo;
  end = *list;
  while ((*list)->befo != NULL && OP && NO_PAR)
    *list = (*list)->befo;
  if (/*(*list)->befo != NULL &&*/ (*list)->next != NULL)
    *list = (*list)->next;
  if (NUM((*list)->cha))
    {
      *list = (*list)->next;
    }
  operator = (*list)->cha;
  *list = (*list)->next;
  if ((count % 2) == 0)
    {
      *list = del_in_list(list, &end);
      ///
      while ((*list)->befo != NULL)
	*list = (*list)->befo;
      ///
    }
  else
    {
      if (operator == op[2])
	*list = (*list)->befo;
      *list = del_in_list(list, &end);
      add_before_list(list, op[3]);
    }
}

int		count_less(t_list **list, char *op, char *num)
{
  int		count;

  if (((*list)->befo)->cha == op[3] && ((*list)->befo)->cha == op[2])
    {
      *list = (*list)->befo;
    }
  if (!(P_OR_M))
    *list = (*list)->next;

  count = 0;
  while (((*list)->next != NULL) && OP)
    {
      if ((isop((*list)->cha, op) % 7) == 0 || isop((*list)->cha, op) == 5)
	return (-1);
      if (isop((*list)->cha, op) == 4)
	{
	  if (isop(NXT->cha, op) == 2)
	    *list = (*list)->next;
	  if (isnum(NXT->cha, num) != 1)
	    return (-1);
	}
      if (isop((*list)->cha, op) == 2)
	count = count + 1;
      *list = (*list)->next;
    }
  if ((*list)->befo != NULL)
    *list = (*list)->befo;

  put_sign(list, count, op, num);
  return (0);
}

int		is_decrypted(t_list **list, char *op, char *num)
{
  while ((*list)->befo != NULL)
    *list = (*list)->befo;

  while ((*list)->next != NULL)
    {
      if ((NXT != NULL) && OP && NO_PAR)
	{
	  *list = NXT;
	  if (!(P_OR_M) && (NO_PAR) && isnum((*list)->cha, num) == 0)
	    return (-1);
	  else if ((P_OR_M) && (!(PRIO(((*list)->befo)->cha))))
	    {
	      if (!(NUM(NXT->cha)))
		return (0);
	    }
	  else if ((P_OR_M) || !(NO_PAR))
	    {
	      *list = (*list)->befo;
	      return (0);
	    }
	}
      if (NXT != NULL)
	*list = (*list)->next;
    }
  return (1);
}

int		decrypt(t_list **list, char *op, char *num)
{
  int		finish;

  finish = is_decrypted(list, op, num);
  if (finish == -1)
    return (-1);
  while (finish  == 0)
    {
      while ((*list)->next != NULL && isnum(((*list)->next)->cha, num) == 1)
	*list = (*list)->next;
      if((*list)->next != NULL)
	*list = (*list)->next;
      if (OP && NO_PAR && count_less(list, op, num) != 0)
	return (-1);
      finish = is_decrypted(list, op, num);
      if (finish == -1)
	return (-1);
    }
  while ((*list)->befo != NULL)
    *list = (*list)->befo;
  return (0);
}
