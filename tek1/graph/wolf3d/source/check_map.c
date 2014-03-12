/*
** check_map.c for check_map in /home/platel_k/projet/graph/wolf3d
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Mon Jan  9 10:57:16 2012 kevin platel
** Last update Fri Jan 13 11:44:27 2012 kevin platel
*/

#include <stdlib.h>
#include "mlx_int.h"
#include "mlx.h"
#include "my.h"
#include "point.h"
#include "my_libX.h"
#include "wolf.h"
#include "perso.h"
#include "decor.h"

int	check_map(t_decor *map)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (map->map[0][i] != 0 && map->map[0][i] == '1')
      i++;
  if (map->map[0][0] != '1' && map->map[0][i] != '1')
    return (1);
  i--;
  while (map->map[j] != NULL && map->map[j][0] == '1' && map->map[j][i] == '1')
    j++;
  if (map->map[j] != NULL && (map->map[j][0] != '1' || map->map[j][i] != '1'))
    return (1);
  j--;
  while (map->map[j][i] != 0 && map->map[0][i] == '1' && i >= 0)
    i--;
  if (i >= 0 && map->map[j][i] != '1')
    return (1);
  return (0);
}
