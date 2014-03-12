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

  moebius.center.x = -100.0f;
  moebius.center.y = 0.0f;
  moebius.center.z = 0.0f;

  moebius.size.x = 50.0f;
  moebius.size.y = 50.0f;
  moebius.size.z = 50.0f;
  step = 1.0f;

  delta.point.x = 0.0f;
  delta.point.y = 0.0f;
  delta.point.z = 0.0f;

  a = b = c = -250.0f;
  i = 0;

 // while (a <= 1.0f)
    {
      b = -1.0f;
      while (b <= 250.0f)
	{
	  c = -1.0f;
	  while (c <= 250.0f)
	    {
	      out.a = -1.0;
	      out.b = -1.0;
	      delta.direction.x = a;
	      delta.direction.y = b;
	      delta.direction.z = c;

           // printf("========= Nouveau test =============\n");
	      if (moebius_cast_get_k(&delta, &moebius, &out) != NULL)
	      {
            printf("k1 = %f, k2 = %f\n", out.a, out.b);
	      }
	      //  printf("x = %f, y = %f, z = %f\n", a, b, c);

	      i++;
	      c += step;
	    }
	  b += step;
	}
      a += step;
    }
  return (0);
}
