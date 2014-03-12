/*
** project.c for project in /home/platel_k/projet/bsq/source
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Thu Dec  8 11:22:43 2011 kevin platel
** Last update Fri Dec  9 15:01:47 2011 kevin platel
*/

#include <stdlib.h>
#include "my.h"
#include "bsq.h"

int	project(char **data, int x, int y, char direc)
{
  int	max;
  int	i;
  int	j;

  i = y;
  j = x;
  max = 0;
  while (data[i] != NULL && data[i][j] != '\0' && data[i][j] != 'o')
    {
      if (direc == 'x')
	j++;
      if (direc == 'y')
	i++;
      max++;
    }
  return (max);
}
