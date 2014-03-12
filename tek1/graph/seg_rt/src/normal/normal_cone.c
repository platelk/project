/*
** normal_cone.c for raytracer in /home/leprov_a//depot/rt/src/normal
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Fri May 25 19:30:26 2012 alexis leprovost
** Last update Sun May 27 15:47:10 2012 alexis leprovost
*/

#include	<stdlib.h>

#include	"raytracer.h"
#include	"global.h"
#include	"detail.h"
#include	"utils.h"
#include	"calc.h"

int	normal_cone(double *n, t_detail *detail, double *position, double *v)
{
  double	location[NB_DIMENSION];
  double	u[NB_DIMENSION];

  if (modif_position(position, detail->object, location, INVERSE_ROTATION) ||
      modif_vector(detail->object->rotation, v, u, INVERSE_ROTATION) ||
      n == NULL || detail == NULL || position == NULL || v == NULL)
    return (EXIT_FAILURE);
  n[X] = location[X] + (detail->k * u[X]);
  n[X] = location[Y] + (detail->k * u[Y]);
  n[Z] = location[Z] + (detail->k * u[Z]);
  n[Z] *= (((t_cone *)detail->object->son)->angle * (-1.0F));
  calc_rotation(n, detail->object->rotation, INVERSE_ROTATION);
  return (EXIT_SUCCESS);
}
