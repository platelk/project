/*
** calc_perturbation.c for raytracer in /home/leprov_a//depot/rt/src/calc
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Mon May 14 11:52:46 2012 alexis leprovost
** Last update Fri Jun  1 16:03:00 2012 zoe phalippou
*/

#include	<stdlib.h>
#include	<math.h>

#include	"raytracer.h"
#include	"global.h"
#include	"object.h"
#include	"utils.h"
#include	"calc.h"

int	calc_perturbation(t_object *object, double *position, double *normal)
{
  double	value[NB_DIMENSION];
  double	pos[NB_DIMENSION];

  if (object == NULL || position == NULL || normal == NULL)
    return (EXIT_FAILURE);
  value[X] = object->perturbation[X];
  value[Y] = object->perturbation[Y];
  value[Z] = object->perturbation[Z];
  modif_position(position, object, pos, INVERSE_ROTATION);
  if (value[X] >= 1.000)
    normal[X] = normal[X] + (cos((pos[X] / value[X])) *
    (sqrt((CARRE(normal[X])
	   + CARRE(normal[Y]) + CARRE(normal[Z])) / value[X])));
  if (value[Y] >= 1.000)
    normal[Y] = normal[Y] + (cos((pos[Y] / value[Y])) *
    (sqrt((CARRE(normal[X])
	   + CARRE(normal[Y]) + CARRE(normal[Z])) / value[Y])));
  if (value[Z] >= 1.000)
    normal[Z] = normal[Z] + (cos((pos[Z] / value[Z])) *
    (sqrt((CARRE(normal[X])
	   + CARRE(normal[Y]) + CARRE(normal[Z])) / value[Z])));
  return (EXIT_SUCCESS);
}
