/*
** img_line.c for img_line in /home/platel_k/projet/minilibX/tp1/tp1_window_empty
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Wed Nov 23 14:36:06 2011 kevin platel
** Last update Wed Nov 23 15:40:01 2011 kevin platel
*/

#include "point.h"
#include <stdlib.h>
#include "my_libX.h"
#include "mlx.h"

#define Y1	(point->y)
#define Y2	(point2->y)
#define X1	(point->x)
#define X2	(point2->x)
#define CALC_Y  Y1 + ((Y2 - Y1) * ((pixel->x) - X1)) / ( X2 - X1)

void	img_line(void *mlx_ptr,t_img *img, t_point *point, t_point *point2)
{
  int		signe_x;
  int		signe_y;
  t_point	*pixel;

  signe_x = 1;
  signe_y = 1;
  pixel = init_point(X1, Y1, point->color);
  if (X1 > X2)
    signe_x = signe_x * -1;
  if (Y1 > Y2)
    signe_y = signe_y * -1;
  while (pixel->x != X2)
    {
      mlx_ppti(mlx_ptr, img, pixel);
      pixel->y = CALC_Y;
      while (pixel->y != Y1 + ((Y2 - Y1) * ((pixel->x + signe_x)- X1)) / (X2 - X1))
	{
	  mlx_ppti(mlx_ptr, img, pixel);
	  pixel->y = pixel->y + signe_y;
	}
      pixel->x = pixel->x + signe_x;
    }
}
