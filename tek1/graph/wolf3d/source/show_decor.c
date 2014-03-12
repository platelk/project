/*
** show_decor.c for show_decor in /home/platel_k/projet/graph/wolf3d/source
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Thu Jan  5 09:03:37 2012 kevin platel
** Last update Sun Jan 15 11:48:30 2012 kevin platel
*/

#include <stdlib.h>
#include "mlx_int.h"
#include "mlx.h"
#include "my.h"
#include "grille.h"
#include "point.h"
#include "my_libX.h"
#include "wolf.h"

int	show_decor(t_decor *map, void *mlx_ptr, void *win_ptr)
{
  mlx_put_image_to_window(mlx_ptr, win_ptr, map->wall->img, 0, 0);
  return (0);
}
