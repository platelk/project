/*
** vec3_utilities.h for moebus in /home/vink/projet/graph/rt/src/moebus
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Sun Jun  3 16:31:10 2012 kevin platel
** Last update Sun Jun  3 16:31:14 2012 kevin platel
*/

#ifndef	__VEC3_UTILITIES_H__
#define __VEC3_UTILITIES_H__

typedef struct s_vec3
{
  double	x;
  double	y;
  double	z;
} t_vec3;

t_vec3 *make_vec3(double, double, double, t_vec3 *);
t_vec3 *normalise_vec3(t_vec3 *);
double lenth_vec3(t_vec3 *);
t_vec3 *substract_vec3(t_vec3 *, t_vec3 *, t_vec3 *);
t_vec3 *vectorial_product3(t_vec3 *, t_vec3 *, t_vec3 *);

#endif
