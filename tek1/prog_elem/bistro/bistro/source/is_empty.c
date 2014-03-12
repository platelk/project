/*
** is_empty.c for is_empty in /home/platel_k/projet/bistro/source
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Fri Nov  4 09:57:52 2011 kevin platel
** Last update Mon Nov  7 15:56:28 2011 matthieu przybylski
*/
#include <stdlib.h>
#include "list.h"
#include "bistromathique.h"
#include "my.h"

/*
** RETURN VALUES :
** 0 if there's at least one valid character.
** 1 if there's no one.
*/

int	is_empty(char *expr, char *num, char *op)
{
  int	i;

  i = 0;
  while (expr[i])
    {
      if (isop(expr[i], op) > 0 || isnum(expr[i], num) != 0)
	return (0);
      i = i + 1;
    }
  my_putstr("ERROR : No one valid character !\n");
  return (1);
}
