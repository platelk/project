/*
** calc_reflection.c for raytracer in /home/leprov_a//depot/rt/src/calc
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Mon May 28 21:13:16 2012 alexis leprovost
** Last update Sat Jun  2 17:33:20 2012 alexis leprovost
*/

#include	<stdlib.h>
#include	<stdio.h>

#include	"raytracer.h"
#include	"global.h"
#include	"detail.h"
#include	"camera.h"
#include	"light.h"
#include	"utils.h"
#include	"calc.h"
#include	"init.h"

static int
get_object_reflechie(t_camera *camera, t_detail *detail,
	   double *vector, t_color *color)
{
  t_object      *tmp;

  tmp = detail->object;
  while (tmp->prev)
    tmp = tmp->prev;
  init_detail(detail);
  while (tmp)
    {
      tmp->inter(camera, tmp, detail, vector);
      tmp = tmp->next;
    }
  if (detail->object != NULL)
    calc_detail(detail, color, camera, vector);
  return (EXIT_SUCCESS);
}

static int
get_color_reflechie(t_color *color, t_object *tmp, int i)
{
  if (color == NULL || tmp == NULL || i < 0)
    return (EXIT_FAILURE);
  color[i].red = (color[i + 1].red * tmp->effect[REFLECTION])
    + (color[i].red * (1.0F - tmp->effect[REFLECTION]));
  color[i].green = (color[i + 1].green * tmp->effect[REFLECTION])
    + (color[i].green * (1.0F - tmp->effect[REFLECTION]));
  color[i].blue = (color[i + 1].blue * tmp->effect[REFLECTION])
    + (color[i].blue * (1.0F - tmp->effect[REFLECTION]));
  return (EXIT_SUCCESS);
}

int
calc_reflection(t_detail *detail, t_color *color,
		t_light *light, double *vector)
{
  static int	i;
  t_camera	camera;
  t_object	*tmp;

  if (i >= CONST_REFL || detail->object == NULL
      || !detail->object->effect[REFLECTION])
    {
      if (detail->object)
	return (refraction_management(detail, &color[i], light, vector));
      else
	return (restat_color(&color[i]));
    }
  refraction_management(detail, &color[i], light, vector);
  cpy_point(detail->position, camera.position);
  get_vector_reflechie(vector, detail->normal, vector);
  ++i;
  tmp = detail->object;
  get_object_reflechie(&camera, detail, vector, &color[i]);
  calc_reflection(detail, color, light, vector);
  --i;
  if (tmp != NULL && tmp->effect[REFLECTION] &&
      (color[i + 1].red >= 0.0F
       && color[i + 1].green >= 0.0F && color[i + 1].blue >= 0.0F))
    get_color_reflechie(color, tmp, i);
  return (EXIT_SUCCESS);
}
