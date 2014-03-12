/*
** calc_management.c for raytracer in /home/leprov_a//depot/rt/src/calc
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Wed May  2 18:58:55 2012 alexis leprovost
** Last update Wed May 30 19:29:35 2012 alexis leprovost
*/

#include	<stdlib.h>

#include	"raytracer.h"
#include	"global.h"
#include	"detail.h"
#include	"utils.h"
#include	"color.h"
#include	"calc.h"
#include	"init.h"
#include	"box.h"
#include	"my.h"

static int
get_object(t_camera *camera, t_detail *detail, double *vector)
{
  t_object      *tmp;

  if (detail->object == NULL)
    return (EXIT_FAILURE);
  tmp = detail->object;
  while (tmp->prev)
    tmp = tmp->prev;
  init_detail(detail);
  while (tmp)
    {
      tmp->inter(camera, tmp, detail, vector);
      tmp = tmp->next;
    }
  return (EXIT_SUCCESS);
}

int
calc_glare(t_detail *detail, t_color *color, t_scene *scene, double *vector)
{
  t_detail	glare;
  t_light	*tmp;
  double	l[NB_DIMENSION];
  double	cosl;

  tmp = scene->light;
  glare.object = detail->object;
  while (tmp)
    {
      if (tmp->type == DIFFUSE)
	{
	  calc_any_vector(scene->camera->position, tmp->location, l);
	  cosl = calc_angle(l, vector);
	  get_object(scene->camera, &glare, l);
	  if (glare.object == NULL || glare.object->effect[TRANSPARENCY] || cosl > 0.0F)
	    {
	      color->red  += (255.0F * (tmp->color->red / 255.0F) * cosl);
	      color->green  += (255.0F * (tmp->color->green / 255.0F) * cosl);
	      color->blue  += (255.0F * (tmp->color->blue / 255.0F) * cosl);
	    }
	}
      tmp = tmp->next;
    }
  color->red = CAST(color->red);
  color->green = CAST(color->green);
  color->blue = CAST(color->blue);
  return (EXIT_SUCCESS);
}

int
calc_management(t_global *global, t_color *color, double x, double y)
{
  t_object	*tmp;
  t_detail	detail;
  double	vector[NB_DIMENSION];
  t_detail	data;

  tmp = NULL;
  tmp = global->scene->object;
  if (restat_color(color) || calc_direction_vector(global, vector, x, y) ||
      init_detail(&detail))
    return (EXIT_FAILURE);
  while (tmp)
    {
      /*      if (inter_ray_box(global->scene->camera, vector, tmp))*/
      tmp->inter(global->scene->camera, tmp, &detail, vector);
      tmp = tmp->next;
    }
  if (detail.object != NULL)
    {
      data = detail;
      calc_detail(&detail, color, global->scene->camera, vector);
      calc_effect(&detail, color, global->scene->light, vector);
      /*      calc_glare(&data, color, global->scene, vector);*/

    }
  return (EXIT_SUCCESS);
}
