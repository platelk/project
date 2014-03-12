/*
** search_coli.c for search_coli in /home/vink/projet/graph/rtv1
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Thu Feb  9 10:53:49 2012 kevin platel
** Last update Sat Mar 10 17:24:32 2012 kevin platel
*/

#include <stdlib.h>
#include "my.h"
#include "scene.h"
#include "object.h"
#include "rt.h"
#include "point.h"
#include "camera.h"

double	 search_k(t_scene *scene, t_cam *cam, t_point *point, t_object **tmp)
{
  double	k;
  double	real_k;

  k = 0.0;
  real_k = 0.0;
  (*tmp) = NULL;
  while (scene && scene->obj && scene->obj != NULL)
    {
      k = calc_k(scene->obj, point, cam);
      if (k < real_k && real_k >= 0.0 && k >= 0.0)
	{
	  real_k = k;
	  (*tmp) = scene->obj;
	}
      else if (real_k == 0.0 && k >= 0.0)
	{
	  real_k = k;
	  (*tmp) = scene->obj;
	}
      scene->obj = scene->obj->next;
    }
  scene->obj = (*tmp);
  while (scene->obj && scene->obj->prev)
    scene->obj = scene->obj->prev;
  return (real_k);
}

int	search_coli(t_scene *scene, t_cam *cam, t_point *point)
{
  int		color;
  double	k;
  t_object	*tmp;
  t_object	*tmp2;
  t_point	*p;

  tmp2 = scene->obj;
  p = rotate(point, cam);
  k = search_k(scene, cam, p, &tmp);
  if (k <= 0.0)
    color = 0;
  else
    {
      if (tmp && search_attr(tmp->attr, COL_STR) != NULL)
	color = my_getnbr(search_attr(tmp->attr, COL_STR));
      else
	color = COLOR;
     scene->obj = tmp2;
      color = calc_light(tmp, calc_vect(p), scene, k);
    }
  scene->obj = tmp2;
  return (color);
}
