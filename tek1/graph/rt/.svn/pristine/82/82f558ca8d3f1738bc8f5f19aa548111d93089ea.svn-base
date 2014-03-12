/*
** perlin_noise.h for perlin_noise in /home/ozouf_h//perlin_noise
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Thu May 10 15:11:06 2012 harold ozouf
** Last update Wed May 30 16:05:09 2012 ronan guiho
*/

#ifndef		__PERLIN_NOISE_H__
#define		__PERLIN_NOISE_H__

#include	"global.h"
#include	"color.h"

#define	SIZE_X	1000
#define	SIZE_Y	1000

typedef enum
{
  MARBLE,
  WOOD,
  NONE
} t_perlin_type;

typedef enum
{
  APP_BUMP,
  APP_TEXT,
  APP_BUMP_TEXT
} t_perlin_apply;

struct	s_perlin
{
  int		nbr_octave;
  float		persistance;
  double	perlin[SIZE_Y][SIZE_X];
  int		effect;
  int		ceil;
  int		apply;
  double	freq;
  double	relief;
  t_color	*begin;
  t_color	*end;
};

struct s_pos
{
  int	x;
  int	y;
  int	z;
};

typedef double	tab_2d[SIZE_Y][SIZE_X];

typedef double    (*t_perlin_foo)(double);

void	make_moy(double, t_perlin *);
double	interpol(double, double, double);
double	marble(double);
void	create_perlin_noise(t_perlin *);
void	init_effects_perlin(t_perlin_foo *);
double	wood(double);

#endif
