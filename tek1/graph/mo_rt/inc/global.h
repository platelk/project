/*
** raytracer.h for raytracer in /home/leprov_a//depot/rt/inc
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Tue May  1 15:53:00 2012 alexis leprovost
** Last update Sat May 26 10:41:08 2012 alexis leprovost
*/

#ifndef __GLOBAL_H__
#define __GLOBAL_H__

typedef struct s_global t_global;
typedef struct s_scene t_scene;
typedef struct s_object t_object;
typedef struct s_detail t_detail;
typedef struct s_color t_color;
typedef struct s_camera t_camera;
typedef struct s_image t_image;
typedef struct s_light t_light;
typedef struct s_limit t_limit;
typedef struct s_window t_window;
typedef struct s_thread t_thread;
typedef struct s_xtree	t_xtree;
typedef struct s_pos	t_pos;
typedef struct s_perlin	t_perlin;
typedef int	(*t_inter)(t_camera *, t_object *, t_detail *, double *);
typedef int	(*t_main_option)(t_global *, t_xtree *);
typedef int	(*t_normal)(double *, t_detail *, double *, double *);

#include	"window.h"
#include	"scene.h"
#include	"light.h"
#include	"parse.h"
#include	"thread.h"

struct s_global
{
  t_thread	thread[MAX_THREAD];
  t_window	*window;
  t_scene	*scene;
  t_info	info;
};

#endif
