/*
** calc_vect.c for raytracer in /home/leprov_a//depot/rt/src/calc
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Fri May  4 14:10:16 2012 alexis leprovost
** Last update Fri Jun  1 16:06:46 2012 zoe phalippou
*/

#include	<stdlib.h>

#include	"raytracer.h"
#include	"global.h"
#include	"camera.h"
#include	"calc.h"
#include	"utils.h"

int	calc_direction_vector(t_global *global,
			      double *vector, double x, double y)
{
  if (!vector || !global || !global->scene || !global->scene->camera)
    return (EXIT_FAILURE);
  vector[X] = global->scene->camera->fov;
  vector[Y] = ((double)global->window->x_win / 2.0F) - x;
  vector[Z] = ((double)global->window->y_win / 2.0F) - y;
  vector[X] -= global->scene->camera->position[X];
  vector[Y] -= global->scene->camera->position[Y];
  vector[Z] -= global->scene->camera->position[Z];
  calc_rotation(vector, global->scene->camera->rotation, NORMAL_ROTATION);
  return (EXIT_SUCCESS);
}

int	calc_any_vector(double *p1, double *p2, double *v)
{
  if (p1 == NULL || p2 == NULL || v == NULL)
    return (EXIT_FAILURE);
  v[X] = p2[X] - p1[X];
  v[Y] = p2[Y] - p1[Y];
  v[Z] = p2[Z] - p1[Z];
  return (EXIT_SUCCESS);
}
