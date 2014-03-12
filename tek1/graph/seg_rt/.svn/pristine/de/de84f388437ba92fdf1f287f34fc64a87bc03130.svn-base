/*
** garbage_math.c for moebus in /home/vink/moebus
**
** Made by kevin platel
** Login   <vink@epitech.net>
**
** Started on  Tue May 22 09:19:35 2012 kevin platel
** Last update Tue May 22 09:43:22 2012 kevin platel
*/

#include	"vec3_utilities.h"
#include	"GarbageMath.h"

t_couple make_couple(double a, double b)
{
  t_couple out;

  out.a = a;
  out.b = b;
  return out;
}

double max3(double a, double b, double c)
{
  if(a > b && a > c)
    return a;
  if(b > a && b > c)
    return b;
  if(c > a && c > b)
    return c;
  return a;
}

double dist_line_pt(t_line delta, t_vec3 b)
{
  t_vec3 norm;

  norm = normalise_vec3(delta.direction);
  return lenth_vec3(vectorial_product3(substract_vec3(b,delta.point),norm));
}

double find_k_factor(t_line delta, t_vec3 b)
{
  t_vec3 ab;

  ab = substract_vec3(b, delta.point);
  return ab.x / delta.direction.x;
}

t_moebiuspart make_moebiuspart(t_moebius band, t_interval t_range, t_interval v_range)
{
  t_moebiuspart out;

  out.band = band;
  out.exclusion.a = 42;
  out.exclusion.b = 42;
  out.t_range = t_range;
  out.v_range = v_range;
  return out;
}
