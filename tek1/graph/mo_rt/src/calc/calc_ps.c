/*
** calc_ps.c for raytracer in /home/leprov_a//depot/rt/src/calc
**
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
**
** Started on  Fri May 11 22:16:56 2012 alexis leprovost
** Last update Sun May 27 12:40:54 2012 ronan guiho
*/

#include	<stdlib.h>

#include	"raytracer.h"

double	calc_ps(double *u, double *v)
{
  double	value;

  if (u == NULL || v == NULL)
    return (0.0F);
  value = (u[X] * v[X]) + (u[Y] * v[Y]) + (u[Z] * v[Z]);
  return (value);
}
