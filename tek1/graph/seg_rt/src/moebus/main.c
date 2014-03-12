/*
** main.c for Moebus in /home/vink/moebus
**
** Made by kevin platel
** Login   <vink@epitech.net>
**
** Started on  Tue May 22 09:42:31 2012 kevin platel
** Last update Sun May 27 16:40:44 2012 kevin platel
*/

#include	<stdlib.h>
#include	"GarbageMath.h"
#include	"moebus.h"

int	main(int ac, char **av)
{
  t_couple	out;
  t_moebius	moebius;
  t_line	delta;
  float	a;
  float	b;
  float	c;
  float	step;
  long	i;

  moebius.center.x = 0.0f;
  moebius.center.y = 0.0f;
  moebius.center.z = 0.0f;

  moebius.size.x = 500.0f;
  moebius.size.y = 500.0f;
  moebius.size.z = 500.0f;
  step = 0.3f;

  delta.point.x = 0.0f;
  delta.point.y = 0.0f;
  delta.point.z = 0.0f;

  delta.direction.x = -1.0f;

  a = b = c = 0.0;
  i = 0;
  while (a <= 1.0f)
    {
      b = -1.0f;
      while (b <= 1.0f)
	{
	  c = -1.0f;
	  while (c <= 1.0f)
	    {
	      out.a = -1.0;
	      out.b = -1.0;
	      delta.direction.x = a;
	      delta.direction.y = b;
	      delta.direction.z = c;
	      if (moebius_cast_get_k(&delta, &moebius, &out) == NULL)
		printf ("Pas de solution !\n");
	      printf("\na = %f, b = %f\n", out.a, out.b);
	      printf("i = %d, x = %f, y = %f, z = %f\n\n", i, a, b, c);
	      i++;
	      c += step;
	    }
	  b += step;
	}
      a += step;
    }
  return (0);
}
