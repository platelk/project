/*
** img_line.c for img_line in /home/platel_k/projet/minilibX/tp1/tp1_window_empty
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Wed Nov 23 14:36:06 2011 kevin platel
** Last update Sat Jan 14 23:42:53 2012 kevin platel
*/

#include <stdlib.h>
#include "point.h"
#include "my_libX.h"
#include "mlx.h"

#define Y1	(point->y)
#define Y2	(point2->y)
#define X1	(point->x)
#define X2	(point2->x)
#define X	(pixel->x)
#define Y	(pixel->y)
#define CALC_Y  Y1 + ((Y2 - Y1) * ((pixel->x) - X1)) / ( X2 - X1)

void	img_line(void *mlx_ptr, t_imag *img, t_point *point, t_point *point2)
{
  int		signe_x;
  int		signe_y;
  t_point	*pixel;

  if (X1 == X2)
    draw_line_vec(mlx_ptr, img, point, point2);
  else
    {
      X1 > X2 ? (signe_x = -1): (signe_x = 1);
      Y1 > Y2 ? (signe_y = -1): (signe_y = 1);
      pixel = init_point(X1, Y1, point->color);
      while (X != X2)
	{
	  mlx_ppti(mlx_ptr, img, pixel);
	  Y = CALC_Y;
	  while (Y != Y1 + ((Y2 - Y1) * ((X + signe_x)- X1)) / (X2 - X1))
	    {
	      mlx_ppti(mlx_ptr, img, pixel);
	      pixel->y = pixel->y + signe_y;
	    }
	  pixel->x = pixel->x + signe_x;
	}
    }
}

void	draw_line_vec(void *mlx, t_imag *img, t_point *point, t_point *point2)
{
  int	signe_y;
  t_point	*pixel;

  signe_y = 1;
  pixel = init_point(X1, Y1, point->color);
  if (Y1 > Y2)
    signe_y = signe_y * -1;
  while (Y1 != Y2)
    {
      mlx_ppti(mlx, img, pixel);
      pixel->y = pixel->y + signe_y;
    }
  free(pixel);
}
