/*
** camera.h for camera in /home/platel_k/projet/graph/rtv1/source
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Wed Feb  1 10:28:31 2012 kevin platel
** Last update Thu Feb 23 10:12:23 2012 kevin platel
*/

#ifndef __CAMERA_H__
#define __CAMERA_H__

#include "attribute.h"

typedef struct s_cam
{
  double	x;
  double	y;
  double	z;
  double	fov;
  void	*father;
  t_attr	*attr;
  struct s_cam *next;
  struct s_cam *prev;
} t_cam;

#endif
