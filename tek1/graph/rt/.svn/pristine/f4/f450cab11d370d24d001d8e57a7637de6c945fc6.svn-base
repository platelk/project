/*
** inter_hyperboloide.c for raytracer in /home/leprov_a//depot/rt/src/inter
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Sun May 27 21:17:46 2012 alexis leprovost
** Last update Sun Jun  3 00:14:42 2012 zoe phalippou
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

int	inter_indice_hyperboloide(t_camera *camera, t_object *object,
			     double *vector, double *indice)
{
  double	pos[NB_DIMENSION];
  double	u[NB_DIMENSION];
  double	cst[NB_DIMENSION];

  if (modif_position(camera->position, object, pos, INVERSE_ROTATION) ||
      modif_vector(object->rotation, vector, u, INVERSE_ROTATION))
    return (EXIT_FAILURE);
  cst[A] = ((t_hyperboloide *)object->son)->a;
  cst[B] = ((t_hyperboloide *)object->son)->b;
  cst[C] = ((t_hyperboloide *)object->son)->c;
  indice[A] = (CARRE(u[X]) / CARRE(cst[A])) + (CARRE(u[Y]) / CARRE(cst[B])) \
    - (CARRE(u[Z]) / CARRE(cst[C]));
  indice[B] = 2.0F * (((pos[X] * u[X]) / CARRE(cst[A]))			\
		      + ((pos[Y] * u[Y]) / CARRE(cst[B]))		\
		      - ((pos[Z] * u[Z]) / CARRE(cst[C])));
  indice[C] = (CARRE(pos[X]) / CARRE(cst[A]))				\
    + (CARRE(pos[Y]) / CARRE(cst[B])) - (CARRE(pos[Z]) / CARRE(cst[C])) - 1.0F;
  indice[DELTA] = CARRE(indice[B]) - (4.0F * indice[A] * indice[C]);
  return (EXIT_SUCCESS);
}

int
inter_hyperboloide(t_camera *camera, t_object *object,
		   t_detail *detail, double *vector)
{
  double	indice[NB_INDICE];
  double	k[2];

  if (!camera || !object || !detail || !vector ||
      inter_indice_hyperboloide(camera, object, vector, indice))
    return (EXIT_FAILURE);
  if (indice[DELTA] >= 0.0F)
    {
      if (calc_k(indice, k))
	return (EXIT_FAILURE);
      if (object->inhibitor)
	obj_inhibitor(k, object, camera, vector);
      if (object->limit)
	{
	  calc_limit(object, camera->position, vector, &k[0]);
	  calc_limit(object, camera->position, vector, &k[1]);
	}
      if (!cmp_k(detail, k))
	{
	  detail->k = SMALLER_POSITIVE_NUMBER(k[0], k[1]);
	  detail->object = object;
	}
    }
  return (EXIT_SUCCESS);
}
