/*
** rotate.c for rotate in /home/vink/projet/graph/rtv1
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Wed Feb 22 21:20:42 2012 kevin platel
** Last update Thu Mar  1 15:22:54 2012 kevin platel
*/

#include <stdlib.h>
#include <math.h>
#include "my.h"
#include "scene.h"
#include "object.h"
#include "rt.h"
#include "point.h"
#include "camera.h"
#include "my_libX.h"

#define RAD(x)  ((double) x * 3.1415 / 180.0)

t_point	*rotate(t_point *p, t_cam *parm)
{
  t_point	*point;
  double	angle;

  point = init_point(0, 0, 0, 0);
  point->x = p->x;
  point->y = p->y;
  point->z = p->z;
  if (parm && search_attr(parm->attr, "rot_x") != NULL)
    angle = my_getnbr(search_attr(parm->attr, "rot_x"));
  else
    angle = 0.0;
  point = rotate_x(point, angle);
  if (parm && search_attr(parm->attr, "rot_y") != NULL)
    angle = my_getnbr(search_attr(parm->attr, "rot_y"));
  else
    angle = 0.0;
  point = rotate_y(point, angle);
  if (parm && search_attr(parm->attr, "rot_z") != NULL)
    angle = my_getnbr(search_attr(parm->attr, "rot_z"));
  else
    angle = 0.0;
  point = rotate_z(point, angle);
  return (point);
}

t_point	*inv_rotate(t_point *p, t_cam *parm)
{
  t_point	*point;
  double	angle;

  point = init_point(0, 0, 0, 0);
  point->x = p->x;
  point->y = p->y;
  point->z = p->z;
  if (parm && search_attr(parm->attr, "rot_x") != NULL)
    angle = -my_getnbr(search_attr(parm->attr, "rot_x"));
  else
    angle = 0.0;
  point = rotate_x(point, -angle);
  if (parm && search_attr(parm->attr, "rot_y") != NULL)
    angle = -my_getnbr(search_attr(parm->attr, "rot_y"));
  else
    angle = 0.0;
  point = rotate_y(point, -angle);
  if (parm && search_attr(parm->attr, "rot_z") != NULL)
    angle = -my_getnbr(search_attr(parm->attr, "rot_z"));
  else
    angle = 0.0;
  point = rotate_z(point, -angle);
  return (point);
}

t_point	        *rotate_x(t_point *coor, double ang)
{
  double	y;
  double	z;

  y = coor->y;
  z = coor->z;
  coor->y = ((cos(RAD(ang)) * y) - (sin(RAD(ang)) * z));
  coor->z = ((cos(RAD(ang)) * z) + (sin(RAD(ang)) * y));
  return (coor);
}

t_point	        *rotate_y(t_point *coor, double ang)
{
  double	x;
  double	z;

  x = coor->x;
  z = coor->z;
  coor->x = ((cos(RAD(ang)) * x) + (sin(RAD(ang)) * z));
  coor->z = ((cos(RAD(ang)) * z) - (sin(RAD(ang)) * x));
  return (coor);
}

t_point	        *rotate_z(t_point *coor, double ang)
{
  double	y;
  double	x;

  y = coor->y;
  x = coor->x;
  coor->y = ((cos(RAD(ang)) * y) + (sin(RAD(ang)) * x));
  coor->x = ((cos(RAD(ang)) * x) - (sin(RAD(ang)) * y));
  return (coor);
}
