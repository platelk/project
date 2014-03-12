/*
** verif_base.c for verif_base in /home/platel_k/projet/102matrice/source
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Sun Dec  4 15:09:46 2011 kevin platel
** Last update Sun Dec  4 15:30:20 2011 kevin platel
*/

#include <stdlib.h>
#include <stdio.h>
#include "102.h"
#include "my.h"

int	verif_base(int base, char *str)
{
  int	i;
  char	*base_ref;
  int	j;

  i = -1;
  base_ref = get_base(base);
  while (str[++i])
    {
      j = -1;
      while (base_ref[++j] != 0 && str[i] != base_ref[j]);
      if (!(base_ref[j]))
	{
	  printf("Error : %c is not in base\n", str[i]);
	  exit (-1);
	}
    }
  return (1);
}
