/*
** my_is_prime.c for my_is_prime in /home/platel_k//lib/c
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Mon Oct 24 10:16:38 2011 kevin platel
** Last update Wed Nov 23 10:57:14 2011 kevin platel
*/

#include "my.h"

int	my_is_prime(int nbr)
{
  int	i;

  i = 2;
  while (((nbr % i) != 0) && i < my_square_root(nbr))
    i = i + 1;
  if ((nbr % i) == 0)
    return (0);
  return (1);
}
