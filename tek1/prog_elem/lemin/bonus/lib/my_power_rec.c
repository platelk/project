/*
** my_power_rec.c for my_power_rec in /home/leprov_a//piscine/Jour_05
**
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
**
** Started on  Fri Oct  7 16:34:17 2011 alexis leprovost
** Last update Mon Apr  2 09:26:10 2012 alexis leprovost
*/

#include	<stdlib.h>

#include	"my.h"

int	my_power_rec(int nb, int power)
{
  if (nb == 1 || power == 0)
    return (EXIT_FAILURE);
  else if (power < 0 || nb == 0 || (nb > 1 && power > 30))
    return (EXIT_SUCCESS);
  else
    {
      if (power == 1)
	return (nb);
      return (nb * my_power_rec(nb, power - 1));
    }
}
