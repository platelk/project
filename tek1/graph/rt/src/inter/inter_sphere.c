/*
** inter_sphere.c for raytracer in /home/leprov_a//depot/rt/src/inter
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Mon May  7 18:14:45 2012 alexis leprovost
** Last update Sun Jun  3 06:16:27 2012 ronan guiho
*/

#include	<stdlib.h>
#include	<stdio.h>

#include	"raytracer.h"
#include	"camera.h"
#include        "object.h"
#include	"detail.h"
#include	"calc.h"
#include	"utils.h"
#include	"inter.h"
#include	"objects_neg.h"

int	inter_indice_sphere(t_camera *camera, t_object *object,
			     double *vector, double *indice)
{
  double	pos[NB_DIMENSION];
  double	u[NB_DIMENSION];

  if (modif_position(camera->position, object, pos, INVERSE_ROTATION) ||
      modif_vector(object->rotation, vector, u, INVERSE_ROTATION))
    return (EXIT_FAILURE);
  indice[A] = CARRE(u[X]) + CARRE(u[Y]) + CARRE(u[Z]);
  indice[B] = 2.000 * ((pos[X] * u[X]) + (pos[Y] * u[Y]) + (pos[Z] * u[Z]));
  indice[C] = CARRE(pos[X]) + CARRE(pos[Y]) + CARRE(pos[Z]) -
    CARRE(((t_sphere *)object->son)->radius);
  indice[DELTA] = CARRE(indice[B]) - (4.000 * indice[A] * indice[C]);
  return (EXIT_SUCCESS);
}

int	inter_sphere_k(t_detail *detail, double *k, t_object *object)
{
  if (!cmp_k(detail, k))
    {
      detail->object = object;
      detail->k = SMALLER_POSITIVE_NUMBER(k[0], k[1]);
    }
  return (EXIT_SUCCESS);
}

int
inter_sphere(t_camera *camera, t_object *object,
	     t_detail *detail, double *vector)
{
  double	indice[NB_INDICE];
  double	k[2];

  if (!camera || !object || !detail || !vector ||
      inter_indice_sphere(camera, object, vector, indice))
    return (EXIT_FAILURE);
  if (indice[DELTA] >= 0.0F)
    {
      if (calc_k(indice, k))
	return (EXIT_FAILURE);
      if (object->inhibitor)
	obj_inhibitor(k, object, camera, vector);
      calc_limit(object, camera->position, vector, &k[0]);
      calc_limit(object, camera->position, vector, &k[1]);
      if (object->image != NULL && object->image->type_texture == 1)
	{
	  if (calc_cut_texture(k, object, vector, camera))
	    return (EXIT_FAILURE);
	}
      inter_sphere_k(detail, k, object);
    }
  return (EXIT_SUCCESS);
}
