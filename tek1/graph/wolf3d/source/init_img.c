/*
** init_img.c for init_img in /home/platel_k/projet/minilibX/tp1/tp1_window_empty
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Thu Nov 17 09:17:33 2011 kevin platel
** Last update Fri Jan  6 23:01:37 2012 kevin platel
*/

#include <stdlib.h>
#include "mlx_int.h"
#include "mlx.h"
#include "point.h"
#include "my_libX.h"

#define	IMG	new->img
#define	BPP	new->bpp
#define	SIZE_LINE	new->sizeline
#define ENDIAN	new->endian
#define DATA	new->data

t_imag	 *init_img(void *mlx_ptr, int width, int height)
{
  t_imag	*new;

  new = malloc(sizeof(*new));
  if (new == NULL)
    return (NULL);
  IMG = mlx_new_image(mlx_ptr, width, height);
  DATA = mlx_get_data_addr(IMG, &(BPP), &(SIZE_LINE), &(ENDIAN));
  new->width = width;
  new->height = height;
  return (new);
}

t_imag	 *init_xpm(void *mlx_ptr, char *link)
{
  t_imag	*new;
  int		with_img;
  int		height_img;

  new = malloc(sizeof(*new));
  if (new == NULL)
    return (NULL);
  IMG = mlx_xpm_file_to_image(mlx_ptr, link, &with_img, &height_img);
  DATA = mlx_get_data_addr(IMG, &(BPP), &(SIZE_LINE), &(ENDIAN));
  new->width = with_img;
  new->height = height_img;
  return (new);
}
