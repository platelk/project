/*
** calc_light.c for calc_light in /home/vink/projet/graph/rtv1
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Fri Feb 10 11:02:23 2012 kevin platel
** Last update Sun Mar 11 14:00:50 2012 kevin platel
*/

#include <stdlib.h>
#include <math.h>
#include "rt.h"
#include "my_libX.h"
#include "my.h"
#include "light.h"

#define	COEF	 80
#define DIST_MAX 50

int	calc_color_light(t_object *obj, t_cam *cam, t_point *p, double mod)
{
  t_point	*n;
  t_point	*light;
  double	cos;
  t_color		color;
  double	dist;
  double	scal;

  color.color = p->color;
  n = init_point(p->x - obj->x, p->y - obj->y, p->z - obj->z, 0);
  light = init_point(p->x - obj->x, p->y - obj->y, p->z - obj->z, 0);
  n->x = n->x + cam->x;
  n->y = n->y + cam->y;
  n->z = n->z + cam->z;
  n = calc_scalaire(obj, n);
  dist = ((n->x * light->x) + (n->y * light->y) + (n->z * light->z));
  scal = (sqrt(pow(n->x, 2) + pow(n->y, 2) + pow(n->z, 2))
	  * (sqrt(pow(light->x, 2) + pow(light->y, 2)
		  + pow(light->z, 2))));
  cos = dist / scal;
  return (calc_color(obj, color, cos, mod));
}

int	calc_color_ombre(double k, int color, int mode)
{
  int	i;
  t_color	col;
  int		inten;

  if (color > 0)
    {
      i = 0;
      col.color = color;
      while (i < 4)
	{
	  if (mode == 0)
	    inten = ((col.tab[i]) - ((((k * (double) col.tab[i]) / 20.0))));
	  else
	    inten = ((col.tab[i]) + ((((k * (double) col.tab[i]) / 20.0))));
	  inten < 0 ? (inten = 0) :
	    (inten > 254) ? (inten = 254) : (inten = inten);
	  col.tab[i] = inten;
	  i++;
	}
      color = col.color;
    }
  return (color);
}

int	find_k_light(t_point *point, t_cam *cam, t_scene *scene, t_object *obj)
{
  double	k;
  t_object	*tmp2;
  int	color;
  int	mode;

  mode = 0;
  k = search_k(scene, cam, point, &tmp2);
  color = 0;
  if (scene && search_attr(scene->attr, "mode") != NULL)
    mode = my_getnbr(search_attr(scene->attr, "mode"));
  if (mode == 0)
    color = calc_color_light(obj, cam, point, k);
  else
    color = calc_color_ombre((k / 0.15), point->color, 1);
  if (k > 0.001 && k < 0.95)
    {
      if (mode == 0)
	color = calc_color_ombre((k / 0.01), 0, 0);
      else
	color = calc_color_ombre((k / 0.2), point->color, 0);
    }
  return (color);
}

int	get_color_light(t_object *obj, int color, double *vect, t_scene *scene)
{
  t_point	*point;
  t_cam	*cam;
 
  cam = malloc(sizeof(*cam));
  point = init_point(0, 0, 0, color);
  cam->x = scene->light->x;
  cam->y = scene->light->y;
  cam->z = scene->light->z;
  point->x = (scene->cam->x + vect[3] * vect[0]) - cam->x;
  point->y = (scene->cam->y + vect[3] * vect[1]) - cam->y;
  point->z = (scene->cam->z + vect[3] * vect[2]) - cam->z;
  color = find_k_light(point, cam, scene, obj);
  return (color);
}

int	calc_light(t_object *obj, double *vect, t_scene *scene, double rk)
{
  int	color;
  double	v[4];

  v[0] = vect[0];
  v[1] = vect[1];
  v[2] = vect[2];
  v[3] = rk;
  if (obj && search_attr(obj->attr, COL_STR) != NULL)
    color = my_getnbr(search_attr(obj->attr, COL_STR));
  else
    color = COLOR;
  while (scene->light && scene->light->next != NULL)
    {
      color = get_color_light(obj, color, v, scene);
      scene->light = scene->light->next;
    }
  if (scene->light)
    color = get_color_light(obj, color, v, scene);
  while (scene->light && scene->light->prev)
    scene->light = scene->light->prev;
  free(vect);
  return (color);
}
