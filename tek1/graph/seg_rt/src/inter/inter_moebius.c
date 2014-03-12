/*
** inter_moebius.c for moebuis in /home/vink/projet/graph/rt/src/inter
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Sun May 27 14:18:03 2012 kevin platel
** Last update Sun May 27 17:19:31 2012 kevin platel
*/

#include	<stdlib.h>

#include	<stdio.h>
#include	"global.h"
#include	"moebus.h"
#include	"camera.h"
#include	"object.h"

int
inter_moebius(t_camera *camera, t_object *object, t_detail *detail, double *vector)
{
  t_line	line;
  t_couple	out;
  t_moebius	moebuis;

  if (!camera || !object || !detail || !vector)
    return (EXIT_FAILURE);

  line.point.x = camera->position[X];
  line.point.y = camera->position[Y];
  line.point.z = camera->position[Z];

  line.direction.x = vector[X];
  line.direction.y = vector[Y];
  line.direction.z = vector[Z];

  moebuis.center.x = object->position[X];
  moebuis.center.y = object->position[Y];
  moebuis.center.z = object->position[Z];

  moebuis.size.x = ((t_mobius *) object->son)->a;
  moebuis.size.y = ((t_mobius *) object->son)->b;
  moebuis.size.z = ((t_mobius *) object->son)->c;

  if (moebius_cast_get_k(&line, &moebuis, &out) == NULL)
    return (EXIT_FAILURE);
  detail->k = SMALLER_POSITIVE_NUMBER(out.a, out.b);
  detail->object = object;
  return (0);
}
