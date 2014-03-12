/*
** calc_p.c for calc_p in /home/platel_k/projet/graph/wolf3d/source
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Thu Jan  5 09:32:03 2012 kevin platel
** Last update Sat Jan 14 11:49:44 2012 kevin platel
*/

#include <math.h>
#include <stdlib.h>
#include "mlx_int.h"
#include "mlx.h"
#include "my.h"
#include "point.h"
#include "my_libX.h"
#include "wolf.h"
#include "perso.h"
#include "decor.h"

#define RAD(x)	((float) ((x * 3.14) / 180))
#define PRES	1000
#define X	0
#define Y	1

int	**calc_p(t_perso *perso)
{
  int	 y1;
  float	 y;
  int	 **p;
  float	 x;
  int	i;

  p = malloc(LENGHT_P * sizeof(*p));
  y1 = 500;
  i = 0;
  while (y1 > -(LENGHT_P / 2))
    {
      p[i] = malloc(2 * sizeof(**p));
      x = 0.5;
      y = ((float) y1) / 1000;
      y1 = y1 - 1;
      p[i][X] = ((x * cos(RAD(perso->angle))) - (y * sin(RAD(perso->angle))))
	* 1000;
      p[i][Y] = ((y * cos(RAD(perso->angle))) + (x * sin(RAD(perso->angle))))
	* 1000;
      p[i][X] = (p[i][X] + ((perso->x)));
      p[i][Y] = (p[i][Y] + ((perso->y)));
      i++;
    }
  return (p);
}

#define COLOR_WALL	0xFFFFFFFF

int	calc_k(t_perso *perso, char **map, int **plan, int x)
{
  int	vx;
  int	vy;
  float	k;
  float	x1;
  float	y1;
  int	i;

  vx = ((plan[x][X]) - perso->x);
  vy = ((plan[x][Y]) - perso->y);
  x1 = (perso->x) * 10;
  y1 = (perso->y) * 10;
  i = 1;
  k = 0.0;
  while (map[(int) x1 / PRES] != 0
	 && map[(int) x1 / (PRES)][(int) y1 / (PRES)] != 0
	 && map[(int) x1 / (PRES)][(int) y1 / (PRES)] != '1')
    {
      x1 = ((float) perso->x * 10) + (k * ((float) vx));
      y1 = ((float) perso->y * 10) + (k * ((float) vy));
      k = k + 0.005;
    }
  return ((int) ((k) * 1000.0));
}
