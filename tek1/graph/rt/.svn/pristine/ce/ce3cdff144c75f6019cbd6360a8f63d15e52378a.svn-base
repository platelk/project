/*
** Moebius.c for moebus in /home/vink/moebus
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Tue May 22 09:06:03 2012 kevin platel
** Last update Sun May 27 18:43:13 2012 kevin platel
*/

#include <stdlib.h>
#include <math.h>
#include "vec3_utilities.h"
#include "interval.h"
#include "GarbageMath.h"

t_vec3 moebius_pt(t_couple tv, t_moebius in)
{
  t_vec3 out;

  out.x = in.size.x * (2 + tv.a*cos(tv.b))*cos(2*tv.b)/2.0f + in.center.x;
  out.y = in.size.y * (2 + tv.a*cos(tv.b))*sin(2*tv.b)/2.0f + in.center.y;
  out.z = in.size.z * tv.a*sin(tv.b)/2.0f + in.center.z;
  return out;
}

int moebius_cast_pretest(t_line delta, t_moebius band)
{
  double max;

  max = max3(band.size.x,band.size.y,band.size.z);
  if((!delta.direction.x && !delta.direction.y && !delta.direction.z)
     || (!band.size.x && !band.size.y && !band.size.z == 0.0f))
    return 0;
  else
    {
      if (dist_line_pt(delta,band.center) < max)
	return (0);
      else
	return (dist_line_pt(delta,band.center));
    }
  return (0);
}


t_couple moebius_cast_line_best_tv(t_moebiuspart *part, t_line *delta, double step)
{
  t_couple test;
  double min;
  t_couple out;

  test = make_couple(part.t_range.min,part.v_range.min);
  min = 0.0f;
  out = make_couple(0.0f,0.0f);
  while(test.a < part.t_range.max && step != 0)
    {
      test.b = part.v_range.min;
      if(test.a != part.exclusion.a)
	while(test.b < part.v_range.max)
	  {
	    if(test.b != part.exclusion.b)
	      if(dist_line_pt(delta, moebius_pt(test,part.band)) < min)
		{
		  min = dist_line_pt(delta, moebius_pt(test,part.band));
		  out = make_couple(test.a,test.b);
		}
	    test.b += step;
	  }
      test.a += step;
    }
  return out;
}

t_couple_tv moebius_cast(t_line delta, t_moebiuspart field)
{
  double step;
  double step_ini;
  t_couple exclusion_ini;
  t_couple_tv out;

  exclusion_ini = make_couple(field.exclusion.a, field.exclusion.b);
  step_ini = 0.1f;
  step = step_ini;
  while(dist_line_pt(delta, moebius_pt(out.a, field.band)) < 2*step*step)
    {
      out.a = moebius_cast_line_best_tv(field, delta, step);
      field.t_range = zoom(field.t_range, out.a.a, 0.1f);
      field.v_range = zoom(field.v_range, out.a.b, 0.1f);
      step *= 0.1f;
      field.exclusion = make_couple(out.a.a,out.a.b);
      if(exclusion_ini.a == 42 && exclusion_ini.b == 42 && step_ini == step)
	out.b = moebius_cast(delta, field).a;
      else
	out.b = make_couple(out.a.a,out.a.a);
      if(step < 0.0001f)
	return out;
    }
  return out;
}

t_couple moebius_cast_get_k(t_line delta, t_moebius band)
{
  t_moebiuspart field;
  t_couple_tv cast_points_tv;
  t_couple out;
  t_vec3 cast_pt_A;
  t_vec3 cast_pt_B;

  if(!moebius_cast_pretest(delta, band))
    return make_couple(-1.0f,-1.0f);
  field.band = band;
  field.exclusion = make_couple(42,42);
  field.t_range = make_interval(-1,1);
  field.v_range = make_interval(0,3.141f);
  cast_points_tv = moebius_cast(delta, field);
  cast_pt_A = moebius_pt(cast_points_tv.a, band);
  cast_pt_B = moebius_pt(cast_points_tv.b, band);
  out.a = find_k_factor(delta,cast_pt_A);
  out.b = find_k_factor(delta,cast_pt_B);
  return out;
}
