/*
** calc_effect.c for raytracer in /home/leprov_a//depot/rt/src/calc
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Wed May  9 20:18:25 2012 alexis leprovost
** Last update Sat Jun  2 17:01:48 2012 alexis leprovost
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<math.h>

#include	"raytracer.h"
#include	"global.h"
#include	"detail.h"
#include	"object.h"
#include	"color.h"
#include	"light.h"
#include	"utils.h"
#include	"init.h"
#include	"calc.h"
#include	"my.h"

int
calc_effect(t_detail *detail, t_color *color, t_light *light, double *vector)
{
  t_color	tmp[CONST_REFL + 1];
  t_detail	data;
  int	i;

  if (detail == NULL || color == NULL || light == NULL || vector == NULL)
    return (EXIT_FAILURE);
  i = -1;
  while (++i <= CONST_REFL)
    {
      tmp[i].red = -1.0F;
      tmp[i].green = -1.0F;
      tmp[i].blue = -1.0F;
    }
  cpy_point(detail->position, data.position);
  cpy_point(detail->normal, data.normal);
  data.k = detail->k;
  data.object = detail->object;
  cpy_color(color, &tmp[0]);
  calc_reflection(detail, tmp, light, vector);
  cpy_color(&tmp[0], color);
  return (EXIT_SUCCESS);
}
