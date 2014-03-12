/*
** inter_cone.c for raytracer in /home/leprov_a//depot/rt/src/inter
**
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
**
** Started on  Tue May  8 11:29:47 2012 alexis leprovost
** Last update Sun Jun  3 06:17:28 2012 ronan guiho
*/

#include	<stdlib.h>
#include	<math.h>

#include	"raytracer.h"
#include	"camera.h"
#include        "object.h"
#include	"detail.h"
#include	"calc.h"
#include	"utils.h"
#include	"inter.h"
#include	"objects_neg.h"

int	inter_indice_cone(t_camera *camera, t_object *object,
			     double *vector, double *indice)
{
  double	pos[NB_DIMENSION];
  double	u[NB_DIMENSION];
  double	radian;
  double	opening;

  radian = (((t_cone *)object->son)->angle * M_PI) / 180.000;
  opening = CARRE(tan(radian));
  if (!opening)
    opening += EPSILON;
  if (modif_position(camera->position, object, pos, INVERSE_ROTATION) ||
      modif_vector(object->rotation, vector, u, INVERSE_ROTATION))
    return (EXIT_FAILURE);
  indice[A] = CARRE(u[X]) + CARRE(u[Y]) - (CARRE(u[Z]) / opening);
  indice[B] = 2.000 *
    ((pos[X] * u[X]) + (pos[Y] * u[Y]) - (pos[Z] * (u[Z]) / opening));
  indice[C] = CARRE(pos[X]) + CARRE(pos[Y]) - (CARRE(pos[Z]) / opening);
  indice[DELTA] = CARRE(indice[B]) - (4.000 * indice[A] * indice[C]);
  return (EXIT_SUCCESS);
}

int	inter_cone_k(t_detail *detail, double *k, t_object *object)
{
  if (!cmp_k(detail, k))
    {
      detail->k = SMALLER_POSITIVE_NUMBER(k[0], k[1]);
      detail->object = object;
    }
  return (EXIT_SUCCESS);
}

int
inter_cone(t_camera *camera, t_object *object,
	   t_detail *detail, double *vector)
{
  double	indice[NB_INDICE];
  double	k[2];

  if (!camera || !object || !detail || !vector ||
      inter_indice_cone(camera, object, vector, indice))
    return (EXIT_FAILURE);
  if (indice[DELTA] >= 0.000)
    {
      if (calc_k(indice, k))
	return (EXIT_FAILURE);
      if (object->inhibitor)
	obj_inhibitor(k, object, camera, vector);
      if (object->image != NULL && object->image->type_texture == 1)
	if (calc_cut_texture(k, object, vector, camera))
	  return (EXIT_FAILURE);
      if (object->limit)
	{
	  calc_limit(object, camera->position, vector, &k[0]);
	  calc_limit(object, camera->position, vector, &k[1]);
	}
      inter_cone_k(detail, k, object);
    }
  return (EXIT_SUCCESS);
}
