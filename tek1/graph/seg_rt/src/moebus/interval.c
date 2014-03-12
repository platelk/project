/*
** interval.c for moebus in /home/vink/moebus
**
** Made by kevin platel
** Login   <vink@epitech.net>
**
** Started on  Tue May 22 09:27:04 2012 kevin platel
** Last update Fri May 25 02:47:29 2012 kevin platel
*/

#include "interval.h"

t_interval *make_interval(double min, double max, t_interval *out)
{
  out->min = min;
  out->max = max;
  return (out);
}

t_interval *zoom(t_interval *in, double center, double lenthfactor)
{
  double moy;

  moy  = (in->min + in->max)/2.0f;
  in->max = (in->max * lenthfactor) + center - moy;
  in->min = (in->min * lenthfactor) + center - moy;
  return (in);
}
