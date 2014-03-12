/*
** find_square.c for find_square in /home/platel_k/projet/bsq/source
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Thu Dec  8 13:02:05 2011 kevin platel
** Last update Sun Dec 11 13:33:11 2011 kevin platel
*/

#include "bsq.h"

int	find_square(char **data, int x, int y, int size)
{
  int		project_x;
  int		project_y;
  int		decal;
  int		big_size;

  decal = 0;
  project_x = project_on_x(data, x, y);
  big_size = size;
  size = 0;
  if (project_x > 0 && project_x < size)
    return (big_size);
  while ((decal < project_x) && project_x > size)
    {
      project_y = project_on_y(data, x + decal, y, project_x);
      decal <= project_y && project_y > size ? size++ : 42;
      project_y < project_x ? project_x = project_y : 42;
      decal++;
    }
  if (size > big_size)
    return (size);
  else
    if (size - 1 >= 0 && size > 2)
      return (size - 1);
    else
      return (0);
}
