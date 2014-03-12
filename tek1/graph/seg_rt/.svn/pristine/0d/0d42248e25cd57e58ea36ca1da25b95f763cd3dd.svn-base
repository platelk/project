/*
** inter_plan.c for raytracer in /home/leprov_a//depot/rt/src/inter
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Mon May  7 13:03:29 2012 alexis leprovost
<<<<<<< .mine
** Last update Mon May 28 00:29:49 2012 alexis leprovost
=======
** Last update Thu May 10 12:26:18 2012 alexis leprovost
>>>>>>> .r95
*/

#include	<stdlib.h>

#include	"raytracer.h"
#include	"global.h"
#include	"camera.h"
#include        "object.h"
#include	"detail.h"
#include	"calc.h"
#include	"utils.h"

int
inter_plan(t_camera *camera, t_object *object, t_detail *detail, double *vector)
{
  double	k;
  double	pos[NB_DIMENSION];
  double	u[NB_DIMENSION];

  if (!camera || !object || !detail || !vector)
    return (EXIT_FAILURE);
  modif_position(camera->position, object, pos, INVERSE_ROTATION);
  modif_vector(object->rotation, vector, u, INVERSE_ROTATION);
  if (!u[Z])
    u[Z] += EPSILON;
  k = (pos[Z] * (-1.0F)) / (u[Z] + 0.0000001F);
  if (object->limit != NULL &&
      calc_limit(object->limit, camera->position, vector, &k))
    return (EXIT_FAILURE);
  if (k > CONST_ERROR && (k < detail->k || detail->k < CONST_ERROR))
    {
      detail->k = k;
      detail->object = object;
    }
  return (EXIT_SUCCESS);
}
