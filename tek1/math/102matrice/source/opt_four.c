/*
** opt_four.c for opt_four in /home/platel_k/projet/102matrice/source
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Sun Dec  4 16:18:54 2011 kevin platel
** Last update Sun Dec  4 16:54:59 2011 kevin platel
*/

#include <stdlib.h>
#include <stdio.h>
#include "102.h"
#include "my.h"

int	opt_four(int ac, char **av, int base)
{
  int	i;
  int	j;
  int	*matrice1;
  int	*matrice2;
  int	*matrice3;

  i = -1;
  matrice3 = malloc(2 * sizeof(int));
  if (ac < 8)
    {
      printf("Error : calcul need 8 arguments\n");
      exit (-1);
    }
  matrice1 = creat_matrice(0, av, 4, base);
  matrice2 = creat_matrice(4, av, 4, base);

  my_printf("Matrice A\n %s  %s\n %s  %s\n", av[0], av[1], av[2], av[3]);
  my_printf("Matrice B\n %s  %s\n %s  %s\n", av[4], av[5], av[6], av[7]);
  
  my_printf("Matrice A.B\n ");

  matrice3[0] = matrice1[0] * matrice2[0] + matrice1[1] * matrice2[2];
  matrice3[1] = matrice1[0] * matrice2[1] + matrice1[1] * matrice2[3];
  matrice3[2] = matrice1[2] * matrice2[0] + matrice1[3] * matrice2[2];
  matrice3[3] = matrice1[2] * matrice2[1] + matrice1[3] * matrice2[3];

  my_putnbr_base(matrice3[0], get_base(base));
  my_putstr("  ");
  my_putnbr_base(matrice3[1], get_base(base));
  my_putstr("\n ");
  my_putnbr_base(matrice3[2], get_base(base));
  my_putstr("  ");
  my_putnbr_base(matrice3[3], get_base(base));
  my_putchar('\n');

  my_printf("Matrice B.A\n ");
  matrice3[0] = matrice1[0] * matrice2[0] + matrice1[2] * matrice2[1];
  matrice3[1] = matrice1[1] * matrice2[0] + matrice1[3] * matrice2[1];
  matrice3[2] = matrice1[0] * matrice2[2] + matrice1[2] * matrice2[3];
  matrice3[3] = matrice1[1] * matrice2[2] + matrice1[3] * matrice2[3];
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
