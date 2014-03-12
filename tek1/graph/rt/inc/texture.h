/*
** texture.h for texture in /home/guiho_r/tek1/rt/src/texture
**
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
**
** Started on  Thu May 10 14:14:55 2012 ronan guiho
** Last update Thu May 31 19:36:33 2012 alexis leprovost
*/

#ifndef __TEXTURE_H__
#define __TEXTURE_H__

#include "image.h"
#include "color.h"

#define FREQUENCE	1.0
#define FREQUENCE_PLAN	5.0
#define FREQUENCE_CYLI	1.0

typedef	int	(*t_mapping)(t_object *, t_color *, double *, t_image *);

typedef enum
{
  U,
  V,
  T
} t_utils;

typedef enum
{
  TEXTURE = 0,
  BUMP,
  PERLIN
} t_flag_mapping;

int	texture_getcolor(t_image *, t_color *, int *);
int	texture_mapping(t_object *, t_color *, double *, int *);
int	texture_bump_mapping(t_detail *, double *);
int	perlin_texture(t_object *, t_perlin *, t_color *, double *);
int	texture_normal_mapping(t_detail *, double *);
int	texture_mapping_sphere(t_object *, t_color *, double *, t_image *);
int	texture_mapping_plan(t_object *, t_color *, double *, t_image *);
int	texture_mapping_cylindre(t_object *, t_color *, double *, t_image *);
int	texture_mapping_tore(t_object *, t_color *, double *, t_image *);
int	texture_mapping_cone(t_object *, t_color *, double *, t_image *);

#endif
