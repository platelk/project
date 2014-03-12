/*
** normal_sphere.c for raytracer in /home/leprov_a//depot/rt/src/normal
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Fri May 25 19:23:20 2012 alexis leprovost
** Last update Sat May 26 11:25:45 2012 alexis leprovost
*/

#include	<stdlib.h>

#include	"raytracer.h"
#include	"global.h"
#include	"detail.h"

int	normal_sphere(double *n, t_detail *detail, double *position, double *v)
{
  if (n == NULL || detail == NULL || position == NULL || v == NULL)
    return (EXIT_FAILURE);
  n[X] = detail->position[X] - detail->object->position[X];
  n[Y] = detail->position[Y] - detail->object->position[Y];
  n[Z] = detail->position[Z] - detail->object->position[Z];
  return (EXIT_SUCCESS);
}
