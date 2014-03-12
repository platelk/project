/*
** perlin_effect.c for perlin_effect in /home/ozouf_h//perlin_noise
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Thu May 10 15:19:08 2012 harold ozouf
** Last update Sun May 20 03:26:51 2012 alexis leprovost
*/

#include	<stdlib.h>
#include	<math.h>

#include	"perlin_noise.h"

void	init_effects_perlin(t_perlin_foo *f)
{
  f[0] = &marble;
  f[1] = &wood;
  f[2] = NULL;
}

void	make_moy(double t_ampli, t_perlin *p)
{
  int	i;
  int	j;

  j = -1;
  while (++j < SIZE_Y)
    {
      i = -1;
      while (++i < SIZE_X)
  	p->perlin[j][i] /= t_ampli;
    }
}

double	interpol(double	i, double j, double k)
{
  k = (1.0 - cos(k * M_PI)) / 2;
  return (i * (1.0 - k) + k * j);
}

double	marble(double value)
{
  return (sqrt(fabs(sin(2 * M_PI * value))));
}

double	wood(double value)
{
  return ((value * 20.0) - (int)(value * 20));
}
