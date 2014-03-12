/*
** scene.h for raytracer in /home/leprov_a//depot/rt/inc
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Fri May  4 13:31:45 2012 alexis leprovost
** Last update Wed May 16 15:28:18 2012 harold ozouf
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
  t_image	*image;
  t_camera	*camera;
  t_object	*object;
  t_light	*light;
  double       	antialiasing;
  t_scene	*next;
  t_scene	*prev;
};

#endif
