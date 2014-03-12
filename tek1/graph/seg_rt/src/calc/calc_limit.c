/*
** calc_limit.c for raytracer in /home/leprov_a//depot/rt/src/calc
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Tue May  8 10:54:09 2012 alexis leprovost
** Last update Sat May 26 14:43:58 2012 alexis leprovost
*/

#include	<stdlib.h>
#include	<stdio.h>

#include	"raytracer.h"
#include	"global.h"
#include	"limit.h"

static int	check_limit(t_limit *limit)
{
  if (limit == NULL)
    return (EXIT_FAILURE);
  if ((limit->flag & MIN_X) && (limit->flag & MAX_X) &&
      (limit->x[MIN] > limit->x[MAX]))
    return (EXIT_FAILURE);
  if ((limit->flag & MIN_Y) && (limit->flag & MAX_Y) &&
      (limit->y[MIN] > limit->y[MAX]))
    return (EXIT_FAILURE);
  if ((limit->flag & MIN_Z) && (limit->flag & MAX_Z) &&
      (limit->z[MIN] > limit->z[MAX]))
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int	calc_limit(t_limit *limit, double *position, double *vector, double *k)
{
  double	location[NB_DIMENSION];

  if (check_limit(limit) || *k <= 0.000)
    return (EXIT_FAILURE);
  location[X] = position[X] + (*k * vector[X]);
  location[Y] = position[Y] + (*k * vector[Y]);
  location[Z] = position[Z] + (*k * vector[Z]);
  if ((limit->flag & MIN_X) && (location[X] < limit->x[MIN]))
    location[X] = limit->x[MIN];
  if ((limit->flag & MAX_X) && (location[X] > limit->x[MAX]))
    location[X] = limit->x[MAX];
  if ((limit->flag & MIN_Y) && (location[Y] < limit->y[MIN]))
    location[Y] = limit->y[MIN];
  if ((limit->flag & MAX_Y) && (location[Y] > limit->y[MAX]))
    location[Y] = limit->y[MAX];
  if ((limit->flag & MIN_Z) && (location[Z] < limit->z[MIN]))
    location[Z] = limit->z[MIN];
  if ((limit->flag & MAX_Z) && (location[Z] > limit->z[MAX]))
    location[Z] = limit->z[MAX];
  *k = (((location[Z] - position[Z]) / (vector[Z] + 0.001)));
  return(EXIT_SUCCESS);
}
