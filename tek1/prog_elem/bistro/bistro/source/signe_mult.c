/*
** signe_mult.c for signe_mult.c in /home/platel_k/projet/bistro/source
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Sat Nov  5 16:40:49 2011 kevin platel
** Last update Tue Nov  8 15:41:38 2011 matthieu przybylski
*/

#include <stdlib.h>
#include "list.h"
#include "bistromathique.h"
#include "my.h"

int	signe_mult(t_list **nb1, t_list **nb2, char *ref_op)
{
  int	signe;

  signe = 0;
  if (isop((*nb1)->cha, ref_op) == 2)
    {
      signe = signe + 1;
      del_one_in_list(nb1);
    }
  if (isop((*nb2)->cha, ref_op) == 2)
    {
      signe = signe + 1;
      del_one_in_list(nb2);
    }
  return (signe);
}

void	signe_divi(t_list **nb1, t_list **nb2, t_list **result, char *ref_op)
{
  int	signe;

  signe = 0;
  if (isop((*nb1)->cha, ref_op) == 2)
    {
      signe = signe + 1;
      del_one_in_list(nb1);
    }
  if (isop((*nb2)->cha, ref_op) == 2)
    {
      signe = signe + 1;
      del_one_in_list(nb2);
    }
  if (signe == 1)
    add_in_list(result, ref_op[3]);
}
