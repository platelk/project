/*
** moebus.h for moebus in /home/vink/moebus
**
** Made by kevin platel
** Login   <vink@epitech.net>
**
** Started on  Tue May 22 09:51:45 2012 kevin platel
** Last update Thu May 31 14:27:49 2012 kevin platel
*/

#ifndef __MOEBIUS_H__
#define __MOEBIUS_H__

#include	"GarbageMath.h"

#define	MO_PRES	3
#define MO_K	1

t_couple *moebius_cast_get_k(t_line *delta, t_moebius *band, t_couple *, double *);

#endif
