/*
** calc_transparency.c for raytracer in /home/leprov_a//depot/rt/src/calc
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Tue May 29 22:24:36 2012 alexis leprovost
** Last update Wed May 30 16:25:28 2012 alexis leprovost
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
get_object(t_camera *camera, t_detail *detail, double *vector, t_color *color)
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

/*int	_get_vector_refracte(double *v, double *n, double n1, double n2, double *t)
{
  double	value;
  double	nf;
  double	angle;
  double	ps;
  double	test;

  if (v == NULL || n == NULL)
    return (EXIT_FAILURE);
  inverse_vector(v);
  test = (asin(((sin(30.0F / 180.0F) *  M_PI) * 1.0F) / 2.0F) / M_PI) * 180.0F;
  printf("%f %f\n", test, (acos(calc_angle(v, n)) / M_PI) * 180.0F);
  nf = n2 / n1;
  ps = calc_ps(v, n);
  inverse_vector(v);
  angle = asin((sin(((calc_angle(v, n) / 180.0F) * M_PI)) * n1) / n2);
  angle = cos(angle) / M_PI * 180.0F;
  t[X] = (nf * v[X]) - ((angle + (nf * ps)) * n[X]);
  t[Y] = (nf * v[Y]) - ((angle + (nf * ps)) * n[Y]);
  t[Z] = (nf * v[Z]) - ((angle + (nf * ps)) * n[Z]);
  printf("v: %f %f %f\n", v[X], v[Y], v[Z]);
  printf("t: %f %f %f\n", t[X], t[Y], t[Z]);
  sleep(1);
  return (EXIT_SUCCESS);
  }*/

int	get_vector_refracte(double *v, double *n, double n1, double n2)
{
  double	mr;
  double	cosi;
  double	cosr;
  double	t[NB_DIMENSION];

  mr = n1 / n2;
  normalize_vector(v);
  cosi = calc_angle(v, n);
  cosr = 1.0F - mr * mr * (1.0F - cosi * cosi);
  /*  printf("cos1:%f - cosr:%f\n", CONVERT_RADIAN(acos(cosi)), CONVERT_RADIAN(acos(cosr)));*/
  if (cosr > 0.0F)
    {
      v[X] = (mr * v[X]) + (mr * cosi - sqrt(cosr)) * n[X];
      v[Y] = (mr * v[Y]) + (mr * cosi - sqrt(cosr)) * n[Y];
      v[Z] = (mr * v[Z]) + (mr * cosi - sqrt(cosr)) * n[Z];
    }
  return (EXIT_SUCCESS);
}

int
calc_refraction(t_detail *detail, t_color *color, t_light *light, double *vector)
{
  static int	i;
  t_camera	camera;
  t_object	*tmp;
  double	mat;

  mat = 1.0F;
  if (i >= CONST_TRANS || detail->object == NULL || !detail->object->effect[TRANSPARENCY])
    {
      if (detail->object)
	light_management(detail, &color[i], light, vector);
      else
	{
	  color[i].red = 0.0F;
	  color[i].green = 0.0F;
	  color[i].blue = 0.0F;
	}
      return (EXIT_SUCCESS);
    }
  light_management(detail, &color[i], light, vector);
  cpy_point(detail->position, camera.position);
  get_vector_refracte(vector, detail->normal, 1.0F, 1.0F);
  ++i;
  tmp = detail->object;
  get_object(&camera, detail, vector, &color[i]);
  calc_refraction(detail, color, light, vector);
  --i;
  if (tmp != NULL && tmp->effect[TRANSPARENCY] &&
      (color[i + 1].red >= 0.0F && color[i + 1].green >= 0.0F && color[i + 1].blue >= 0.0F))
    {
      color[i].red = (color[i + 1].red * tmp->effect[TRANSPARENCY]) +
	(color[i].red * (1.0F - tmp->effect[TRANSPARENCY]));
      color[i].green = (color[i + 1].green * tmp->effect[TRANSPARENCY]) +
	(color[i].green * (1.0F - tmp->effect[TRANSPARENCY]));
      color[i].blue = (color[i + 1].blue * tmp->effect[TRANSPARENCY]) +
	(color[i].blue * (1.0F - tmp->effect[TRANSPARENCY]));
    }
  return (EXIT_SUCCESS);
}

int
refraction_management(t_detail *detail, t_color *color, t_light *light, double *vector)
{
  t_color	tmp[CONST_TRANS + 1];
  double	tv[NB_DIMENSION];
  t_detail	td;
  int		i;

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
  tmp[0].red = color->red;
  tmp[0].green = color->green;
  tmp[0].blue = color->blue;
  calc_refraction(&td, tmp, light, tv);
  color->red = tmp[0].red;
  color->green = tmp[0].green;
  color->blue = tmp[0].blue;
  return (EXIT_SUCCESS);
}
