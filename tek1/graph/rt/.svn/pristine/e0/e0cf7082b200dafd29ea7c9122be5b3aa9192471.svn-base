/*
** modif_position.c for raytracer in /home/leprov_a//depot/rt/src/calc
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Mon May  7 17:55:03 2012 alexis leprovost
** Last update Fri Jun  1 00:10:35 2012 alexis leprovost
*/

#include	<stdlib.h>

#include	"camera.h"
#include	"object.h"
#include	"calc.h"

int
modif_position(double *position, t_object *object,
	       double *location, int flag)
{
  if (!location || !object || !position)
    return (EXIT_FAILURE);
  location[X] = position[X] - object->position[X];
  location[Y] = position[Y] - object->position[Y];
  location[Z] = position[Z] - object->position[Z];
  calc_rotation(location, object->rotation, flag);
  return (EXIT_SUCCESS);
}

int
modif_vector(double *rotation, double *old_vector,
	     double *new_vector, int flag)
{
  if (!rotation || !old_vector || !new_vector)
    return (EXIT_FAILURE);
  new_vector[X] = old_vector[X];
  new_vector[Y] = old_vector[Y];
  new_vector[Z] = old_vector[Z];
  calc_rotation(new_vector, rotation, flag);
  return (EXIT_SUCCESS);
}
