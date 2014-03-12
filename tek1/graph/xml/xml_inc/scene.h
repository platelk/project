/*
** scene.h for raytracer in /home/leprov_a//depot/rt/inc
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Fri May  4 13:31:45 2012 alexis leprovost
** Last update Mon May  7 12:40:59 2012 alexis leprovost
*/

#ifndef __SCENE_H__
#define __SCENE_H__

#include	"object.h"
#include	"camera.h"
#include	"light.h"

typedef struct s_scene
{
  t_object	*object;
  t_camera	*camera;
  t_light	*light;
  struct s_scene	*next;
  struct s_scene	*prev;
} t_scene;

#endif
