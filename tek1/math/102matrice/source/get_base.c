/*
** get_base.c for get_base in /home/platel_k/projet/102matrice/source
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Sun Dec  4 10:49:01 2011 kevin platel
** Last update Wed Dec  7 11:54:44 2011 kevin platel
*/

#include <stdio.h>
#include <stdlib.h>
#include "102.h"
#include "my.h"

char	*get_base(int base)
{
  char	*base_ref;
  char	*base_ret;
  int	i;

  if (base > 16)
    {
      my_printf("Error : %d is an invalid base\n", base);
      exit(1);
    }
  i = -1;
  base_ref = "0123456789ABCDEF";
  base_ret = malloc(base * sizeof(char));
  if (base < 2)
    {
      printf("Erreur %d est trop petit", base);
      exit(1);
    }
  while (++i < base && base_ref[i] != '\0')
    base_ret[i] = base_ref[i];
  if (base_ref == '\0')
    {
      printf("Erreur %d est superieur a 16", base);
      exit(1);
    }
  return (base_ret);
}
