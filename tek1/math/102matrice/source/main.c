/*
** main.c for main in /home/platel_k/projet/102matrice/source
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Sun Dec  4 09:09:59 2011 kevin platel
** Last update Sun Dec  4 16:59:02 2011 kevin platel
*/

#include <stdlib.h>
#include <stdio.h>
#include "102.h"
#include "my.h"

int	main(int ac, char ** av)
{
  int	*matrice;
  int	i;

  i = 2;
  ac < 2 ? my_printf("Give an option\n") : 42;
  ac == 2 ? my_printf("Give a base\n") : 42;
  (ac < 3) ? exit (-1) : 42;

  while (++i < ac)
    verif_base(atoi(av[2]), av[i]);

  atoi(av[1]) == 1 ? opt_one((ac - 3), &av[3], atoi(av[2])) : 42;
  atoi(av[1]) == 2 ? opt_two((ac - 3), &av[3], atoi(av[2])) : 42;
  atoi(av[1]) == 3 ? opt_three((ac - 3), &av[3], atoi(av[2])) : 42;
  atoi(av[1]) == 4 ? opt_four((ac - 3), &av[3], atoi(av[2])) : printf("Error : put a valid option\n");

  return (0);
}
