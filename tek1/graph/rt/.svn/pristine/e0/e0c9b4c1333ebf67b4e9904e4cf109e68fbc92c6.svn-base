/*
** my_putnbr_base.c for my_putnbr_base in /home/leprov_a//project/maths/102matrice
**
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
**
** Started on  Thu Nov 24 21:07:30 2011 alexis leprovost
** Last update Sun Jun  3 11:29:28 2012 kevin platel
*/

#include	<stdlib.h>

#include	"my.h"

int     my_putnbr_base(int nbr, char *base)
{
  static int zero;

  if (zero == 0 && nbr == 0)
    {
      my_putchar('0');
      return (0);
    }
  zero = 42;
  if (nbr < 0)
    {
      nbr = nbr * (-1);
      my_putchar('-');
    }
  if (nbr == 0)
    return (nbr);
  my_putnbr_base(nbr / my_strlen(base), base);
  my_putchar(base[nbr % my_strlen(base)]);
  zero = 0;
  return (EXIT_SUCCESS);
}
