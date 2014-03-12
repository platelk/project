/*
** normal_plan.c for raytracer in /home/leprov_a//depot/rt/src/normal
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Fri May 25 19:26:14 2012 alexis leprovost
** Last update Sun May 27 15:47:34 2012 alexis leprovost
*/

#include	<stdlib.h>

#include	"global.h"
#include	"detail.h"
#include	"calc.h"
#include	"utils.h"

int	normal_plan(double *n, t_detail *detail)
{
  if (n == NULL || detail == NULL)
    return (EXIT_FAILURE);
  n[X] = 0.0F;
  n[Y] = 0.0F;
  n[Z] = 1.0F;
  calc_rotation(n, detail->object->rotation, INVERSE_ROTATION);
  return (EXIT_SUCCESS);
}
