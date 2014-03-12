/*
** create_matrix.c for 103homogene
** 
** Made by matthieu przybylski
** Login   <przyby_m@epitech.net>
** 
** Started on  Thu Dec 15 16:18:13 2011 matthieu przybylski
** Last update Thu Dec 15 17:19:29 2011 matthieu przybylski
*/

#include <stdlib.h>
#include <stdio.h>
#include "103homogene.h"

float		*create_matrix(int **pars)
{
  static int	i;

  if (pars[i] == NULL)
    return (NULL);
  i++;
  if (pars[i - 1][0] == 'T')
    return (translation(pars[i - 1]));
  else if (pars[i - 1][0] == 'H')
    return (homotetie(pars[i - 1]));
  else if (pars[i - 1][0] == 'R')
    return (rotation(pars[i - 1]));
  else if (pars[i - 1][0] == 'S')
    return (symetrie(pars[i - 1]));
  else
    {
      printf("Erreur : Option inconnu rencontré\n");
      return (NULL);
    }
}
