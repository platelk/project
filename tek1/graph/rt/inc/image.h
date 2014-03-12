/*
** image.h for raytracer in /home/leprov_a//depot/rt/inc
**
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
**
** Started on  Tue May  1 15:51:52 2012 alexis leprovost
** Last update Thu May 31 23:50:17 2012 alexis leprovost
*/

#ifndef __IMAGE_H__
#define __IMAGE_H__

#include	"global.h"
#include	"color.h"

typedef enum
{
  WIDTH,
  HEIGHT
} e_size;

typedef	enum e_bump_type
{
  B_NORMAL = 0,
  B_DISPLACEMENT,
  B_BUMP,
  B_NONE
} t_bump_type;

typedef struct s_cut_texture
{
  t_color	*tcolor;
  int		interval;
  int		flag;
} t_cut_texture;

struct s_image
{
  void	*ptr;
  char	*data;
  int	size[2];
  int	sizeline;
  int	bpp;
  int	endian;
  t_bump_type	type;
  double	freq;
  double	relief;
  int		type_texture;
  t_cut_texture *cut_texture;
};

#endif
