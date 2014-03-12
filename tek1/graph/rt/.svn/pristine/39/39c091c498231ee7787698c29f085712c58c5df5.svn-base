/*
** inter_plan.c for raytracer in /home/leprov_a//depot/rt/src/inter
**
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
**
** Started on  Mon May  7 13:03:29 2012 alexis leprovost
** Last update Sun Jun  3 11:34:22 2012 alexis leprovost
*/

#include	<stdlib.h>

#include	"raytracer.h"
#include	"global.h"
#include	"camera.h"
#include        "object.h"
#include	"detail.h"
#include	"calc.h"
#include	"utils.h"

double	inter_indice_plan(t_camera *camera, t_object *object,
			  double *vector)
{
  double	pos[NB_DIMENSION];
  double	u[NB_DIMENSION];
  double	k;

  if (modif_position(camera->position, object, pos, INVERSE_ROTATION) ||
      modif_vector(object->rotation, vector, u, INVERSE_ROTATION))
    return (-1.0F);
  if (!u[Z])
    u[Z] += EPSILON;
  k = (pos[Z] * (-1.0F)) / (u[Z] + 0.0000001F);
  return (k);
}

int
inter_plan(t_camera *camera, t_object *object,
	   t_detail *detail, double *vector)
{
  double	k;

  k = -1.0F;
  if (!camera || !object || !detail || !vector)
    return (EXIT_FAILURE);
  k = inter_indice_plan(camera, object, vector);
  if (object->limit)
    calc_limit(object, camera->position, vector, &k);
  if (object->image != NULL && object->image->type_texture == 1)
    if (calc_cut_texture(&k, object, vector, camera))
      return (EXIT_FAILURE);
  if (k > CONST_ERROR && (k < detail->k || detail->k < CONST_ERROR))
    {
      detail->k = k;
      detail->object = object;
    }
  return (EXIT_SUCCESS);
}
