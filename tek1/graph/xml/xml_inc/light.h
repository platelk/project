/*
** light.h for raytracer in /home/leprov_a//depot/rt/inc
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Mon May  7 12:20:58 2012 alexis leprovost
** Last update Mon May  7 12:37:01 2012 alexis leprovost
*/

#ifndef __LIGHT_H__
#define __LIGHT_H__

#include	"raytracer.h"

typedef	enum e_type
{
  AMBIENT,
  DIFFUSE,
  SPECULAR
} t_type;

typedef struct s_light
{
  t_type	type;
  double	location[NB_DIMENSION];
  double	intensity;
  struct s_light	*next;
} t_light;

#endif
