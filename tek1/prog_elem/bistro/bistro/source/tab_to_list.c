/*
** tab_to_list.c for ta_to_list in /home/przyby_m/projet/bistro/source
** 
** Made by matthieu przybylski
** Login   <przyby_m@epitech.net>
** 
** Started on  Tue Nov  1 13:25:26 2011 matthieu przybylski
** Last update Sat Nov  5 15:28:49 2011 kevin platel
*/

#include <stdlib.h>
#include "list.h"
#include "bistromathique.h"

/*
** GOAL :
** Take the content of a string except invalid character
** to create (and fill) a list with it.
*/

void	tab_to_list(t_list **begin, char *expr, char *ref_num, char *ref_op)
{
  int	i;

  *begin = NULL;
  i = 0;
  while (expr[i] != '\0')
    {
      if (isnum(expr[i], ref_num) == 1 || isop(expr[i], ref_op) > 0)
	*begin = add_in_list(begin, expr[i]);
      i = i + 1;
    }
}
