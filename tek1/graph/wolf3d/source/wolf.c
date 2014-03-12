/*
** wolf.c for wolf in /home/platel_k/projet/graph/wolf3d
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Fri Jan 13 12:48:09 2012 kevin platel
** Last update Sun Jan 15 11:48:45 2012 kevin platel
*/

#include <stdlib.h>
#include "mlx_int.h"
#include "mlx.h"
#include "my.h"
#include "grille.h"
#include "point.h"
#include "my_libX.h"
#include "wolf.h"

int	wolf(t_perso *perso, t_decor *map, void *win_ptr, void *mlx_ptr)
{
  t_param	*param;

  clean_img(mlx_ptr, map->wall);
  draw_wall(perso, map, win_ptr, mlx_ptr);
  param = malloc(sizeof(*param));
  param->map = map;
  param->mlx_ptr = mlx_ptr;
  param->win_ptr = win_ptr;
  param->perso = perso;
  mlx_key_hook(win_ptr, &key_hook, param);
  mlx_expose_hook(win_ptr, &expose, param);
  mlx_loop(mlx_ptr);
  return (0);
}
