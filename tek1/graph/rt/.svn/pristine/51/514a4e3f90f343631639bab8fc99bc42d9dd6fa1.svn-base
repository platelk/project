/*
** normal_tore.c for raytracer in /home/leprov_a//depot/rt/src/normal
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Fri May 25 19:32:14 2012 alexis leprovost
** Last update Sun May 27 15:47:50 2012 alexis leprovost
*/

#include	<stdlib.h>

#include	"global.h"
#include	"raytracer.h"
#include	"detail.h"
#include	"utils.h"

int	normal_tore(double *n, t_detail *detail, double *position, double *v)
{
  double	value[NB_DIMENSION + 3];

  if (n == NULL || detail == NULL || position == NULL || v == NULL)
    return (EXIT_FAILURE);
  value[X] = detail->position[X];
  value[Y] = detail->position[Y];
  value[Z] = detail->position[Z];
  value[Z + 1] = ((t_tore *)detail->object->son)->radius[MIN];
  value[Z + 2] = ((t_tore *)detail->object->son)->radius[MAX];
  value[Z + 3] = (CARRE(value[X]) + CARRE(value[Y]) + CARRE(value[Z]) +
		  CARRE(value[Z + 2]) - CARRE(value[Z - 1]));
  n[X] = (4.000 * value[X] * value[Z + 3]) - (8.000 * value[Z + 2] * value[X]);
  n[Y] = (4.000 * value[Y] * value[Z + 3]);
  n[Z] = (4.000 * value[Z] * value[Z + 3]) - (8.000 * value[Z + 2] * value[Z]);
  return (EXIT_SUCCESS);
}
