/*
** interval.c for moebus in /home/vink/projet/graph/rt/src/xml_src/src
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Sun Jun  3 16:25:58 2012 kevin platel
** Last update Sun Jun  3 16:26:00 2012 kevin platel
*/

#include "moebus.h"
#include "GarbageMath.h"
#include "vec3_utilities.h"
#include "interval.h"

t_vec3	*calc_normal_vec_plan(t_couple *point, t_moebius *tv, t_vec3 *out)
{
  t_vec3	vec1;
  t_vec3	vec2;
  t_vec3	moeb_point;
  t_couple	tv_a;
  t_vec3	point_a;
  t_vec3	point_b;

  moebius_pt(point, tv, &moeb_point);
  tv_a.a = point->a + MO_PRES;
  moebius_pt(&tv_a, tv, &point_a);
  tv_a.b = point->b + MO_PRES;
  tv_a.a = point->a;
  moebius_pt(&tv_a, tv, &point_b);
  vec1.x = point_a.x - moeb_point.x;
  vec1.y = point_a.y - moeb_point.y;
  vec1.z = point_a.z - moeb_point.z;
  out = normalise_vec3(&vec1);
  vec2.x = point_b.x - moeb_point.x;
  vec2.y = point_b.y - moeb_point.y;
  vec2.z = point_b.z - moeb_point.z;
  out = normalise_vec3(&vec2);
  out = vectorial_product3(&vec1, &vec2, out);
  return (out);
}

char	vec_is_in_plan(t_couple *point, t_line *delta, t_moebius *tv)
{
  t_vec3	vec_norm;
  t_vec3	moeb_point;
  t_vec3 norm;
  t_vec3 aout;
  t_vec3 out;

  make_vec3(-1.0, -1.0, -1.0, &moeb_point);
  moebius_pt(point, tv, &moeb_point);
  make_vec3(delta->direction.x, delta->direction.y, delta->direction.z, &norm);
  normalise_vec3(&norm);
  vectorial_product3(substract_vec3(&moeb_point, &(delta->point), &aout),
		     &norm, &out);
  calc_normal_vec_plan(point, tv, &vec_norm);
  if (EQUALZERO(((out.x * vec_norm.x) + (out.y * vec_norm.y)
		 + (out.z * vec_norm.z))))
    return (1);
  return (0);
}

t_interval *make_interval(double min, double max, t_interval *out)
{
  out->min = min;
  out->max = max;
  return (out);
}

t_interval *zoom(t_interval *in, double center, double lenthfactor)
{
  t_interval initial_in;
  double moy;

  make_interval(in->min, in->max, &initial_in);
  moy  = (in->min + in->max)/2.0f;

  in->min = (in->min - moy )* lenthfactor + center;
  in->max = (in->max - moy )* lenthfactor + center;

  if ( in->min < initial_in.min )
    in->min = initial_in.min;
  if ( in->max > initial_in.max )
    in->max = initial_in.max;

  return (in);
}
