/*
** scene.h for scene in /home/vink/projet/graph/rtv1/source
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Wed Feb  8 10:20:00 2012 kevin platel
** Last update Wed Feb  8 23:16:20 2012 kevin platel
*/

#ifndef __SCENE_H__
#define __SCENE_H__

#include "object.h"
#include "light.h"
#include "camera.h"
#include "attribute.h"

typedef struct s_scene
{
  t_attr   *attr;
  t_object *obj;
  t_light  *light;
  t_cam	   *cam;
  struct s_scene *next;
  struct s_scene *prev;
} t_scene;

#endif
