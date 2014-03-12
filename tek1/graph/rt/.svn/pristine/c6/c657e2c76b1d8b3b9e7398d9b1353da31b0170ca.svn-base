/*
** inter_cubetroue.c for raytracer in /home/guiho_r/tek1/rt/src/inter
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Mon May 14 22:31:25 2012 ronan guiho
** Last update Sat Jun  2 18:27:51 2012 alexis leprovost
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<math.h>

#include	"raytracer.h"
#include	"global.h"
#include	"camera.h"
#include        "object.h"
#include	"detail.h"
#include	"calc.h"
#include	"utils.h"
#include	"inter.h"

t_global	*global_thread;

int	inter_indice_cubetroue(t_camera *camera, t_object *object,
				       double *vector, double *indice)
{
  double	size;
  double	pos[NB_DIMENSION];
  double	u[NB_DIMENSION];

  if (modif_position(camera->position, object, pos, INVERSE_ROTATION) ||
      modif_vector(object->rotation, vector, u, INVERSE_ROTATION))
    return (EXIT_FAILURE);
  size =  ((t_cubetroue *)object->son)->radius;
  indice[A] = QUATRO(u[X]) + QUATRO(u[Y]) + QUATRO(u[Z]);
  indice[B] = 4.0 * (CUBE(u[X]) * pos[X] + CUBE(u[Y])	\
		     * pos[Y] + CUBE(u[Z]) * pos[Z]);
  indice[C] = 6.0 * (CARRE(u[X]) * CARRE(pos[X]) + CARRE(u[Y])		\
		     * CARRE(pos[Y]) + CARRE(u[Z]) * CARRE(pos[Z])) -	\
    5.0 * (CARRE(u[X]) + CARRE(u[Y]) + CARRE(u[Z]));
  indice[D] = 4.0 * (CUBE(pos[X]) * u[X] + CUBE(pos[Y])		\
		     * u[Y] + CUBE(pos[Z]) * u[Z]) - 10.0 *	\
    (u[X] * pos[X] + u[Y] * pos[Y] + u[Z] * pos[Z]);
  indice[E] = QUATRO(pos[X]) + QUATRO(pos[Y]) + QUATRO(pos[Z]) - 5.0	\
    * (CARRE(pos[X]) + CARRE(pos[Y]) + CARRE(pos[Z]));
  indice[E] += size;
  return (EXIT_SUCCESS);
}

int		inter_cubetroue(t_camera *camera, t_object *object,
				t_detail *detail, double *vector)
{
  double	k;
  double	k_tab[4];
  double	indice[5];

  if (!camera || !object || !detail || !vector ||
      inter_indice_cubetroue(camera, object, vector, indice))
    {
      return (EXIT_FAILURE);
    }
  inter_equation4deg(indice, k_tab);
  calc_limit(object, camera->position, vector, &k_tab[0]);
  calc_limit(object, camera->position, vector, &k_tab[1]);
  calc_limit(object, camera->position, vector, &k_tab[2]);
  calc_limit(object, camera->position, vector, &k_tab[3]);
  k = calcul_solution_smallest(k_tab);
  if (k > CONST_ERROR && (k < detail->k || detail->k < CONST_ERROR))
    {
      detail->k = k;
      detail->object = object;
    }
  return (EXIT_SUCCESS);
}
