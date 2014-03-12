/*
** object.h for raytracer in /home/leprov_a//depot/rt/inc
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Thu May 31 23:59:39 2012 alexis leprovost
** Last update Sun Jun  3 11:15:56 2012 kevin platel
*/

#ifndef __OBJECT_H__
#define __OBJECT_H__

#include	"global.h"
#include	"image.h"
#include	"color.h"
#include	"inter.h"
#include	"xml_attr.h"
#include        "perlin_noise.h"
#include	"limit.h"
#include	"procedural.h"
#include	"inter.h"

#define	STRING_OBJ	"window/scene/object"

#define STRING_CUBE	"cube"
#define	STRING_SPH	"sphere"
#define	STRING_PLA	"plan"
#define	STRING_CYL	"cylindre"
#define	STRING_CON	"cone"
#define	STRING_TOR	"tore"
#define	STRING_CUBET	"cubetroue"
#define	STRING_PARA	"paraboloide"
#define	STRING_HYPER	"hyperboloide"
#define	STRING_MOEB	"moebius"
#define	STRING_BLEND	"blender"
#define	STRING_TRIA	"triangle"

#define STRING_TYPE	"TYPE"
#define	STRING_NORM	"normal"
#define STRING_NEG	"negatif"
#define	STRING_BUMP	"bump_mapping"
#define	STRING_PERL	"perlin"

#define STRING_EFFECT	"effect"
#define	STRING_TEX	"texture"

#define	STRING_MATERIAL	"material"

#define	STRING_X	"X"
#define	STRING_Y	"Y"
#define	STRING_Z	"Z"

#define STRING_REFL	"REFLECTION"
#define STRING_BRIG	"BRIGHTNESS"
#define STRING_TRA	"TRANSPARENCY"
#define	STRING_PHONG	"PHONG"

#define	STRING_LOC	"location"
#define	STRING_ROT	"rotation"
#define STRING_PER	"perturbation"
#define STRING_COL	"color"

#define STRING_AA	"ANTIALIASING"

#define	NB_EFFECT	4
#define	NB_TYPE		12

typedef enum e_effect
{
  REFLECTION = 0,
  BRIGHTNESS,
  TRANSPARENCY,
  PHONG,
  TYPE
} t_effect;

typedef enum e_obj_type
{
  SPHERE = 0,
  PLAN,
  CYL,
  CON,
  TORE,
  CUBE_TROUE,
  PARABOLOIDE,
  HYPERBOLOIDE,
  CUBE,
  MOEBIUS,
  TRIANGLE,
  BLENDER,
} t_obj_type;

struct s_object
{
  t_object	*next;
  t_object	*prev;
  double	box_pos[NB_DIMENSION];
  double	box_size[NB_DIMENSION];
  double	position[NB_DIMENSION];
  double	rotation[NB_DIMENSION];
  double	perturbation[NB_DIMENSION];
  double	effect[NB_EFFECT];
  t_color	*color;
  t_image	*image;
  t_procedural	*procedural;
  int		texture_pos[2];
  double	material;
  t_image	*image_bump;
  t_obj_type	type;
  t_limit	*limit;
  t_inter	inter;
  t_attr	*attr;
  t_perlin	*perlin;
  void		*son;
  t_object	*inhibitor;
};

typedef	struct	s_blender
{
  char	*path;
} t_blender;

typedef	struct	s_triangle
{
  double	pt1[3];
  double	pt2[3];
  double	pt3[3];
  double	n[3];
} t_triangle;

typedef struct  s_cube
{
  double	size;
} t_cube;

typedef struct  s_tore
{
  double	radius[2];
} t_tore;

typedef struct  s_cubetroue
{
  double	radius;
  double	size;
} t_cubetroue;

typedef struct	s_paraboloide
{
  double	radius;
} t_paraboloide;

typedef	struct	s_sphere
{
  double	radius;
} t_sphere;

typedef	struct	s_cylindre
{
  double	radius;
} t_cylindre;

typedef	struct	s_cone
{
  double	angle;
} t_cone;

typedef	struct	s_plan
{
} t_plan;

typedef struct	s_hyperboloide
{
  double	a;
  double	b;
  double	c;
} t_hyperboloide;

typedef struct	s_mobius
{
  double	a;
  double	b;
  double	c;
} t_mobius;

#endif
