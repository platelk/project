/*
** my_putnbr_base.c for my_putnbr_base in /home/platel_k//projet/piscine/Jour_6
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Mon Oct 10 16:43:15 2011 kevin platel
** Last update Wed Nov 23 11:01:52 2011 kevin platel
*/

#include "my.h"

#define ABS(x)	(x < 0)? x = (x * (-1)): x

int	my_putnbr_base(int nbr, char *base)
{
  if (nbr == 0)
    {
      my_putchar(base[0]);
      return (0);
    }
  my_putnbr_int_base(nbr, base);
  return (0);
}

int	my_putnbr_int_base(int nbr, char *base)
{
  int	i;

  i = 0;
  while (base[i])
      i = i + 1;
  if (nbr == 0)
    return (0);
  if (nbr < 0)
    my_putchar('-');
  my_putnbr_int_base(ABS(nbr) / i, base);
  my_putchar(base[ABS(nbr) % i]);
  return (0);
}
