/*
** image.h for raytracer in /home/leprov_a//depot/rt/inc
**
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
**
** Started on  Tue May  1 15:51:52 2012 alexis leprovost
** Last update Wed May 30 15:58:02 2012 ronan guiho
*/

#ifndef __IMAGE_H__
#define __IMAGE_H__

#include	"global.h"

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
};

#endif
