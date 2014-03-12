/*
** inter_sphere.c for raytracer in /home/leprov_a//depot/rt/src/inter
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Mon May  7 18:14:45 2012 alexis leprovost
** Last update Tue May 29 18:56:23 2012 zoe phalippou
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

int
inter_sphere(t_camera *camera, t_object *object, t_detail *detail, double *vector)
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
      if ((detail->k < CONST_ERROR && (k[0] > CONST_ERROR || k[1] > CONST_ERROR)) ||
	  (k[0] > CONST_ERROR && (k[1] > CONST_ERROR && k[0] < k[1]) && k[0] < detail->k) ||
	  (k[1] > CONST_ERROR && (k[0] > CONST_ERROR && k[1] < k[0]) && k[1] < detail->k))
	{
	  detail->k = SMALLER_POSITIVE_NUMBER(k[0], k[1]);
	  detail->object = object;
	}
    }
  return (EXIT_SUCCESS);
}
