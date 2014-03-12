/*
** val_cha.c for val_cha in /home/platel_k/projet/bistro/source
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Thu Nov  3 17:56:22 2011 kevin platel
** Last update Mon Nov  7 15:58:59 2011 matthieu przybylski
*/

#include <stdlib.h>
#include "list.h"
#include "bistromathique.h"
#include "my.h"

/*
** GOAL :
** val_cha inform the user that his expression contains
** invalid characters who will be deleted.
**
** RETURN VALUE :
** in any case, val_cha returns 0.
*/

int	val_cha(char *begin, char *ref_num,char *ref_op)
{
  int	i;

  i = 0;
  while (begin[i])
    {
      if (isop(begin[i], ref_op) == -1 && isnum(begin[i], ref_num) == 0)
	{
	  my_putstr("WARNING : Invalid character are delete for calcul\n");
	  return (0);
	}
      i = i + 1;
    }
  return (0);
}
