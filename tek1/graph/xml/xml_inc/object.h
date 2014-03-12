/*
** object.h for raytracer in /home/leprov_a//depot/rt/inc
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Fri May  4 13:29:04 2012 alexis leprovost
** Last update Tue May  8 13:43:52 2012 kevin platel
*/

#ifndef __OBJECT_H__
#define __OBJECT_H__

#include	"raytracer.h"
#include	"image.h"
#include	"color.h"

#define	STRING_OBJ	"window/scene/object"

#define	STRING_X	"X"
#define	STRING_Y	"Y"
#define	STRING_Z	"Z"

#define	STRING_LOC	"location"
#define	STRING_ROT	"rotation"
#define STRING_COL	"color"

#define	NB_EFFECT	3
#define	NB_TYPE		3

typedef enum e_effect
{
  REFLECTION,
  BRIGHTNESS,
  TRANSPARENCY
} t_effect;

typedef enum e_dim
{
  X,
  Y,
  Z
} t_dim;

typedef enum e_type
{
  SPHERE,
  PLAN,
  CYL
} t_type;

typedef struct s_object
{
  double	position[NB_DIMENSION];
  double	rotation[NB_DIMENSION];
  double	perturbation[NB_DIMENSION];
  double	effect[NB_EFFECT];
  t_color	*color;
  t_image	*image;
  t_type	type;
  t_limit       *limit;

  void	*sun;
  struct s_object	*inhibitor;
  struct s_object *next;
  struct s_object *prev;
} t_object;

#endif
