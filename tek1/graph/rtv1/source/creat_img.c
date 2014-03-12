/*
** creat_img.c for creat_img.c in /home/vink/projet/graph/rtv1
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Thu Feb  9 10:04:54 2012 kevin platel
** Last update Thu Feb  9 13:06:15 2012 kevin platel
*/

#include <stdlib.h>
#include "my.h"
#include "mlx.h"
#include "point.h"
#include "scene.h"
#include "my_libX.h"
#include "rt.h"

t_imag	*creat_img(t_scene *scene, void *mlx_ptr)
{
  int	width;
  int	height;
  t_imag	*img;

  width = WIDTH;
  height = HEIGHT;
  if (search_attr(scene->attr, "width") != NULL)
    width = my_getnbr(search_attr(scene->attr, "width"));
  if (search_attr(scene->attr, "height") != NULL)
    height = my_getnbr(search_attr(scene->attr, "height"));
  img = init_img(mlx_ptr, width, height);
  return (img);
}
