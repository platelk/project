/*
** GarbageMath.h for moebus in /home/vink/moebus
**
** Made by kevin platel
** Login   <vink@epitech.net>
**
** Started on  Tue May 22 09:18:34 2012 kevin platel
** Last update Tue May 22 09:51:17 2012 kevin platel
*/

#ifndef	__GARBAGE_MATH_H__
#define __GARBAGE_MATH_H__

#include "interval.h"
#include "vec3_utilities.h"

typedef struct s_line
{
  t_vec3 point;
  t_vec3 direction;
} t_line;

typedef struct s_couple
{
  double a;
  double b;
} t_couple;

typedef struct s_couple_tv
{
  t_couple a;
  t_couple b;
} t_couple_tv;

typedef struct s_moebius
{
  t_vec3 center;
  t_vec3 size;
} t_moebius;

typedef struct s_moebiuspart
{
  t_moebius band;
  t_couple exclusion;
  t_interval v_range;
  t_interval t_range;
} t_moebiuspart;

t_couple make_couple(double a, double b);
double max3(double a, double b, double c);
double dist_line_pt(t_line delta, t_vec3 b);
double find_k_factor(t_line delta, t_vec3 b);
t_moebiuspart make_moebiuspart(t_moebius band, t_interval t_range, t_interval v_range);

#endif