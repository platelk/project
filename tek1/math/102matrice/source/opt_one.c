/*
** opt_one.c for opt_one in /home/platel_k/projet/102matrice/source
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Sun Dec  4 14:38:04 2011 kevin platel
** Last update Sun Dec  4 16:59:31 2011 kevin platel
*/

#include <stdlib.h>
#include <stdio.h>
#include "102.h"
#include "my.h"

int	opt_one(int ac, char **av, int base)
{
  int	i;
  int	*matrice1;
  int	*matrice2;
  int	*matrice3;

  i = -1;
  matrice3 = malloc(4 * sizeof(int));
  if (ac < 8)
    {
      printf("Error : calcul need 8 arguments\n");
      exit (-1);
    }
  matrice1 = creat_matrice(0, av, 4, base);
  matrice2 = creat_matrice(4, av, 4, base);
  while (++i <= 4)
    matrice3[i] = matrice1[i] + matrice2[i];
  my_printf("Matrice A\n %s  %s\n %s  %s\n", av[0], av[1], av[2], av[3]);
  my_printf("Matrice B\n %s  %s\n %s  %s\n", av[4], av[5], av[6], av[7]);
  my_printf("Matrice A+B\n ");
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
