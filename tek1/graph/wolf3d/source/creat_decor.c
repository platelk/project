/*
** creat_decor.c for creat_decor in /home/platel_k/projet/graph/wolf3d/include
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Wed Jan  4 14:45:26 2012 kevin platel
** Last update Sun Jan 15 11:49:11 2012 kevin platel
*/

#include <stdlib.h>
#include "mlx_int.h"
#include "mlx.h"
#include "my.h"
#include "point.h"
#include "my_libX.h"
#include "wolf.h"
#include "decor.h"
#include "perso.h"

t_decor	*creat_decor(char **av, void *mlx_ptr, void *win_ptr)
{
  t_decor	*map;

  win_ptr = win_ptr;
  map = malloc(sizeof(*map));
  if (map == NULL)
    return (0);

  map->wall = init_img(mlx_ptr, 1000, 1000);
  map->map = get_data(av[1]);
  return (map);
}
