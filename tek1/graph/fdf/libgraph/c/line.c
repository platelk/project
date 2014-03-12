/*
** line.c for line in /home/platel_k/projet/minilibX/lib_libx
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Wed Nov  9 13:43:04 2011 kevin platel
** Last update Wed Dec  7 16:57:55 2011 kevin platel
*/

#include <stdlib.h>
#include "point.h"
#include "mlx.h"
#include "my_libX.h"

#define WIN	(my_ptr->win_ptr)
#define MLX	(my_ptr->mlx_ptr)
#define Y1	point->y
#define Y2	point2->y
#define X1	point->x
#define X2	point2->x
#define CALC_Y  Y1 + ((Y2 - Y1) * (x - X1))/(X2 - X1)

void	line(t_my_ptr *my_ptr, t_point *point, t_point *point2)
{
  int	x;
  int	y;
  int	signe_x;
  int	signe_y;

  signe_x = 1;
  signe_y = 1;
  if (X1 > X2)
    signe_x = signe_x * -1;
  if (Y1 > Y2)
    signe_y = signe_y * -1;
  x = X1;
  while (x != X2)
    {
      mlx_pixel_put(MLX, WIN, x, CALC_Y, point2->color);
      y = CALC_Y;
      while (y != Y1 + ((Y2 - Y1) * ((x + signe_x)- X1)) / (X2 - X1))
	{
	  mlx_pixel_put(MLX, WIN, x, y, point2->color);
	  y = y + signe_y;
	}
      x = x + signe_x;
    }
}
