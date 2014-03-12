/*
** calc_point.c for raytracer in /home/leprov_a//depot/rt/src/calc
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Wed May  9 18:54:14 2012 alexis leprovost
** Last update Thu May 10 11:18:50 2012 alexis leprovost
*/

#include	<stdlib.h>
#include	<stdio.h>

#include	"raytracer.h"

int	calc_point(double *position, double *vector, double *location, double k)
{
  if (position == NULL || vector == NULL || location == NULL)
    return (EXIT_FAILURE);
  location[X] = position[X] + (k * vector[X]);
  location[Y] = position[Y] + (k * vector[Y]);
  location[Z] = position[Z] + (k * vector[Z]);
  return (EXIT_SUCCESS);
}
