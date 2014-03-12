/*
** my_putnbr_base.c for my_putnbr_base in /home/platel_k//projet/piscine/Jour_6
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Mon Oct 10 16:43:15 2011 kevin platel
** Last update Mon Dec 19 09:24:59 2011 kevin platel
*/

#include "my.h"

int	my_putul_nbr(unsigned long int nbr, char *base)
{
  int	i;

  i = 0;
  while (base[i])
    i = i + 1;
  if (nbr == 0)
    return (0);
  my_putul_nbr(nbr / i, base);
  my_putchar(base[nbr % i]);
  return (0);
}

int	my_putnbrul_base(unsigned long int nbr, char *base)
{
  if (nbr == 0)
    {
      my_putchar(base[0]);
      return (0);
    }
  my_putul_nbr(nbr, base);
  return (0);
}
