/*
** check_op.c for check_op in /home/platel_k/projet/bistro/source
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Fri Nov  4 10:21:36 2011 kevin platel
** Last update Mon Nov  7 16:40:08 2011 matthieu przybylski
*/

#include <stdlib.h>
#include "list.h"
#include "bistromathique.h"
#include "my.h"

int	check_op(t_list *begin, char *num, char *op)
{
  while (begin->befo != NULL)
    begin = begin->befo;
  if ((isop(begin->cha, op) % 7) == 0 || isop(begin->cha, op) == 5)
    return (1);
  while (begin->next != NULL)
    begin = begin ->next;
  if (isnum(begin->cha, num) == 1 || isop(begin->cha, op) == 5)
    return (0);
  else
    return (1);
}
