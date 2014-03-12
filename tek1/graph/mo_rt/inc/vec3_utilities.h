/*
** vec3_utilities.h for moebus in /home/vink/moebus
**
** Made by kevin platel
** Login   <vink@epitech.net>
**
** Started on  Tue May 22 09:17:04 2012 kevin platel
** Last update Sun May 27 10:39:51 2012 kevin platel
*/

#ifndef	__VEC3_UTILITIES_H__
#define __VEC3_UTILITIES_H__

typedef struct s_vec3
{
  double	x;
  double	y;
  double	z;
} t_vec3;

t_vec3 *make_vec3(double x, double y, double z, t_vec3 *);
t_vec3 *normalise_vec3(t_vec3 *in);
double lenth_vec3(t_vec3 *in);
t_vec3 *substract_vec3(t_vec3 *inA,t_vec3 *inB, t_vec3 *out);
t_vec3 *vectorial_product3(t_vec3 *inA, t_vec3 *inB, t_vec3 *out);

#endif
