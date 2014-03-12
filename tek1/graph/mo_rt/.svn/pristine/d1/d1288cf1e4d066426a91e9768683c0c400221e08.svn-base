/*
** calc_rotation.c for raytracer in /home/leprov_a//depot/rt/src/calc
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Fri May  4 14:43:50 2012 alexis leprovost
** Last update Sat May 26 14:53:48 2012 alexis leprovost
*/

#include	<stdlib.h>
#include	<math.h>

#include	"raytracer.h"
#include	"global.h"

static	int	rotation_x(double *vector, double coord)
{
  double	radian;
  double	x;
  double	y;
  double	z;

  if (vector == NULL)
    return (EXIT_FAILURE);
  radian = (coord * M_PI) / 180.0F;
  z = (vector[Y] * (sin(radian) * (-1.0F))) + (vector[Z] * cos(radian));
  y = (vector[Y] * cos(radian)) + (vector[Z] * sin(radian));
  x = vector[X];
  vector[X] = x;
  vector[Y] = y;
  vector[Z] = z;
  return (EXIT_SUCCESS);
}

static	int	rotation_y(double *vector, double coord)
{
  double	radian;
  double	x;
  double	y;
  double	z;

  if (vector == NULL)
    return (EXIT_FAILURE);
  radian = (coord * M_PI) / 180.0F;
  z = (vector[X] * sin(radian)) + (vector[Z] * cos(radian));
  y = vector[Y];
  x = (vector[X] * cos(radian)) + (vector[Z] * (sin(radian) * (-1.0F)));
  vector[X] = x;
  vector[Y] = y;
  vector[Z] = z;
  return (EXIT_SUCCESS);
}

static	int	rotation_z(double *vector, double coord)
{
  double	radian;
  double	x;
  double	y;
  double	z;

  if (vector == NULL)
    return (EXIT_FAILURE);
  radian = (coord * M_PI) / 180.0F;
  z = vector[Z];
  y = (vector[X] * (sin(radian) * (-1.0F))) + (vector[Y] * cos(radian));
  x = (vector[X] * cos(radian)) + (vector[Y] * sin(radian));
  vector[X] = x;
  vector[Y] = y;
  vector[Z] = z;
  return (EXIT_SUCCESS);
}

int	calc_rotation(double *vector, double *rotation, double flag)
{
  double	tmp[NB_DIMENSION];

  if (rotation == NULL || vector == NULL)
    return (EXIT_FAILURE);
  tmp[X] = rotation[X] * flag;
  tmp[Y] = rotation[Y] * flag;
  tmp[Z] = rotation[Z] * flag;
  if (tmp[X])
    rotation_x(vector, tmp[X]);
  if (tmp[Y])
    rotation_y(vector, tmp[Y]);
  if (tmp[Z])
    rotation_z(vector, tmp[Z]);
  return (EXIT_FAILURE);
}
