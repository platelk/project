/*
** calc_img.c for calc_img in /home/vink/projet/graph/rtv1
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Thu Feb  9 10:02:13 2012 kevin platel
** Last update Sat Mar 10 17:08:48 2012 kevin platel
*/

#include <stdlib.h>
#include "my.h"
#include "mlx.h"
#include "point.h"
#include "scene.h"
#include "my_libX.h"
#include "rt.h"

t_point	*calc_img_color(t_point *point, t_scene *scene, t_point *p)
{
  if ((point->color = search_coli(scene, scene->cam, p)) == 0)
    {
      if (search_attr(scene->attr, "color") != NULL)
	point->color = my_getnbr(search_attr(scene->attr, "color"));
      else
	point->color = 0;
    }
  return (point);
}

t_imag	*calc_img(t_scene *scene, void *mlx_ptr)
{
  t_imag	*img;
  t_point	*point;
  t_point	*p;

  img = creat_img(scene, mlx_ptr);
  point = init_point(0, 0, scene->cam->fov, 0);
  p = init_point(-(img->width / 2), -(img->height / 2), scene->cam->fov, 0);
  while (point->x < (img->width))
    {
      point->y = 0;
      p->y = -(img->height / 2);
      while (point->y < img->height)
	{
	  point = calc_img_color(point, scene, p);
	  mlx_ppti(mlx_ptr, img, point);
	  p->y += 1;
	  point->y += 1;
	}
      p->x += 1;
      point->x += 1;
    }
  return (img);
}
