/*
** my_find_prime_sup.c for my_find_prime_sup in /home/platel_k//lib/c
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Mon Oct 24 10:20:38 2011 kevin platel
** Last update Wed Nov 23 10:56:12 2011 kevin platel
*/

#include "my.h"

int	my_find_prime_sup(int nbr)
{
  int	i;

  i = 0;
  while (my_is_prime(nbr + i) != 1)
    i = i + 1;
  return (i);
}
