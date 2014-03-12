/*
** my_ppt.c for my_ppt in /home/platel_k/projet/minilibX/tp1/tp1_window_empty
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Thu Nov 17 09:59:14 2011 kevin platel
** Last update Fri Jan  6 11:31:17 2012 kevin platel
*/

#include <stdlib.h>
#include "my_libX.h"
#include "mlx.h"
#include "point.h"

void	mlx_ppti(void *mlx_ptr, t_imag *img, t_point *pixel)
{
  unsigned int	i;
  unsigned int	color;
  char		*get;
  int		k;
  int		endian;

  k = 1;
  i = (img->sizeline) * (pixel->y);
  i = i + (img->bpp / 8) * (pixel->x);
  color = mlx_get_color_value(mlx_ptr, pixel->color);
  get = &color;
  if (img->endian == 0)
    endian = 1;
  else
    {
      k = (img->bpp) - 1;
      endian = -1;
    }
  while (k < (img->bpp / 8) && k >= 0)
    {
      (img->data)[i] = get[k - endian];
      k = k + endian;
      i++;
    }
}
