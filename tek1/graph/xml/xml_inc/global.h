/*
** raytracer.h for raytracer in /home/leprov_a//depot/rt/inc
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Tue May  1 15:53:00 2012 alexis leprovost
** Last update Mon May  7 12:32:56 2012 alexis leprovost
*/

#ifndef __GLOBAL_H__
#define __GLOBAL_H__

#include	"window.h"
#include	"scene.h"
#include	"light.h"
#include	"parse.h"

typedef struct s_global
{
  t_window	*window;
  t_scene	*scene;
  t_info	info;
  int		antialiasing;
} t_global;

#endif
