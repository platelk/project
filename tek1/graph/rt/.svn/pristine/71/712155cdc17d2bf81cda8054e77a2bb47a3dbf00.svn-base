/*
** calc_management.c for raytracer in /home/leprov_a//depot/rt/src/calc
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Wed May  2 18:58:55 2012 alexis leprovost
** Last update Sun Jun  3 19:18:48 2012 alexis leprovost
*/

#include	<stdlib.h>
#include	<math.h>

#include	"raytracer.h"
#include	"global.h"
#include	"detail.h"
#include	"utils.h"
#include	"color.h"
#include	"calc.h"
#include	"init.h"
#include	"box.h"
#include	"my.h"

t_global	*global_thread;
pthread_mutex_t mutex;

static int
filter_color(t_color *color, int filter)
{
  int	grey;

  if (color == NULL || !filter)
    return (EXIT_FAILURE);
  if (filter < 0)
    {
      grey = (color->red + color->green + color->blue) / 3;
      color->red = grey;
      color->green = grey;
      color->blue = grey;
    }
  else
    {
      color->red = color->red * ((filter >> 16) / 255.0F);
      color->green = color->green * (((filter >> 8) % 256) / 255.0F);
      color->blue = color->blue * ((filter % 256) / 255.0F);
    }
  return (EXIT_SUCCESS);
}

static int
calc_wizzard(t_detail *detail, t_color *color,
	     t_camera *camera, double wizzard)
{
  double	alpha;
  double	range;

  if (detail == NULL || color == NULL || camera == NULL)
    return (EXIT_FAILURE);
  if (detail->k > 0.0F)
    range = (-1.0F) * sqrt(CARRE(detail->position[X] - camera->position[X]) \
			   + CARRE(detail->position[Y]			\
				   - camera->position[Y])		\
			   + CARRE(detail->position[Z]			\
				   - camera->position[Z])) / CONST_WIZZ;
  else
    range = (-1.0F) * sqrt(CARRE(camera->position[X] \
				 - (camera->position[X] * CONST_WIZZ))	\
			   + CARRE(camera->position[Y] \
				   - (camera->position[Y] * CONST_WIZZ)) \
			   + CARRE(camera->position[Z] \
				   - (camera->position[Z] * CONST_WIZZ))) \
      / CONST_WIZZ;
  alpha = exp(range * wizzard);
  color->red = (alpha * color->red) + ((1.0F - alpha) * 214.0F);
  color->green = (alpha * color->green) + ((1.0F - alpha) * 214.0F);
  color->blue = (alpha * color->blue) + ((1.0F - alpha) * 214.0F);
  return (EXIT_SUCCESS);
}

int
calc_management(t_global *global, t_color *color, double x, double y)
{
  t_object	*tmp;
  t_detail	detail;
  double	vector[NB_DIMENSION];

  tmp = NULL;
  if (global == NULL || global->scene == NULL)
    return (EXIT_FAILURE);
  tmp = global->scene->object;
  if (restat_color(color) || calc_direction_vector(global, vector, x, y) ||
      init_detail(&detail))
    return (EXIT_FAILURE);
  while (tmp)
    {
      if (inter_ray_box(global->scene->camera, vector, tmp))
	tmp->inter(global->scene->camera, tmp, &detail, vector);
      tmp = tmp->next;
    }
  if (detail.object != NULL)
    {
      calc_detail(&detail, color, global->scene->camera, vector);
      calc_effect(&detail, color, global->scene->light, vector);
    }
  calc_wizzard(&detail, color, global->scene->camera, global->scene->wizzard);
  filter_color(color, global->scene->filter);
  return (EXIT_SUCCESS);
}
