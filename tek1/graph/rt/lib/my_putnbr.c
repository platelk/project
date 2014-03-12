/*
** my_putnbr.c for my in /home/leprov_a//bdd/my
**
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
**
** Started on  Mon Apr 30 16:42:56 2012 alexis leprovost
** Last update Thu Jan 31 11:59:41 2013 kevin platel
*/

#include	"my.h"

void	my_putnbr(int nb)
{
  int	pow;

  pow = 1;
  if (nb < 0)
    {
      my_putchar('-');
      nb *= (-1);
    }
  while ((nb / pow) > 9)
    pow *= 10;
  while (pow > 0)
    {
      my_putchar((nb / pow) % 10 + 48);
      pow /= 10;
    }
}
