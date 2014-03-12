/*
** my_rev_params.c for my_rev_params in /home/platel_k//projet/piscine/Jour_07/ex_03
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Tue Oct 11 14:13:59 2011 kevin platel
** Last update Wed Nov 23 11:03:24 2011 kevin platel
*/

#include "my.h"

int	my_rev_param(int argc, char **argv)
{
  int	i;

  i = 0;
  while ((argc - i) != 0)
    {
      my_putstr(argv[argc - i - 1]);
      my_putchar('\n');
      i = i + 1;
    }
  return (0);
}
