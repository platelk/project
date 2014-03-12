/*
** inter_moebius.c for moebuis in /home/vink/projet/graph/rt/src/inter
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Sun May 27 14:18:03 2012 kevin platel
** Last update Sun Jun  3 14:46:54 2012 kevin platel
*/

#include	<stdlib.h>

#include	<stdio.h>
#include	"global.h"
#include	"moebus.h"
#include	"camera.h"
#include	"object.h"
#include        "utils.h"
#include        "inter.h"
#include	"calc.h"
#include        "objects_neg.h"

int
inter_init_moebius(t_moebius *moebius, t_object *object)
{
  moebius->center.x = object->position[X];
  moebius->center.y = object->position[Y];
  moebius->center.z = object->position[Z];
  if (object->son == NULL)
    return (EXIT_FAILURE);
  moebius->size.x = ((t_mobius *) object->son)->a;
  moebius->size.y = ((t_mobius *) object->son)->b;
  moebius->size.z = ((t_mobius *) object->son)->c;
  return (0);
}

int
inter_init_line(t_line *line, double *pos, double *u)
{
  line->point.x = pos[X];
  line->point.y = pos[Y];
  line->point.z = pos[Z];
  line->direction.x = u[X];
  line->direction.y = u[Y];
  line->direction.z = u[Z];
  return (0);
}

int
inter_moebius(t_camera *camera, t_object *object, t_detail *detail,
	      double *vector)
{
  t_line	line;
  t_couple	out;
  t_moebius	moebius;
  double	u[NB_DIMENSION];
  double	pos[NB_DIMENSION];

  if (!camera || !object || !detail || !vector)
    return (EXIT_FAILURE);
  modif_position(camera->position, object, pos, INVERSE_ROTATION);
  modif_vector(object->rotation, vector, u, INVERSE_ROTATION);
  inter_init_line(&line, pos, u);
  if (inter_init_moebius(&moebius, object) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (moebius_cast_get_k(&line, &moebius, &out) == NULL)
    return (EXIT_FAILURE);
  detail->non_initialize = 1;
  detail->normal[X] = out.normal[X];
  detail->normal[Y] = out.normal[Y];
  detail->normal[Z] = out.normal[Z];
  detail->k = out.a;
  detail->object = object;
  return (0);
}
