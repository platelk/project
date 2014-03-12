/*
** mu_put_nbr.c for my_put_nbr in /home/platel_k//projet/piscine/Jour_03
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Wed Oct  5 16:52:07 2011 kevin platel
** Last update Wed Nov 23 10:58:42 2011 kevin platel
*/

#include "my.h"

int	my_putnbr(int nb)
{
  long int   modulo;
  long int   nbr1;

  nbr1 = nb;
  modulo = 1;
  if (nb == 0)
    my_putchar('0');
  if (nb < 0)
    my_putchar('-');
  while (nbr1 >= 1 || nbr1 <= -1)
    {
      nbr1 = nbr1 / 10;
      modulo = modulo * 10;
    }
  nbr1 = nb;
  if (nb < 0)
    nbr1 = (nbr1 * (-1));
  while (modulo >= 10)
    {
      my_putchar('0' + ((nbr1 % modulo) / (modulo / 10)));
      modulo = modulo / 10;
    }
  return (0);
}
