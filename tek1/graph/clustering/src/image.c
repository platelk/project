/*
** image.c for image in /home/guiho_r//TP/TP_igraph/tp2
**
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
**
** Started on  Thu Nov 17 09:09:43 2011 ronan guiho
** Last update Mon May  7 00:27:34 2012 ronan guiho
*/
#include <assert.h>
#include <stdlib.h>
#include "image.h"
#include "mlx.h"
#include "my.h"

#define		IMG	t_img

// Inisialization img
t_image		*initialization_img(void *ptr_ini, int height, int width)
{
  t_image	*t_img;

  IMG = malloc(sizeof(*t_img));
  IMG->ptr_ini = ptr_ini;
  IMG->height = height;
  IMG->width = width;
  IMG->img = mlx_new_image(ptr_ini, width, height);
  IMG->data = mlx_get_data_addr(IMG->img, &IMG->bpp, \
				&IMG->sizeline, &IMG->endian);
  return (t_img);
}

// Pixel put to img
int		mlx_ppti(t_image *t_img, int x, int y, int color)
{
  int		i;
  char		*ptr;
  unsigned int  color1;

  color1 = mlx_get_color_value(IMG->ptr_ini, color);
  ptr = (char *) &color1;
  i = (y * IMG->sizeline) + (x * (IMG->bpp / 8));
  IMG->data[i] = ptr[0];
  IMG->data[i + 1] = ptr[1];
  IMG->data[i + 2] = ptr[2];
  IMG->data[i + 3] = ptr[3];
  return (0);
}
