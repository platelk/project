/*
** calc_cut_texture.c for rt in /home/phalip_z//rt
** 
** Made by zoe phalippou
** Login   <phalip_z@epitech.net>
** 
** Started on  Thu May 31 15:51:57 2012 zoe phalippou
** Last update Sat Jun  2 23:50:05 2012 zoe phalippou
*/

#include <stdio.h>
#include <stdlib.h>

#include        "raytracer.h"
#include        "camera.h"
#include        "object.h"
#include        "detail.h"
#include        "calc.h"
#include        "utils.h"
#include        "inter.h"
#include	"texture.h"

static	int	put_nbr_k(t_object *obj)
{
  if ((int)obj->type != -1)
    {
      if (obj->type == SPHERE || obj->type == CON || obj->type == CYL
	  || obj->type == PARABOLOIDE ||  obj->type == HYPERBOLOIDE)
	return (2);
      if (obj->type == PLAN)
	return (1);
      if (obj->type == TORE)
	return (4);
    }
  return (0);
}

static int	condition_color(t_color *tcolor, t_color *color, int diff)
{
  if (tcolor)
    if ((tcolor->green <= (color->green + (double)diff)
	 && tcolor->green >= (color->green - (double)diff))
	&& (tcolor->red <= (color->red + (double)diff)
	    && tcolor->red >= (color->red - (double)diff)) &&
	(tcolor->blue <= (color->blue + (double)diff)
	 && tcolor->blue >= (color->blue - (double)diff)))
      return (EXIT_SUCCESS);
  return (EXIT_FAILURE);
}

static int	cut_text(t_object *obj, t_color *color)
{
  if (obj->image->cut_texture->flag == 1)
    {
      if (!condition_color(obj->image->cut_texture->tcolor,
			   color, obj->image->cut_texture->interval))
	return (EXIT_SUCCESS);
    }
  else if (obj->image->cut_texture->flag == 0)
    if (condition_color(obj->image->cut_texture->tcolor,
			color, obj->image->cut_texture->interval))
      return (EXIT_SUCCESS);
  return (EXIT_FAILURE);
}

int	calc_cut_texture(double *k, t_object *obj,
			 double *vector, t_camera *camera)
{
  int		nb_k;
  t_color	color;
  int		utils[2];
  int		i;
  double	pos[NB_DIMENSION];

  i = -1;
  utils[0] = (int)obj->type;
  utils[1] = TEXTURE;
  nb_k = put_nbr_k(obj);
  while (++i < nb_k)
    {
      if (calc_point(camera->position, vector, pos, k[i]))
	return (EXIT_FAILURE);
      texture_mapping(obj, &color, pos, utils);
      if (!cut_text(obj, &color))
	k[i] = -1.000;
     }
  return (EXIT_SUCCESS);
}
