/*
** project_x.c for project_x in /home/platel_k/projet/bsq/source
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Fri Dec  9 11:01:35 2011 kevin platel
** Last update Fri Dec  9 17:21:21 2011 kevin platel
*/

#include <stdlib.h>
#include "my.h"
#include "bsq.h"

int	project_on_x(char **data, int x, int y)
{
  int	max;

  max = 0;
  while (data[y] != NULL && data[y][x] != '\0' && data[y][x] != 'o')
    {
      x++;
      max++;
    }
  return (max);
}

int	project_on_y(char **data, int x, int y, int max)
{
  int	max_y;

  max_y = 0;
  while (data[y] != NULL && data[y][x] != 0 && data[y][x] != 'o')
    {
      y++;
      max_y++;
      if (max_y > max)
	return (max_y);
    }
  return (max_y);
}
