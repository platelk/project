/*
** calc_delta.c for calc_delta in /home/vink/projet/graph/rtv1
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Sat Mar 10 16:30:03 2012 kevin platel
** Last update Sun Mar 11 14:47:10 2012 kevin platel
*/

#include <stdlib.h>
#include <math.h>
#include "my.h"
#include "mlx.h"
#include "point.h"
#include "scene.h"
#include "my_libX.h"
#include "rt.h"

#define	X	(0)
#define	Y	(1)
#define	Z	(2)
#define RAD(x)  ((double) ((double) x * 3.1415) / 180.0)

double	*calc_vect(t_point *point)
{
  double	*vect;

  vect = malloc(3 * sizeof(*vect));
  if (vect == NULL)
    return (NULL);
  vect[X] = ((double) point->x);
  vect[Y] = ((double) point->y);
  vect[Z] = ((double) point->z);
  return (vect);
}

double	calc_delta_cone(t_object *object, double *vect, t_cam *cam)
{
  double	a;
  double	b;
  double	c;
  double	delta;
  t_point	*point;
  t_point	*point2;
  double	r;

  point = init_point(vect[X], vect[Y], vect[Z], 0);
  point2 = init_point(cam->x, cam->y, cam->z, 0);
  point2 = inv_rotate(point2, (t_cam *) object);
  point = inv_rotate(point, (t_cam *) object);
  r = (double) object->r;
  a = (pow(point->x, 2) + pow(point->z, 2) - (pow(point->y, 2) * pow(tan(RAD(r)), 2)));
  b = 2 * ((point->x * (point2->x - object->x)) + (point->z * (point2->z - object->z))
	   - (point->y * (point2->y - object->y) * pow(tan(RAD(r)), 2)));
  c = pow((point2->x - object->x), 2) + pow((point2->z - object->z), 2) 
       - (pow(((point2->y - object->y)), 2) * pow(tan(RAD(r)), 2));
  delta = (b * b) - (4.0 * a * c);
  vect[X] = b;
  vect[Y] = a;
  return (delta);
}

double	calc_delta_cyl(t_object *object, double *vect, t_cam *cam)
{
  double	a;
  double	b;
  double	c;
  double	delta;
  t_point	*point;
  t_point	*point2;

  point = init_point(vect[X], vect[Y], vect[Z], 0);
  point2 = init_point(cam->x, cam->y, cam->z, 0);
  point2 = inv_rotate(point2, (t_cam *) object);
  point = inv_rotate(point, (t_cam *) object);
  a = (pow(point->x, 2) + pow(point->z, 2));
  b = 2.0 * (((point2->x - object->x) * point->x)
	      + (point->z * (point2->z - object->z)));
  c = ((pow(point2->x - object->x, 2)) + (pow(point2->z - object->z, 2)))
    - ((object->r) * (object->r));
  delta = (b * b) - (4.0 * a * c);
  vect[X] = b;
  vect[Y] = a;
  return (delta);
}

double	calc_delta_sph(double *vect, t_object *object, t_cam *cam)
{
  double	a;
  double	b;
  double	c;
  double	delta;

  a = ((vect[X] * vect[X]) + (vect[Y] * vect[Y]) + (vect[Z] * vect[Z]));
  b = 2.0 * ((((cam->x - object->x) * vect[X])
	    + (vect[Y] * ((double) cam->y - (double) object->y))
	    + (((double) cam->z - (double) object->z) * vect[Z])));
  c = (((double) cam->x - (double) object->x)
       * ((double)cam->x - (double)object->x))
    + (((double) cam->y - (double) object->y)
     * ((double)cam->y - (double) object->y))
    + (((double) cam->z - (double) object->z)
     * ((double) cam->z - (double) object->z))
    - (((double) object->r) * ((double) object->r));
  free(vect);
  delta = (b * b) - (4.0 * a * c);
  return (delta);
}
