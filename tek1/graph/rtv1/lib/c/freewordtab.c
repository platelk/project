/*
** freewordtab.c for freewordtab.c in /home/platel_k/projet/fdf
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Thu Nov 17 17:22:54 2011 kevin platel
** Last update Wed Feb  8 13:12:50 2012 kevin platel
*/

#include <stdlib.h>
#include "my.h"

void	freewordtab(char **tab)
{
  int	i;

  i = 0;
  while (tab != NULL && tab[i] != NULL)
    {
      free((tab[i]));
      i++;
    }
  free(tab);
}
