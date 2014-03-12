/*
** raytracer.h for raytracer in /home/leprov_a//depot/rt/inc
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Tue May  1 15:53:00 2012 alexis leprovost
** Last update Sun Jun  3 17:42:54 2012 alexis leprovost
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
typedef struct s_procedural t_procedural;
typedef struct s_stereoscopique t_stereoscopique;
typedef int	(*t_inter)(t_camera *, t_object *, t_detail *, double *);
typedef int	(*t_main_option)(t_global *, t_xtree *);
typedef int	(*t_normal)(double *, t_detail *, double *, double *);

#include	"window.h"
#include	"scene.h"
#include	"light.h"
#include	"parse.h"
#include	"thread.h"
#include	"stereoscopique.h"

typedef enum e_param
{
  POSITION,
  ROTATION,
  RED,
  GREEN,
  BLUE,
  TP,
  RP,
  PP,
  BP,
  AA
} t_param;

struct s_global
{
  t_stereoscopique	*stereoscopique;
  int		count_pixel;
  int		count_trame;
  t_thread	thread[MAX_THREAD];
  t_window	*window;
  t_scene	*scene;
  t_object	*object;
  int		param;
  t_info	info;
};

int             main_option_normal(t_global *, t_xtree *);

#endif
