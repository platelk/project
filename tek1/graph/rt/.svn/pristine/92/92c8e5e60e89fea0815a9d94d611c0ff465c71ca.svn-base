/*
** Moebius.c for moebus in /home/vink/projet/graph/rt/src/moebus
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Sun Jun  3 16:26:33 2012 kevin platel
** Last update Sun Jun  3 16:26:34 2012 kevin platel
*/

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
  out->x = in->size.x * ((2 + (tv->a * cos(MO_K * tv->b))) *	\
			 cos(2 * tv->b) / 2.0f) + in->center.x;
  out->y = in->size.y * ((2 + (tv->a * cos(MO_K * tv->b))) *	\
			 sin(2 * tv->b) / 2.0f) + in->center.y;
  out->z = in->size.z * (tv->a * sin(MO_K * tv->b) / 2.0f) + in->center.z;
  return (out);
}

char moebius_cast_pretest(t_line *delta, t_moebius *band)
{
  double max;

  max = max3(band->size.x, band->size.y, band->size.z) * 1.6;
  if ((EQUALZERO(delta->direction.x) && EQUALZERO(delta->direction.y) &&
       EQUALZERO(delta->direction.z))
      || (EQUALZERO(band->size.x) &&
	  EQUALZERO(band->size.y) && EQUALZERO(band->size.z)))
    return (0);
  else
    if (dist_line_pt(delta, &(band->center)) < max)
      return (1);
    else
      return (0);
  return (0);
}

t_couple *moebius_cast_line_best_tv(t_moebiuspart *part, t_line *delta,
				    double step,
				    t_couple *out)
{
  t_couple test;
  double min;
  t_vec3	aout;

  min = -1.0f;
  make_couple(-1.0f, -1.0f, out);
  test.a = part->t_range.min;
  if (EQUALZERO(step))
    return (NULL);
  while (test.a < part->t_range.max)
    {
      test.b = part->v_range.min;
      while (test.b < part->v_range.max)
	{
	  if (dist_line_pt(delta, moebius_pt(&test, &(part->band), &aout))
	      < min || min == -1.0f)
	    {
	      min = dist_line_pt(delta, moebius_pt(&test, &(part->band), &aout));
	      make_couple(test.a, test.b, out);
	    }
	  test.b += step;
	}
      test.a += step;
    }
  return (out);
}

t_couple_tv *moebius_cast(t_line *delta, t_moebiuspart *field,
			  t_couple_tv *out)
{
  double step;
  double step_ini;
  t_couple exclusion_ini;
  t_vec3	aout;

  make_couple(field->exclusion.a, field->exclusion.b, &exclusion_ini);
  step_ini = MO_STEP;
  step = step_ini;
  make_couple(-1.0, -1.0, &(out->a));
  make_couple(-1.0, -1.0, &(out->b));
  while ((dist_line_pt(delta, moebius_pt(&(out->a), &(field->band), &aout))
	  > (MO_PRES))
	 && !vec_is_in_plan(&(out->a), delta, &(field->band)))
    {
      moebius_cast_line_best_tv(field, delta, step, &(out->a));
      zoom(&(field->t_range), out->a.a, 0.08f);
      zoom(&(field->v_range), out->a.b, 0.08f);
      if (step < MO_IT)
	return (NULL);
      step *= 0.1f;
    }
  make_couple(out->a.a, out->a.a, &(out->b));
  return (out);
}

t_couple  *moebius_cast_get_k(t_line *delta, t_moebius *band, t_couple *out)
{
  t_moebiuspart field;
  t_couple_tv cast_points_tv;
  t_couple	aout;

  normalise_vec3(&(delta->direction));
  if (!moebius_cast_pretest(delta, band))
    return (NULL);
  field.band = *band;
  field.exclusion = *(make_couple(42, 42, &aout));
  make_interval(-1.0, 1.0, &(field.t_range));
  make_interval(0.0, 3.1415f, &(field.v_range));
  make_couple(-1.0, -1.0, out);
  if (moebius_cast(delta, &field, &cast_points_tv) == NULL)
    return (NULL);
  if (check_sol(out, delta, &cast_points_tv, band) == NULL)
    return (NULL);
  return (out);
}
