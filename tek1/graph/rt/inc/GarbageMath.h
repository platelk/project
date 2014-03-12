/*
** GarbageMath.h for obj in /home/vink/projet/graph/rt/src/moebus
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Sun Jun  3 16:30:24 2012 kevin platel
** Last update Sun Jun  3 16:30:25 2012 kevin platel
*/


#ifndef	__GARBAGE_MATH_H__
#define __GARBAGE_MATH_H__

#include	"global.h"
#include	"vec3_utilities.h"

typedef struct interval
{
  double	min;
  double	max;
} t_interval;

typedef struct s_line
{
  t_vec3	point;
  t_vec3	direction;
} t_line;

typedef struct s_couple
{
  double	a;
  double	b;
  double	normal[NB_DIMENSION];
} t_couple;

typedef struct s_couple_tv
{
  t_couple	a;
  t_couple	b;
} t_couple_tv;

typedef struct s_moebius
{
  t_vec3	center;
  t_vec3	size;
} t_moebius;

typedef struct s_moebiuspart
{
  t_moebius	band;
  t_couple	exclusion;
  t_interval	v_range;
  t_interval	t_range;
} t_moebiuspart;

t_couple	*make_couple(double, double, t_couple *);
double		max3(double, double, double);
double		dist_line_pt(t_line *, t_vec3 *);
double		find_k_factor(t_line *, t_vec3 *);
t_moebiuspart	*make_moebiuspart(t_moebius *, t_interval *,
				  t_interval *, t_moebiuspart *);

#endif
