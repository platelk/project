/*
** Moebius.c for moebus in /home/vink/moebus
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Tue May 22 09:06:03 2012 kevin platel
** Last update Thu May 31 14:27:24 2012 kevin platel
*/

#define NOZEROMIN	0.0001f
#define EQUALZERO(x)	((((x) >  NOZEROMIN) && ((x) < NOZEROMIN)) ? 1 : 0)

#include <stdlib.h>
#include <math.h>
#include "moebus.h"
#include "vec3_utilities.h"
#include "interval.h"
#include "GarbageMath.h"
#include "global.h"
#include "object.h"


t_vec3  *moebius_pt(t_couple *tv, t_moebius *in, t_vec3 *out)
{
  out->x = in->size.x * (2 + tv->a*cos(MO_K * tv->b))*cos(2*tv->b)/2.0f + in->center.x;
  out->y = in->size.y * (2 + tv->a*cos(MO_K * tv->b))*sin(2*tv->b)/2.0f + in->center.y;
  out->z = in->size.z * tv->a*sin(MO_K * tv->b)/2.0f + in->center.z;
  return (out);
}

char moebius_cast_pretest(t_line *delta, t_moebius *band)
{
  double max;

  max = max3(band->size.x, band->size.y, band->size.z) * 1.6;
  if ((EQUALZERO(delta->direction.x) && EQUALZERO(delta->direction.y) && EQUALZERO(delta->direction.z))
      || (EQUALZERO(band->size.x) && EQUALZERO(band->size.y) && EQUALZERO(band->size.z)))
      return (0); //False
  else
    if (dist_line_pt(delta, &(band->center)) < max)
        return (1);  //True
    else
        return (0); //False
  return (0);
}


t_couple *moebius_cast_line_best_tv(t_moebiuspart *part, t_line *delta, double step, t_couple *out)
{
  t_couple test;
  double min;
  t_vec3	aout;

  min = -1.0f;
  make_couple(-1.0f,-1.0f, out);
  test.a = part->t_range.min;
  if (EQUALZERO(step))
    return (NULL);
  while (test.a < part->t_range.max)
    {
      test.b = part->v_range.min;
      if(test.a != part->exclusion.a)
	while(test.b < part->v_range.max)
	  {
	    if (test.b != part->exclusion.b )
	      if (dist_line_pt(delta, moebius_pt(&test, &(part->band), &aout)) < min || min == -1.0f)
		{
		  min = dist_line_pt(delta, moebius_pt(&test, &(part->band), &aout));
		  make_couple(test.a, test.b, out);
		}
	    test.b += step;
	  }
      test.a += step * 5;
    }
  return (out);
}

t_couple_tv *moebius_cast(t_line *delta, t_moebiuspart *field, t_couple_tv *out)
{
  double step;
  double step_ini;
  t_couple exclusion_ini;
  t_vec3	aout;
  t_couple_tv	rec;

  make_couple(field->exclusion.a, field->exclusion.b, &exclusion_ini);
  step_ini = 0.05f;
  step = step_ini;
  make_couple(-1.0f, -1.0f,&(out->a));
  make_couple(-1.0f, -1.0f,&(out->b));
  while (dist_line_pt(delta, moebius_pt(&(out->a), &(field->band), &aout)) > MO_PRES)
    {
      moebius_cast_line_best_tv(field, delta, step, &(out->a));
      zoom(&(field->t_range), out->a.a, 0.11f);
      zoom(&(field->v_range), out->a.b, 0.05f);
      /*      if (exclusion_ini.a == 42 && exclusion_ini.b == 42
	  && ((dist_line_pt(delta, moebius_pt(&(out->a), &(field->band), &aout)) > MO_PRES)))
      {
        make_couple(out->a.a, out->a.b, &(field->exclusion));
        if (!moebius_cast(delta, field, &rec))
          out->b = rec.a;
        else
          make_couple(out->a.a, out->a.a, &(out->b));
	  }*/
      if(step < 0.001f)
          return (NULL);
      step *= 0.1f;

    }
  if (exclusion_ini.a == 42 && exclusion_ini.b == 42)
    make_couple(out->a.a, out->a.a, &(out->b));
  return out;
}

t_couple  *moebius_cast_get_k(t_line *delta, t_moebius *band, t_couple *out, double *vec)
{
  t_moebiuspart field;
  t_couple_tv cast_points_tv;
  t_vec3 cast_pt_A;
  t_vec3 cast_pt_B;
  t_couple	aout;
  t_couple_tv	o;

  if (!moebius_cast_pretest(delta, band))
    return (NULL);
  field.band = *band;
  field.exclusion = *(make_couple(42, 42, &aout));
  make_interval(-1.0, 1.0, &(field.t_range));
  make_interval(0,3.1415f, &(field.v_range));
  if(moebius_cast(delta, &field, &cast_points_tv) == NULL)
      return NULL;
  moebius_pt(&(cast_points_tv.a), band, &cast_pt_A);
  moebius_pt(&(cast_points_tv.b), band, &cast_pt_B);
  out->a = find_k_factor(delta, &cast_pt_A);
  out->b = find_k_factor(delta, &cast_pt_B);
  if (out->a < 0.0f)
    out->a = out->b;
  if (out->b < 0.0f)
    out->b = out->a;
  if (out->b < 0.0f)
    return (NULL);
  if (out->a < out->b)
    {
      vec[X] = cast_pt_A.x;
      vec[Y] = cast_pt_A.y;
      vec[Z] = cast_pt_A.z;
    }
  else
    {
      vec[X] = cast_pt_B.x;
      vec[Y] = cast_pt_B.y;
      vec[Z] = cast_pt_B.z;
    }
  return out;
}
