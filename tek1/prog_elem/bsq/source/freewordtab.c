/*
** freewordtab.c for freewordtab.c in /home/platel_k/projet/fdf
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Thu Nov 17 17:22:54 2011 kevin platel
** Last update Fri Dec  9 14:58:19 2011 kevin platel
*/

#include <stdlib.h>
#include "bsq.h"

void	freewordtab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != 0)
    {
      free(tab[i]);
      i++;
    }
}
