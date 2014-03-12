/*
** interval.h for moebus in /home/vink/moebus
**
** Made by kevin platel
** Login   <vink@epitech.net>
**
** Started on  Tue May 22 09:26:24 2012 kevin platel
** Last update Sun May 27 08:43:35 2012 kevin platel
*/

#ifndef __INTERVAL_H__
#define __INTERVAL_H__

typedef struct interval
{
  double min;
  double max;
} t_interval;

t_interval *make_interval(double, double, t_interval *);
t_interval *zoom(t_interval *, double, double);


#endif
