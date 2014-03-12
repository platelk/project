/*
** get_vector.c for raytracer in /home/leprov_a//depot/rt/src/utils
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Fri Jun  1 00:18:38 2012 alexis leprovost
** Last update Sun Jun  3 19:17:28 2012 alexis leprovost
*/

#include	<stdlib.h>
#include	<math.h>

#include	"detail.h"
#include	"color.h"
#include	"light.h"
#include	"calc.h"
#include	"utils.h"
#include	"shadow.h"

int
get_vector_light(t_light *light, t_detail *detail, double *v)
{
  if (light == NULL || detail == NULL || v == NULL)
    return (EXIT_FAILURE);
  if (light->type == PARALLELE)
    cpy_point(v, light->location);
  if (light->type == DIFFUSE)
    calc_any_vector(detail->position, light->location, v);
  return (EXIT_SUCCESS);
}

int
get_vector_reflechie(double *i, double *n, double *r)
{
  double	ps;

  if (i == NULL || n == NULL || r == NULL)
    return (EXIT_FAILURE);
  ps = calc_ps(i, n);
  r[X] = ((-2.0F * ps * n[X])) + i[X];
  r[Y] = ((-2.0F * ps * n[Y])) + i[Y];
  r[Z] = ((-2.0F * ps * n[Z])) + i[Z];
  return (EXIT_SUCCESS);
}

int	get_vector_refracte(double *v, double *n, double n1, double n2)
{
  double	mr;
  double	ps;

  mr = n1 / n2;
  inverse_vector(v);
  ps = calc_ps(v, n);
  normalize_vector(v);
  normalize_vector(n);
  v[X] = ((mr * ps) - sqrt(1.0F - CARRE(mr)				\
			   * (1.0F - CARRE(ps)))) * n[X] - (mr * v[X]);
  v[Y] = ((mr * ps) - sqrt(1.0F - CARRE(mr)				\
			   * (1.0F - CARRE(ps)))) * n[Y] - (mr * v[Y]);
  v[Z] = ((mr * ps) - sqrt(1.0F - CARRE(mr)				\
			   * (1.0F - CARRE(ps)))) * n[Z] - (mr * v[Z]);
  return (EXIT_SUCCESS);
}
