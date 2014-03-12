/*
** inter_paraboloide.c for raytracer in /home/leprov_a//depot/rt/src/inter
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Sun May 27 19:05:08 2012 alexis leprovost
** Last update Mon May 28 00:29:25 2012 alexis leprovost
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

int	inter_indice_paraboloide(t_camera *camera, t_object *object,
			     double *vector, double *indice)
{
  double	pos[NB_DIMENSION];
  double	u[NB_DIMENSION];
  double	cst;

  if (modif_position(camera->position, object, pos, INVERSE_ROTATION) ||
      modif_vector(object->rotation, vector, u, INVERSE_ROTATION))
    return (EXIT_FAILURE);
  cst = ((t_paraboloide *)object->son)->radius;
  indice[A] = CARRE(u[X]) + CARRE(u[Y]);
  indice[B] = (2.0F * pos[X] * u[X]) + (2.0F * pos[Y] * u[Y]) - (cst * u[Z]);
  indice[C] = CARRE(pos[X]) + CARRE(pos[Y]) - (cst * pos[Z]);
  indice[DELTA] = CARRE(indice[B]) - (4.000 * indice[A] * indice[C]);
  return (EXIT_SUCCESS);
}

int
inter_paraboloide(t_camera *camera, t_object *object, t_detail *detail, double *vector)
{
  double	indice[NB_INDICE];
  double	k[2];

  if (!camera || !object || !detail || !vector ||
      inter_indice_paraboloide(camera, object, vector, indice))
    return (EXIT_FAILURE);
  if (indice[DELTA] >= 0.000)
    {
      if (calc_k(indice, k))
	return (EXIT_FAILURE);
      if ((detail->k < CONST_ERROR && (k[0] > 0.0F || k[1] > 0.0F)) ||
	  (k[0] > CONST_ERROR && (k[1] > CONST_ERROR && k[0] < k[1]) && k[0] < detail->k) ||
	  (k[1] > CONST_ERROR && (k[0] > CONST_ERROR && k[1] < k[0]) && k[1] < detail->k))
	{
	  detail->k = SMALLER_POSITIVE_NUMBER(k[0], k[1]);
	  detail->object = object;
	}
    }
  return (EXIT_SUCCESS);
}
