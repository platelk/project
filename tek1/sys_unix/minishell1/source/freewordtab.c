/*
** freewordtab.c for freewordtab.c in /home/platel_k/projet/fdf
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Thu Nov 17 17:22:54 2011 kevin platel
** Last update Fri Dec 30 22:41:15 2011 kevin platel
*/

#include <stdlib.h>
#include "minishell.h"
#include "env.h"
#include "my.h"

char	**freewordtab(char **tab)
{
  int	i;

  i = 0;
  while (tab != NULL && tab[i] != NULL)
    {
      free((tab[i]));
      i++;
    }
  return (tab);
}
