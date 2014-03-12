/*
** main.c for Moebus in /home/vink/moebus
**
** Made by kevin platel
** Login   <vink@epitech.net>
**
** Started on  Tue May 22 09:42:31 2012 kevin platel
** Last update Sun May 27 14:24:14 2012 kevin platel
*/

#include	<stdlib.h>
#include	"GarbageMath.h"
#include	"moebus.h"

int	main()
{
  t_couple	out;
  t_moebius	moebius;
  t_line	delta;

  moebius.center.x = 100000.0;
  moebius.center.y = 0.0;
  moebius.center.z = 0.0;

  moebius.size.x = 100.0;
  moebius.size.y = 100.0;
  moebius.size.z = 100.0;

  delta.point.x = 0.0;
  delta.point.y = 0.0;
  delta.point.z = 0.0;
  delta.direction.x = 0.0;
  delta.direction.y = 1.0;
  delta.direction.z = 0.0;

  if (moebius_cast_get_k(delta, moebius, &out) == NULL)
    return NULL;
  printf("a = %f, b = %f\n", out.a, out.b);
  return (0);
}
