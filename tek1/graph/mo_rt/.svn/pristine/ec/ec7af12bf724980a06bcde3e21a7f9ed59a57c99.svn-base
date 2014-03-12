/*
** inter_moebius.c for moebuis in /home/vink/projet/graph/rt/src/inter
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Sun May 27 14:18:03 2012 kevin platel
** Last update Tue May 29 03:04:40 2012 kevin platel
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
  double	vec[NB_DIMENSION];
  t_sphere	sphere;
  t_object	tmp;

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

  if (object->son == NULL)
    return (EXIT_FAILURE);
  moebuis.size.x = ((t_mobius *) object->son)->a;
  moebuis.size.y = ((t_mobius *) object->son)->b;
  moebuis.size.z = ((t_mobius *) object->son)->c;

  if (moebius_cast_get_k(&line, &moebuis, &out, vec) == NULL)
    return (EXIT_FAILURE);
  sphere.radius = MO_PRES;
  tmp.position[X] = vec[X];
  tmp.position[Y] = vec[Y];
  tmp.position[Z] = vec[Z];
  tmp.rotation[X] = object->rotation[X];
  tmp.rotation[Y] = object->rotation[Y];
  tmp.rotation[Z] = object->rotation[Z];
  tmp.son = &sphere;
  tmp.inhibitor = NULL;
  inter_sphere(camera, &tmp, detail, vector);
  detail->object = object;
  return (0);
}
