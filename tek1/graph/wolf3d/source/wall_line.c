/*
** wall_line.c for wall_line in /home/platel_k/projet/graph/wolf3d/source
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Fri Jan  6 19:33:22 2012 kevin platel
** Last update Sat Jan  7 11:23:21 2012 kevin platel
*/

#include <stdlib.h>
#include "mlx_int.h"
#include "mlx.h"
#include "my.h"
#include "point.h"
#include "my_libX.h"
#include "wolf.h"
#include "decor.h"

#define COLOR_WALL	0x000000FF

void	wall_line(void *mlx_ptr, int k, int x, t_imag *wall)
{
  t_point	*point1;
  t_point	*point2;

  if (k != 0)
    {
      point1 = init_point(x, 500 + (1000 / (2 * (k / 14000))), COLOR_WALL);
      point2 = init_point(x, 500 - (1000 / (2 * (k / 14000))), COLOR_WALL);
    }
  else
    {
      point1 = init_point(x, (1000), COLOR_WALL);
      point2 = init_point(x, (0), COLOR_WALL);
    }
  img_line(mlx_ptr, wall, point1, point2);
}
