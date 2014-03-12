/*
** light_management.c for raytracer in /home/leprov_a//depot/rt/src/light
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Thu May 10 12:52:15 2012 alexis leprovost
<<<<<<< .mine
** Last update Wed May 30 00:56:46 2012 ronan guiho
=======
** Last update Tue May 29 18:43:06 2012 alexis leprovost
>>>>>>> .r238
*/

#include	<stdlib.h>
#include	<math.h>
#include	<stdio.h>

#include	"detail.h"
#include	"color.h"
#include	"light.h"
#include	"calc.h"
#include	"utils.h"
#include	"shadow.h"

static int	light_ambient(t_detail *detail, t_color *color, t_light *light)
{
  t_light	*tmp;
  int	it;

  tmp = light;
  it = 0;
  if (detail == NULL || color == NULL || light == NULL)
    return (EXIT_FAILURE);
  while (tmp != NULL)
    {
      if (tmp->type == AMBIENT)
	{
	  color[1].red += (color[0].red * tmp->intensity);
	  color[1].green += (color[0].green * tmp->intensity);
	  color[1].blue += (color[0].blue * tmp->intensity);
	  ++it;
	}
      tmp = tmp->next;
    }
  color[1].red = ABS(CAST(color[1].red / (log(it) + 1.000)));
  color[1].green = ABS(CAST(color[1].green / (log(it) + 1.000)));
  color[1].blue = ABS(CAST(color[1].blue / (log(it) + 1.000)));
  return (EXIT_SUCCESS);
}

static int
get_vector_light(t_light *light, t_detail *detail, double *v)
{
  if (light == NULL || detail == NULL || v == NULL)
    return (EXIT_FAILURE);
  if (light->type == PARALLELE)
    cpy_point(v, light->location);
  if (light->type == DIFFUSE)
    calc_any_vector(detail->position, light->location, v);
  return (EXIT_SUCCESS);
}

static int
light_apply(t_light *light, t_detail *detail, double *theta, t_color *color)
{
  double	gamma;

  if (light == NULL || detail == NULL || color == NULL)
    return (EXIT_FAILURE);
  gamma = detail->object->effect[PHONG];
  color[2].red += ((color[0].red * theta[0]) +
		   (detail->object->effect[BRIGHTNESS] * light->color->red * theta[0]) +
		   (color[0].red * pow(theta[1], gamma))) * (light->color->red / 255.0F) *
    light->intensity * theta[2];
  color[2].green += ((color[0].green * theta[0]) +
		     (detail->object->effect[BRIGHTNESS] * light->color->green * theta[0]) +
		     (color[0].green * pow(theta[1], gamma))) * (light->color->green / 255.0F) *
    light->intensity * theta[2];
  color[2].blue += ((color[0].blue * theta[0]) +
		    (detail->object->effect[BRIGHTNESS] * light->color->blue * theta[0]) +
		    (color[0].blue * pow(theta[1], gamma))) * (light->color->blue / 255.0F) *
    light->intensity * theta[2];
  return (EXIT_SUCCESS);
}

int
get_vector_reflechie(double *i, double *n, double *r)
{
  double	ps;

  if (i == NULL || n == NULL || r == NULL)
    return (EXIT_FAILURE);
  ps = calc_ps(i, n);
  r[X] = ((-2.0F * ps * n[X])) + i[X];
  r[Y] = ((-2.0F * ps * n[Y])) + i[Y];
  r[Z] = ((-2.0F * ps * n[Z])) + i[Z];
  return (EXIT_SUCCESS);
}

static int
light_ponctual(t_detail *detail, t_color *color, t_light *light, double *vector)
{
  t_light	*tmp;
  double	l[NB_DIMENSION];
  double	r[NB_DIMENSION];
  double	theta[3];
  int	it;

  tmp = light;
  it = 0;
  if (detail == NULL || color == NULL || light == NULL || vector == NULL)
    return (0);
  while (tmp != NULL)
    {
      get_vector_light(tmp, detail, l);
      if (tmp->type != AMBIENT)
	{
	  theta[0] = calc_angle(l, detail->normal);
	  inverse_vector(l);
	  get_vector_reflechie(l, detail->normal, r);
	  inverse_vector(l);
	  theta[1] = calc_angle(r, l);
	  if ((theta[2] = shadow_management(detail, color, l)))
	    light_apply(tmp, detail, theta, color);
	  ++it;
	}
      tmp = tmp->next;
    }
  color[2].red = ABS(CAST(color[2].red / (log(it) + 1.0F)));
  color[2].green = ABS(CAST(color[2].green / (log(it) + 1.0F)));
  color[2].blue = ABS(CAST(color[2].blue / (log(it) + 1.0F)));
  return (EXIT_SUCCESS);
}

int
light_management(t_detail *detail, t_color *color, t_light *light, double *vector)
{
  t_color	tmp[3];

  tmp[0].red = color->red;
  tmp[0].green = color->green;
  tmp[0].blue = color->blue;
  restat_color(&tmp[1]);
  restat_color(&tmp[2]);
  light_ambient(detail, tmp, light);
  light_ponctual(detail, tmp, light, vector);
  color->red = ABS(CAST(tmp[1].red + tmp[2].red));
  color->green = ABS(CAST(tmp[1].green + tmp[2].green));
  color->blue = ABS(CAST(tmp[1].blue + tmp[2].blue));
  return (EXIT_SUCCESS);
}
