/*
** opt_two.c for opt_two in /home/platel_k/projet/102matrice/source
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Sun Dec  4 15:39:59 2011 kevin platel
** Last update Sun Dec  4 15:48:03 2011 kevin platel
*/

#include <stdlib.h>
#include <stdio.h>
#include "102.h"
#include "my.h"

int	opt_two(int ac, char **av, int base)
{
  int	i;
  int	*matrice1;
  int	*matrice3;

  i = -1;
  matrice3 = malloc(4 * sizeof(int));
  if (ac < 5)
    {
      printf("Error : calcul need 5 arguments\n");
      exit (-1);
    }
  matrice1 = creat_matrice(1, av, 4, base);
  while (++i <= 4)
    matrice3[i] = matrice1[i] * atoi(convert_base(av[0], get_base(base), "0123456789"));
  my_printf("Matrice A\n %s  %s\n %s  %s\n", av[1], av[2], av[3], av[4]);
  my_printf("Nombre p = %s\n", av[0]);
  my_printf("Matrice p.A\n ");
  my_putnbr_base(matrice3[0], get_base(base));
  my_putstr("  ");
  my_putnbr_base(matrice3[1], get_base(base));
  my_putstr("\n ");
  my_putnbr_base(matrice3[2], get_base(base));
  my_putstr("  ");
  my_putnbr_base(matrice3[3], get_base(base));
  my_putchar('\n');

  return (0);
}
