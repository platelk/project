/*
** light.h for raytracer in /home/leprov_a//depot/rt/inc
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Mon May  7 12:20:58 2012 alexis leprovost
** Last update Tue May 29 19:49:56 2012 zoe phalippou
*/

#ifndef __LIGHT_H__
#define __LIGHT_H__

#include	"raytracer.h"
#include	"global.h"
#include	"detail.h"
#include	"color.h"

typedef	enum e_type
{
  AMBIENT,
  PARALLELE,
  DIFFUSE
} t_type;

struct s_light
{
  t_type	type;
  double	location[NB_DIMENSION];
  double	intensity;
  t_color	*color;
  t_inter	inter;
  t_light	*next;
};

int	light_management(t_detail *, t_color *, t_light *, double *);

#endif
