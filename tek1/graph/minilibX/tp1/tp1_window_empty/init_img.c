/*
** init_img.c for init_img in /home/platel_k/projet/minilibX/tp1/tp1_window_empty
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Thu Nov 17 09:17:33 2011 kevin platel
** Last update Wed Nov 23 15:14:03 2011 kevin platel
*/

#include "mlx.h"
#include "point.h"
#include <stdlib.h>
#include "my_libX.h"

#define	IMG	new->img
#define	BPP	new->bpp
#define	SIZE_LINE	new->sizeline
#define ENDIAN	new->endian
#define DATA	new->data

t_img	*init_img(void *mlx_ptr, int width, int height)
{
  t_img	*new;

  new = malloc(sizeof(*new));
  if (new == NULL)
    return (NULL);
  IMG = mlx_new_image(mlx_ptr, width, height);
  DATA = mlx_get_data_addr(IMG, &(BPP), &(SIZE_LINE), &(ENDIAN));
  new->width = width;
  new->height = height;
  return (new);
}
