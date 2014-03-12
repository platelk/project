/*
** clean.c for clean in /home/platel_k/projet/fdf/source
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Fri Dec  9 23:42:02 2011 kevin platel
** Last update Fri Feb 17 15:26:08 2012 kevin platel
*/

#include "my_libX.h"
#include "grille.h"
#include "point.h"
#include "mlx.h"

void	clean_img(void *mlx_ptr, t_imag *img)
{
  t_point	*point;

  point = init_point(0, 0, 0, 0x003366FF);
  while (point->x < 1000)
    {
      point->y = 0;
      while (point->y < 500)
	{
	  mlx_ppti(mlx_ptr, img, point);
	  point->y = point->y + 1;
	}
      point->x = point->x + 1;
    }
  point->x = 0;
  point->color = 0x00888888;
  while (point->x < 1000)
    {
      point->y = 500;
      while (point->y < 1000)
	{
	  mlx_ppti(mlx_ptr, img, point);
	  point->y = point->y + 1;
	}
      point->x = point->x + 1;
    }
}
