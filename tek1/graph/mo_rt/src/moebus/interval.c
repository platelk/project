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
  t_interval initial_in;
  make_interval(in->min,in->max,&initial_in);
  double moy;
  moy  = (in->min + in->max)/2.0f;

  in->min = (in->min - moy )* lenthfactor + center;
  in->max = (in->max - moy )* lenthfactor + center;

  if ( in->min < initial_in.min )
    in->min = initial_in.min;

  if ( in->max > initial_in.max )
    in->max = initial_in.max;

  return (in);
}
