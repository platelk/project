/*
** moebus.h for moebus in /home/vink/projet/graph/rt/src/moebus
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Sun Jun  3 16:30:03 2012 kevin platel
** Last update Sun Jun  3 16:30:04 2012 kevin platel
*/

#ifndef __MOEBIUS_H__
#define __MOEBIUS_H__

#include	"GarbageMath.h"

#define	MO_PRES	3.0
#define MO_STEP	0.1
#define MO_IT	0.01
#define MO_K	1.0

#define NOZEROMIN	0.000001
#define EQUALZERO(x)	((((x) >  -NOZEROMIN) && ((x) < NOZEROMIN)) ? 1 : 0)

t_couple	*check_sol(t_couple *, t_line *, t_couple_tv *, t_moebius *);
t_couple	*moebius_cast_get_k(t_line *, t_moebius *, t_couple *);
t_vec3		*moebius_pt(t_couple *, t_moebius *, t_vec3 *);
char		moebius_cast_pretest(t_line *, t_moebius *);
t_couple	*moebius_cast_line_best_tv(t_moebiuspart *, t_line *,
				    double, t_couple *);
t_couple_tv	*moebius_cast(t_line *, t_moebiuspart *, t_couple_tv *);

#endif
