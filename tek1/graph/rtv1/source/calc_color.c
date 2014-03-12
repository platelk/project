/*
** calc_color.c for color in /home/vink/projet/graph/rtv1
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Thu Mar  8 18:05:48 2012 kevin platel
** Last update Sat Mar 10 17:40:50 2012 kevin platel
*/

#include <stdlib.h>
#include <math.h>
#include "rt.h"
#include "my_libX.h"
#include "my.h"
#include "light.h"

t_point	*calc_scalaire(t_object *obj, t_point *point)
{
  if (obj->type == SPHERE)
    return (point);
  else if (obj->type == PLAN)
    {
      point->x = 0;
      point->y = 100;
      point->z = 0;
      point = rotate(point, (t_cam *) obj);
      return (point);
    }
  else if (obj->type == CYL)
    {
      point->y = 0;
      point = rotate(point, (t_cam *) obj);
      return (point);
    }
  else if (obj->type == CONE)
    {
      point->y = point->y * -1.6;
      point = rotate(point, (t_cam *) obj);
      return (point);
    }
  return (point);
}

int	calc_color(t_object *obj, t_color color, double cos, double k)
{
  int	i;
  int	col;

  i = 0;
  cos < 0.0 ? (cos = -cos) : (cos = cos);
  if (obj->type == PLAN)
    cos = cos * 3.0;
  if (obj->type == SPHERE)
    cos = cos * 1.8;
  k = k / 0.2;
  if (k < 20.0)
    {
      while (i < 4)
	{
	  col = (color.tab[i] * (cos)) - ((k * color.tab[i]) / 20.0);
	  if (col > 254)
	    col = 254;
	  if (col < 0)
	    col = 0;
	  color.tab[i] = col;
	  i++;
	}
    }
  return (color.color);
}

int	moy_col(int color, int old)
{
  t_color	col;
  t_color	old_col;
  int	ret;
  int	i;

  col.color = color;
  old_col.color = old;
  i = 0;
  while (i < 4)
    {
      ret = (col.tab[i] - old_col.tab[i]) + old_col.tab[i];
      if (ret < 0)
	ret = 0;
      if (ret > 254)
	ret = 254;
      col.tab[i] = (char) ret;
      i++;
    }
  return (col.color);
}
