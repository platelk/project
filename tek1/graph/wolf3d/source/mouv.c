/*
** mouv.c for mouv in /home/platel_k/projet/graph/wolf3d/source
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Mon Jan  9 15:29:14 2012 kevin platel
** Last update Sun Jan 15 11:47:56 2012 kevin platel
*/

#include <math.h>
#include <stdlib.h>
#include "mlx_int.h"
#include "mlx.h"
#include "my.h"
#include "grille.h"
#include "point.h"
#include "my_libX.h"
#include "wolf.h"

#define RAD(x)	((float) ((x * 3.14) / 180))

int	mouv_left(t_param *param)
{
  if (param->map->map[((param->perso->x - 10) / 100)][param->perso->y / 100]
      != '1')
    {
      param->perso->angle += 10;
      draw_wall(param->perso, param->map, param->win_ptr, param->mlx_ptr);
    }
  return (0);
}

int	mouv_right(t_param *param)
{
  if (param->map->map[((param->perso->x - 10) / 100)][param->perso->y / 100]
      != '1')
    {
      param->perso->angle -= 10;
      draw_wall(param->perso, param->map, param->win_ptr, param->mlx_ptr);
    }
  return (0);
}

int	mouv_up(t_param *param)
{
  float	x;
  int	x1;
  int	y1;

  x = 0.5;
  x1 = (x * cos(RAD(param->perso->angle))) * 10;
  y1 = (x * sin(RAD(param->perso->angle))) * 10;
  if (param->map->map[((param->perso->x + x1) / 100)][param->perso->y / 100]
      != '1'
    && param->map->map[(param->perso->x) / 100][(param->perso->y + y1) / 100]
      != '1')
    {
      param->perso->x = param->perso->x + ((int) x1);
      param->perso->y = param->perso->y + ((int) y1);
      draw_wall(param->perso, param->map, param->win_ptr, param->mlx_ptr);
    }
  return (0);
}

int	mouv_down(t_param *param)
{
  float	x;
  int	x1;
  int	y1;

  x = 0.5;
      x1 = (x * cos(RAD(param->perso->angle))) * 10;
      y1 = (x * sin(RAD(param->perso->angle))) * 10;
  if (param->map->map[((param->perso->x - x1) / 100)][param->perso->y / 100]
      != '1'
      && param->map->map[param->perso->x / 100][(param->perso->y - y1) / 100]
      != '1')
    {
      param->perso->x = param->perso->x - ((int) x1);
      param->perso->y = param->perso->y - ((int) y1);
      draw_wall(param->perso, param->map, param->win_ptr, param->mlx_ptr);
    }
  return (0);
}
