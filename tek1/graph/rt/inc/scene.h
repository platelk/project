/*
** scene.h for raytracer in /home/leprov_a//depot/rt/inc
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
0** Started on  Fri May  4 13:31:45 2012 alexis leprovost
** Last update Sun Jun  3 15:05:28 2012 alexis leprovost
*/

#ifndef __SCENE_H__
#define __SCENE_H__

#include	"global.h"
#include	"camera.h"
#include	"light.h"
#include	"image.h"
#include	"object.h"

struct s_scene
{
  int		id;
  int		filter;
  t_image	*image;
  t_camera	*camera;
  t_object	*object;
  t_light	*light;
  double	wizzard;
  double       	antialiasing;
  t_scene	*next;
  t_scene	*prev;
};

#endif
