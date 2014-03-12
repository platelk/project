/*
** calc_limit.c for raytracer in /home/leprov_a//depot/rt/src/calc
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Tue May  8 10:54:09 2012 alexis leprovost
** Last update Fri Jun  1 16:00:43 2012 zoe phalippou
*/

#include	<stdlib.h>
#include	<stdio.h>

#include	"raytracer.h"
#include	"global.h"
#include	"object.h"
#include	"limit.h"
#include	"utils.h"
#include	"calc.h"

int	calc_limit(t_object *object, double *position,
		   double *vector, double *k)
{
  double	loc[NB_DIMENSION];
  double        pos[NB_DIMENSION];
  double        u[NB_DIMENSION];

  if (object == NULL || object->limit == NULL || position == NULL ||
      vector == NULL ||
      modif_position(position, object, pos, INVERSE_ROTATION) ||
      modif_vector(object->rotation, vector, u, INVERSE_ROTATION))
    return (EXIT_FAILURE);
  loc[X] = pos[X] + (*k * u[X]);
  loc[Y] = pos[Y] + (*k * u[Y]);
  loc[Z] = pos[Z] + (*k * u[Z]);
  if (((object->limit->flag & MIN_X) && (loc[X] < object->limit->x[MIN]))
      || ((object->limit->flag & MAX_X) && (loc[X] > object->limit->x[MAX]))
      || ((object->limit->flag & MIN_Y) && (loc[Y] < object->limit->y[MIN]))
      || ((object->limit->flag & MAX_Y) && (loc[Y] > object->limit->y[MAX]))
      || ((object->limit->flag & MIN_Z) && (loc[Z] < object->limit->z[MIN]))
      || ((object->limit->flag & MAX_Z) && (loc[Z] > object->limit->z[MAX])))
    *k = -1.0F;
  return (EXIT_SUCCESS);
}
