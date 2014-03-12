/*
** check_par.c for check_par.c in /home/platel_k/projet/bistro/source
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Fri Nov  4 15:27:09 2011 kevin platel
** Last update Mon Nov  7 16:48:40 2011 matthieu przybylski
*/

#include <stdlib.h>
#include "list.h"
#include "bistromathique.h"

#define BEFO	(begin->befo)

int	check_par(t_list *begin, char *op)
{
  int	par_op;
  int	par_clo;

  par_op = 0;
  par_clo = 0;
  while (begin != NULL)
    {
      if (isop(begin->cha, op) == 4)
	{
	  par_op = par_op + 1;
	  if (isop((begin->next)->cha, op) == 5)
	    return (1);
	  if (BEFO != NULL)
	    if (isop(BEFO->cha, op) == 5 || isop(BEFO->cha, op) == -1)
	      return (1);
	}
      if (isop(begin->cha, op) == 5)
	par_clo = par_clo + 1;
      begin = begin->next;
    }
  if (par_op != par_clo)
    return (1);
  return (0);
}
