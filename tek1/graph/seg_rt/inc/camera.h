/*
** camera.h for raytracer in /home/leprov_a//depot/rt/inc
**
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
**
** Started on  Fri May  4 15:00:05 2012 alexis leprovost
** Last update Tue May  8 17:11:09 2012 alexis leprovost
*/

#ifndef __CAMERA_H__
#define __CAMERA_H__

#include	"raytracer.h"
#include	"global.h"

struct s_camera
{
  double	fov;
  double	position[NB_DIMENSION];
  double	rotation[NB_DIMENSION];
  t_camera	*next;
  t_camera	*prev;
};

#endif
