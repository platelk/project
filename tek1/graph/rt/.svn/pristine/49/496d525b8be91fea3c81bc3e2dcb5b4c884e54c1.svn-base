/*
** inter_triangle.c for inter_triangle in /home/ozouf_h//rt/parser_3ds
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Fri Jun  1 01:41:16 2012 harold ozouf
** Last update Sun Jun  3 17:38:37 2012 harold ozouf
*/

#include	<math.h>
#include	<stdlib.h>
#include	"raytracer.h"
#include	"camera.h"
#include	"calc.h"
#include        "utils.h"
#include        "object.h"
#include	"detail.h"
#include	"init_triangle.h"
#include	"inter.h"

int     test_prod_vect(double *pt1, double *pt2, double *pt3, double *norm)
{
  double	t[3];
  double        res;

  t[0] = (((pt2[Y] - pt1[Y]) * (pt3[Z] - pt1[Z]))	\
	   - ((pt3[Y] - pt1[Y]) * (pt2[Z] - pt1[Z])));
  t[1] = (((pt2[Z] - pt1[Z]) * (pt3[X] - pt1[X]))	\
	   - ((pt3[Z] - pt1[Z]) * (pt2[X] - pt1[X])));
  t[2] = (((pt2[X] - pt1[X]) * (pt3[Y] - pt1[Y]))	\
	   - ((pt3[X] - pt1[X]) * (pt2[Y] - pt1[Y])));
  res = t[0] * norm[X] + t[1] * norm[Y] + t[2] * norm[Z];
  return ((res < 0.000001) ? (0) : (1));
}

int     intersect_tri(double *res, t_triangle *o, double *pos, double *vect)
{
  double        p;
  double        t;

  p = o->n[X] * vect[X] + o->n[Y] * vect[Y] + o->n[Z] * vect[Z];
  if (p < 0.0001)
    {
      t = -(o->n[X] * (pos[X] - o->pt1[X]) + o->n[Y] *
	    (pos[Y] - o->pt1[Y]) + o->n[Z] * (pos[Z] - o->pt1[Z]))/
	(o->n[X] * vect[X] + o->n[Y] * vect[Y] + o->n[Z] * vect[Z]);
      if (t < 0.00001)
        return (EXIT_FAILURE);
      res[X] = pos[X] + vect[X] * t;
      res[Y] = pos[Y] + vect[Y] * t;
      res[Z] = pos[Z] + vect[Z] * t;
      if (test_prod_vect(o->pt1, o->pt2, res, o->n))
	if (test_prod_vect(o->pt2, o->pt3, res, o->n))
	  if (test_prod_vect(o->pt3, o->pt1, res, o->n))
	    return (EXIT_SUCCESS);
    }
  return (EXIT_FAILURE);
}

int
inter_triangle(t_camera *camera, t_object *o, t_detail *detail,
	       double *vector)
{
  double	res[3];
  double	dist;

  if (o && o->son && camera)
    if (intersect_tri(res, \
			    ((t_triangle *)o->son), \
			    camera->position, vector) == EXIT_SUCCESS)
      {
	dist = sqrt(pow(res[X] - camera->position[X], 2) + \
		    pow(res[Y] - camera->position[Y], 2) + \
		    pow(res[Z] - camera->position[Z], 2));
	detail->k = dist / sqrt(vector[X] * vector[X] + vector[Y] * \
				vector[Y] + vector[Z] * vector[Z]);
	detail->object = o;
	copy_tab(detail->normal, ((t_triangle *)o->son)->n);
	detail->non_initialize = 1;
	return (EXIT_SUCCESS);
      }
  return (EXIT_FAILURE);
}

int
inter_blender(t_camera *camera, t_object *o, t_detail *detail,
	      double *vector)
{
  camera = camera;
  o = o;
  detail = detail;
  vector = vector;
  return (EXIT_FAILURE);
}
