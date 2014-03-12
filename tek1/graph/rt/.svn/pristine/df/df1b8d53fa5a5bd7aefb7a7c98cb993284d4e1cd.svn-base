/*
** main.c for main in /home/ozouf_h//perlin_noise
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Tue May  8 22:23:08 2012 harold ozouf
** Last update Sun Jun  3 19:55:04 2012 harold ozouf
*/

#include	<math.h>
#include	<stdlib.h>

#include	"perlin_noise.h"

static void	generate_noise(tab_2d map)
{
  int		i;
  int		j;

  j = -1;
  srandom(time(NULL));
  while (++j < SIZE_Y)
    {
      i = -1;
      while (++i < SIZE_X)
	map[j][i] = (double)(random() % 1000) / 1000;
    }
}

static void	smooth_noise(tab_2d map, int period, tab_2d smooth)
{
  t_pos		i;
  t_pos		p[2];
  double      	blend[2];
  double       	t[2];

  i.x = -1;
  while (++(i.x) < SIZE_X)
    {
      p[0].x = (i.x / period) * period;
      p[1].x = (p[0].x + period) % SIZE_X;
      blend[0] = (i.x - p[0].x) * 1.0 / period;
      i.y = -1;
      while (++(i.y) < SIZE_Y)
	{
	  p[0].y = (i.y / period) * period;
	  p[1].y = (p[0].y + period) % SIZE_Y;
	  blend[1] = (i.y - p[0].y) * 1.0 / period;
	  t[0] = interpol(map[p[0].y][p[0].x], map[p[0].y][p[1].x], blend[0]);
	  t[1] = interpol(map[p[1].y][p[0].x], map[p[1].y][p[1].x], blend[0]);
	  smooth[i.y][i.x] = interpol(t[0], t[1], blend[1]);
	}
    }
 }

static double	get_perlin_raw(t_perlin *p, int oct)
{
  static tab_2d	*smooth;
  static tab_2d	map;
  double	ampli[2];
  t_pos		i;

  i.x = -1;
  generate_noise(map);
  smooth = malloc(sizeof(*smooth) * oct);
  while (++(i.x) < oct)
    smooth_noise(map, 1 << i.x, smooth[i.x]);
  ampli[0] = 1.0;
  ampli[1] = 0.0;
  while (--oct > 0)
    {
      ampli[0] *= ((p->persistance > 1) ? (1) : (p->persistance));
      ampli[1] += ampli[0];
      i.y = -1;
      while (++(i.y) < SIZE_Y)
	{
	  i.x = -1;
	  while (++(i.x) < SIZE_X)
	    p->perlin[i.y][i.x] += smooth[oct][i.y][i.x] * ampli[0];
	}
    }
  return (ampli[1]);
}

void	create_perlin_noise(t_perlin *p)
{
  double	t_ampli;
  int		oct;

  oct = ((p->nbr_octave > 10) ? (10) :(p->nbr_octave));
  t_ampli = get_perlin_raw(p, oct);
  if (!p->ceil)
    make_moy(t_ampli, p);
}
