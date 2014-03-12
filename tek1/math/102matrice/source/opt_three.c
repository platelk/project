/*
** opt_three.c for opt_three in /home/platel_k/projet/102matrice/source
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Sun Dec  4 15:49:26 2011 kevin platel
** Last update Wed Dec  7 12:28:22 2011 kevin platel
*/

#include <stdlib.h>
#include <stdio.h>
#include "102.h"
#include "my.h"

int	opt_three(int ac, char **av, int base)
{
  int	i;
  int	*matrice1;
  int	*matrice2;
  int	*matrice3;

  i = -1;
  matrice3 = malloc(2 * sizeof(int));
  if (ac < 6)
    {
      printf("Error : calcul need 6 arguments\n");
      exit (-1);
    }
  matrice1 = creat_matrice(0, av, 4, base);
  matrice2 = creat_matrice(4, av, 2, base);

  matrice3[0] = matrice2[0]*matrice1[0] + matrice2[1]*matrice1[1];
  matrice3[1] = matrice2[0]*matrice1[2] + matrice2[1]*matrice1[3];

  my_printf("Matrice A\n %s  %s\n %s  %s\n", av[0], av[1], av[2], av[3]);
  my_printf("Vecteur u\n %s \n %s\n", av[4], av[5]);
  my_printf("Matrice A.u\n ");
  my_putnbr_base(matrice3[0], get_base(base));
  my_putstr("\n ");
  my_putnbr_base(matrice3[1], get_base(base));
  my_putchar('\n');

  return (0);
}
