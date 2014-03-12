/*
** calc_k.c for calc_k in /home/vink/projet/graph/rtv1
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Thu Feb  9 11:05:24 2012 kevin platel
** Last update Sat Mar 10 17:10:18 2012 kevin platel
*/

#include <stdlib.h>
#include <math.h>
#include "my.h"
#include "scene.h"
#include "object.h"
#include "rt.h"
#include "point.h"
#include "camera.h"
#include "my_libX.h"

#define	X	(0)
#define	Y	(1)
#define	Z	(2)
#define RAD(x)  ((double) x * 3.1415 / 180.0)

double	calc_sph(t_object *object, double *vect, t_cam *cam)
{
  double	x1;
  double	x2;
  double	delta;
  double	a;
  double	b;

  a = ((vect[X] * vect[X]) + (vect[Y] * vect[Y]) + (vect[Z] * vect[Z]));
  b = 2.0 * ((((cam->x - object->x) * vect[X])
	    + (vect[Y] * ((double) cam->y - (double) object->y))
	    + (((double) cam->z - (double) object->z) * vect[Z])));
  delta = calc_delta_sph(vect, object, cam);
  if (delta < 0.0)
    return (-1.0);
  if (delta == 0.0)
    return ((-b) / 2.0 * a);
  x1 = (-b - sqrt(delta)) / (2.0 * a);
  x2 = (-b + sqrt(delta)) / (2.0 * a);
  if (x1 < x2 && x1 > 0.0)
    return (x1);
  else if (x2 < x1 && x2 > 0.0)
    return (x2);
  else
    return (0.0);
}

double	calc_cyl(t_object *object, double *vect, t_cam *cam)
{
  double	a;
  double	b;
  double	x1;
  double	x2;
  double	delta;

  delta = calc_delta_cyl(object, vect, cam);
  a = vect[Y];
  b = vect[X];
  free(vect);
  if (delta < 0.0)
    return (-1.0);
  if (delta == 0.0)
    return ((-b) / 2.0 * a);
  x1 = (-b - sqrt(delta)) / (2.0 * a);
  x2 = (-b + sqrt(delta)) / (2.0 * a);
  if (x1 < x2 && x1 > 0.0)
    return (x1);
  else if (x2 < x1 && x2 > 0.0)
    return (x2);
  else
    return (0.0);
}

double	calc_cone(t_object *object, double *vect, t_cam *cam)
{
  double	a;
  double	b;
  double	delta;
  double	x1;
  double	x2;

  delta = calc_delta_cone(object, vect, cam);
  a = vect[Y];
  b = vect[X];
  if (delta < 0.0)
    return (-1.0);
  if (delta == 0.0)
    return ((-b) / 2.0 * a);
  x1 = (-b - sqrt(delta)) / (2.0 * a);
  x2 = (-b + sqrt(delta)) / (2.0 * a);
  if (x1 < x2 && x1 > 0.0)
    return (x1);
  else if (x2 < x1 && x2 > 0.0)
    return (x2);
  else
    return (0.0);
}

double	calc_plan(t_object *object, double *vect, t_cam *cam)
{
  double	vect_y;
  t_point	*point;
  t_point	*point2;
  t_point	*point3;

  vect_y = vect[Y];
  point = init_point(object->x, object->y, object->z, 0);
  point2 = init_point(cam->x, cam->y, cam->z, 0);
  point3 = init_point(vect[X], vect[Y], vect[Z], 0);
  free(vect);
  point2 = inv_rotate(point2, (t_cam *) object);
  point3 = inv_rotate(point3, (t_cam *) object);
  if (vect_y == 0.0)
    return (-1.0);
  if (-(point2->y - (point->y)) < 0.0)
    return (-1.0);
  return (-((point2->y - (point->y)) / point3->y));
}

double	calc_k(t_object *object, t_point *point, t_cam *cam)
{
  if (object->type == SPHERE)
    return (calc_sph(object, calc_vect(point), cam));
  if (object->type == PLAN)
    return (calc_plan(object, calc_vect(point), cam));
  if (object->type == CYL)
    return (calc_cyl(object, calc_vect(point), cam));
  if (object->type == CONE)
    return (calc_cone(object, calc_vect(point), cam));
  return (-1.0);
}
