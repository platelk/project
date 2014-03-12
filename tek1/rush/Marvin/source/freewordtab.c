/*
** freewordtab.c for freewordtab.c in /home/platel_k/projet/fdf
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Thu Nov 17 17:22:54 2011 kevin platel
** Last update Sat Nov 26 18:10:32 2011 kevin platel
*/

#include <string.h>
#include <stdlib.h>

void	freewordtab(char ***tab)
{
  int	i;

  i = 0;
  while (*tab[i] != NULL)
    {
      free(*tab[i]);
      i++;
    }
}
