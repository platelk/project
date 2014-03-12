/*
** moebius_part_two.c for moebus in /home/vink/projet/graph/rt/src/moebus
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Sun Jun  3 16:26:46 2012 kevin platel
** Last update Sun Jun  3 16:26:46 2012 kevin platel
*/

#include	<stdlib.h>

#include	"vec3_utilities.h"
#include	"GarbageMath.h"
#include	"interval.h"
#include	"moebus.h"

t_couple_tv	*calc_seconde_sol(t_line *delta, t_moebiuspart *field,
				  t_couple_tv *out)
{
  t_vec3	aout;
  t_couple exclusion_ini;
  t_couple_tv	rec;

  make_couple(field->exclusion.a, field->exclusion.b, &exclusion_ini);
  if (exclusion_ini.a == 42.0 && exclusion_ini.b == 42.0
      && ((dist_line_pt(delta, moebius_pt(&(out->a), &(field->band), &aout))
	   > MO_PRES))
      && !vec_is_in_plan(&(out->a), delta, &(field->band)))
    {
      make_couple(out->a.a, out->a.b, &(field->exclusion));
      make_interval(-1.0, 1.0, &(field->t_range));
      make_interval(0, 3.1415f, &(field->v_range));
      if (!moebius_cast(delta, field, &rec))
	out->b = rec.a;
      else
	make_couple(out->a.a, out->a.a, &(out->b));
    }
  else
    make_couple(out->a.a, out->a.a, &(out->b));
  return (out);
}

void	moebius_get_normal(t_couple *out, t_couple *tv, t_moebius *band)
{
  t_vec3	normal;

  calc_normal_vec_plan(tv, band, &normal);
  out->normal[0] = normal.x;
  out->normal[1] = normal.y;
  out->normal[2] = normal.z;
}

double	calc_sol(t_vec3 *cast_pt_A, t_line *delta,
		 t_couple *tv,
		 t_moebius *band)
{
  double	a;
  double	b;
  double	c;
  double	sol;
  t_vec3	normal;

  calc_normal_vec_plan(tv, band, &normal);
  a = ((normal.x * delta->point.x) + (normal.y * delta->point.y)
       + (normal.z * delta->point.z));
  b = -((normal.x * cast_pt_A->x) + (normal.y * cast_pt_A->y)
	+ (normal.z * cast_pt_A->z));
  normalise_vec3(&(delta->direction));
  c = (normal.x * delta->direction.x) + (normal.y * delta->direction.y)
    + (normal.z * delta->direction.z);
  sol = (-(a + b)) / c;
  sol = sol * 20;
  return (sol);
}

t_couple	*check_sol(t_couple *out, t_line *delta,
			   t_couple_tv *cast_points_tv,
			   t_moebius *band)
{
  t_vec3 cast_pt_A;
  t_vec3 cast_pt_B;

  moebius_pt(&(cast_points_tv->a), band, &cast_pt_A);
  moebius_pt(&(cast_points_tv->b), band, &cast_pt_B);
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
      out->a = calc_sol(&cast_pt_A, delta, &(cast_points_tv->a), band);
      moebius_get_normal(out, &(cast_points_tv->a), band);
    }
  else
    {
      out->a = calc_sol(&cast_pt_B, delta, &(cast_points_tv->b), band);
      moebius_get_normal(out, &(cast_points_tv->b), band);
    }
  return (out->a < 0 ? NULL : out);
}
