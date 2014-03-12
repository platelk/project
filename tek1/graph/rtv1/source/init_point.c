/*
** init_point.c for init_point in /home/platel_k/projet/minilibX/tp1/tp1_window_empty
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Wed Nov  9 14:21:58 2011 kevin platel
** Last update Thu Feb 23 17:46:28 2012 kevin platel
*/

#include <stdlib.h>
#include "point.h"
#include "mlx.h"
#include "mlx_int.h"
#include "my_libX.h"

t_point		*init_point(double x, double y, double z, int color)
{
  t_point	*new_point;

  new_point = malloc(sizeof(*new_point));
  if (new_point == NULL)
    return (NULL);
  new_point->x = x;
  new_point->y = y;
  new_point->z = z;
  new_point->color = color;

  return (new_point);
}
