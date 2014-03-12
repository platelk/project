/*
** convert_base.c for convert_base in /home/platel_k//projet/piscine/Jour_08/ex_02
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Wed Oct 12 09:43:22 2011 kevin platel
** Last update Wed Nov 23 10:55:29 2011 kevin platel
*/

#include <stdlib.h>
#include "my.h"

int     my_nbr_malloc(int nbr, char *base, int c)
{
  int   i;

  i = 0;
  while (base[i])
    i = i + 1;
  if (nbr == 0)
    return (c);
  if (nbr < 0)
    nbr = nbr * -1;
  my_nbr_malloc(nbr / i, base, c + 1);
  return (0);
}

char     *my_nbr_base(int nbr, char *base, char *new, int c)
{
  int   i;
  int	n;

  i = 0;
  n = 0;
  while (base[i])
    i = i + 1;
  if (nbr == 0)
    return (new);
  if (nbr < 0)
    nbr = nbr * (- 1);
  my_nbr_base(nbr / i, base, new, c + 1);
  new[c] = base[nbr % i];
  return (0);
}

char	*convert_base(char *nbr, char *base_from, char *base_to)
{
  int	length;
  int	j;
  int	nb;
  int	f;
  char	*new;

  f = 0;
  length = my_strlen(nbr) - 1;
  nb = 0;
  while (f < length + 1)
    {
      j = 0;
      while (nbr[f] != base_from[j])
	{
	  j = j + 1;
	}
      nb = nb + (j * my_power_rec(my_strlen(base_from), length - f));
      f = f + 1;
    }
  new = malloc(my_nbr_malloc(nb, base_to, 0));
  my_nbr_base(nb, base_to, new, 0);
  return (my_revstr(new));
}
