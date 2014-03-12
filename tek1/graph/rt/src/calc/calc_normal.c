/*
** main.c for normal in /home/ozouf_h//rt_normal
**
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Wed May  9 17:23:32 2012 harold ozouf
** Last update Sun Jun  3 01:32:40 2012 harold ozouf
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<math.h>

#include	"raytracer.h"
#include	"camera.h"
#include	"detail.h"
#include	"calc.h"
#include	"init.h"
#include	"utils.h"

static int
get_normal(double *p1, double *p2, double *p3, double *n)
{
  double	u[NB_DIMENSION];
  double	v[NB_DIMENSION];
  int		i;

  i = -1;
  while (++i < NB_DIMENSION)
    {
      u[i] = (p2[i] - p1[i]) * (1.000 / CARRE(CONST_NORMAL));
      v[i] = (p3[i] - p1[i]) * (1.000 / CARRE(CONST_NORMAL));
    }
  n[X] = (u[Y] * v[Z]) - (u[Z] * v[Y]);
  n[Y] = (u[Z] * v[X]) - (u[X] * v[Z]);
  n[Z] = (u[X] * v[Y]) - (u[Y] * v[X]);
  normalize_vector(n);
  return (EXIT_SUCCESS);
}

static	int
get_axe(double *vector)
{
  int	axe;
  int	i;

  if (vector == NULL)
    return (NB_DIMENSION + 1);
  axe = X;
  i = -1;
  while (++i < NB_DIMENSION)
    if (ABS(vector[axe]) <= ABS(vector[i]))
      axe = i;
  return (axe);
}

static int
get_vector(double *old, double *new, int axe, int flag)
{
  int	i;

  if (old == NULL || new == NULL ||  axe > NB_DIMENSION)
    return (EXIT_FAILURE);
  i = -1;
  while (++i < NB_DIMENSION)
    if (axe != i)
      new[i] = old[i] + CONST_NORMAL;
    else
      new[i] = old[i];
  i = 0;
  while (flag >= 0)
    {
      if (i != axe)
	--flag;
      ++i;
    }
  new[i - 1] += CONST_NORMAL;
  return (EXIT_SUCCESS);
}

static int
approx_normal(t_camera *c, t_detail *d, double *v, double *n)
{
  t_detail	td[2];
  double	tv[2][NB_DIMENSION];
  int		axe;

  axe = get_axe(v);
  if (init_detail(&td[0]) || init_detail(&td[1]) ||
      get_vector(v, tv[0], axe, 1) || get_vector(v, tv[1], axe, 0))
    return (EXIT_FAILURE);
  d->object->inter(c, d->object, &td[0], tv[0]);
  d->object->inter(c, d->object, &td[1], tv[1]);
  if (td[0].object != NULL && td[1].object != NULL)
    {
      calc_point(c->position, tv[0], td[0].position, td[0].k);
      calc_point(c->position, tv[1], td[1].position, td[1].k);
      get_normal(d->position, td[0].position, td[1].position, n);
      corrector_normal(d, n, v);
      return (EXIT_SUCCESS);
    }
  return (EXIT_FAILURE);
}

int	calc_normal(t_camera *c, t_detail *d, double *v, double *n)
{
  int	i;

  i = -1;
  if (d->non_initialize == 0)
    {
      while (++i < NB_DIMENSION)
	n[i] = 0.0F;
      approx_normal(c, d, v, n);
    }
  corrector_normal(d, n, v);
  return (EXIT_SUCCESS);
}
