/*
** calc_transparency.c for raytracer in /home/leprov_a//depot/rt/src/calc
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Tue May 29 22:24:36 2012 alexis leprovost
** Last update Sun Jun  3 17:17:03 2012 alexis leprovost
*/

#include	<stdlib.h>
#include	<math.h>

#include	"raytracer.h"
#include	"global.h"
#include	"detail.h"
#include	"texture.h"
#include	"camera.h"
#include	"light.h"
#include	"utils.h"
#include	"calc.h"
#include	"init.h"

static int
get_object_refracte(t_camera *camera, t_detail *detail,
		    double *vector, t_color *color)
{
  t_object      *tmp;
  t_object	*data;

  data = detail->object;
  tmp = detail->object;
  while (tmp->prev)
    tmp = tmp->prev;
  init_detail(detail);
  while (tmp)
    {
      if (tmp != data)
	tmp->inter(camera, tmp, detail, vector);
      tmp = tmp->next;
    }
  if (detail->object != NULL)
    calc_detail(detail, color, camera, vector);
  return (EXIT_SUCCESS);
}

static int
get_color_refracte(t_color *color, t_object *tmp, int i)
{
  if (color == NULL || tmp == NULL || i < 0)
    return (EXIT_FAILURE);
  color[i].red = (color[i + 1].red * tmp->effect[TRANSPARENCY])	\
    + (color[i].red * (1.0F - tmp->effect[TRANSPARENCY]));
  color[i].green = (color[i + 1].green * tmp->effect[TRANSPARENCY])	\
    + (color[i].green * (1.0F - tmp->effect[TRANSPARENCY]));
  color[i].blue = (color[i + 1].blue * tmp->effect[TRANSPARENCY])	\
    + (color[i].blue * (1.0F - tmp->effect[TRANSPARENCY]));
  return (EXIT_SUCCESS);
}

int
calc_refraction(t_detail *detail, t_color *color,
		t_light *light, double *vector)
{
  static int	i;
  t_camera	camera;
  t_object	*tmp;

  if (i >= CONST_TRANS || detail->object == NULL
      || !detail->object->effect[TRANSPARENCY])
    {
      if (detail->object)
	return (light_management(detail, &color[i], light, vector));
      else
	return (restat_color(&color[i]));
    }
  light_management(detail, &color[i], light, vector);
  cpy_point(detail->position, camera.position);
  get_vector_refracte(vector, detail->normal, 1.0F, detail->object->material);
  ++i;
  tmp = detail->object;
  get_object_refracte(&camera, detail, vector, &color[i]);
  calc_refraction(detail, color, light, vector);
  --i;
  if (tmp != NULL && tmp->effect[TRANSPARENCY] &&
      (color[i + 1].red >= 0.0F
       && color[i + 1].green >= 0.0F && color[i + 1].blue >= 0.0F))
    get_color_refracte(color, tmp, i);
  return (EXIT_SUCCESS);
}

int
refraction_management(t_detail *detail,
		      t_color *color, t_light *light, double *vector)
{
  t_color	tmp[CONST_TRANS + 1];
  double	tv[NB_DIMENSION];
  t_detail	td;
  int		i;

  if (detail == NULL || color == NULL || light == NULL || vector == NULL)
    return (EXIT_FAILURE);
  i = -1;
  while (++i <= CONST_TRANS)
    {
      tmp[i].red = -1.0F;
      tmp[i].green = -1.0F;
      tmp[i].blue = -1.0F;
    }
  cpy_point(vector, tv);
  cpy_point(detail->position, td.position);
  cpy_point(detail->normal, td.normal);
  td.k = detail->k;
  td.object = detail->object;
  cpy_color(color, &tmp[0]);
  calc_refraction(&td, tmp, light, tv);
  cpy_color(&tmp[0], color);
  return (EXIT_SUCCESS);
}
