/*
** del_us_zero.c for del_us_zero in /home/platel_k/projet/bistro/source
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Sun Nov  6 14:06:00 2011 kevin platel
** Last update Tue Nov  8 15:52:00 2011 matthieu przybylski
*/

#include <stdlib.h>
#include "list.h"
#include "bistromathique.h"
#include "my.h"

t_list	 *del_us_zero(t_list **nb, char *base)
{
  if (nb != NULL)
    {
      if ((*nb) != NULL && (*nb)->next != NULL && isnum((*nb)->cha, base) == 0)
	(*nb) = (*nb)->next;
      while ((*nb) != NULL && (*nb)->next != NULL && (*nb)->cha == base[0])
	{
	  (*nb) = del_one_in_list(nb);
	}
      while ((*nb) != NULL && (*nb)->befo != NULL)
	(*nb) = (*nb)->befo;
    }
  return ((*nb));
}
