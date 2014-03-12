/*
** modif_vector.c for raytracer in /home/leprov_a//depot/rt/src/utils
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Sat May 26 14:02:13 2012 alexis leprovost
** Last update Thu May 31 23:16:28 2012 alexis leprovost
*/

#include	<stdlib.h>
#include	<stdio.h>

#include	"global.h"
#include	"detail.h"
#include	"camera.h"
#include	"calc.h"
#include	"init.h"
#include	"utils.h"

int	corrector_normal(t_detail *detail, double *normal, double *vector)
{
  t_camera	camera;
  t_detail	tmp;

  if (init_detail(&tmp))
    return (EXIT_FAILURE);
  camera.position[X] = detail->position[X] - (1.0F * vector[X]);
  camera.position[Y] = detail->position[Y] - (1.0F * vector[Y]);
  camera.position[Z] = detail->position[Z] - (1.0F * vector[Z]);
  detail->object->inter(&camera, detail->object, &tmp, normal);
  if (tmp.k > CONST_ERROR)
      inverse_vector(normal);
  return (EXIT_SUCCESS);
}

int	normalize_vector(double *vector)
{
  int	value;

  if (vector == NULL)
    return (EXIT_FAILURE);
  value = calc_norme(vector);
  vector[X] /= value;
  vector[Y] /= value;
  vector[Z] /= value;
  return (EXIT_SUCCESS);
}

int	inverse_vector(double *vector)
{
  if (vector == NULL)
    return (EXIT_FAILURE);
  vector[X] *= (-1.0F);
  vector[Y] *= (-1.0F);
  vector[Z] *= (-1.0F);
  return (EXIT_SUCCESS);
}
