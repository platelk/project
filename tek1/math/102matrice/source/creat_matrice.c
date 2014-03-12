/*
** creat_matrice.c for creat_matrice in /home/platel_k/projet/102matrice/source
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Sun Dec  4 10:20:01 2011 kevin platel
** Last update Sun Dec  4 16:59:34 2011 kevin platel
*/

#include <stdlib.h>
#include "my.h"
#include "102.h"

int	*creat_matrice(int ac, char **av, int dim, int base)
{
  int	i;
  int	*matrice;

  matrice = malloc(dim * sizeof(int));
  i = -1;

  while ((++i + ac) < ((ac + dim)))
    matrice[i] = atoi(convert_base(av[ac + i], get_base(base), "0123456789"));
  return (matrice);
}
