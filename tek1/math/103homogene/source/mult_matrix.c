/*
** mult_matrix.c for 103homogene
** 
** Made by matthieu przybylski
** Login   <przyby_m@epitech.net>
** 
** Started on  Thu Dec 15 13:53:59 2011 matthieu przybylski
** Last update Fri Dec 16 10:12:42 2011 matthieu przybylski
*/

#include "103homogene.h"

float	*mult_matrix(float *m1, float *m2)
{
  int	i, j, k, l;
  float	*result;

  result = init_result();
  k = 0;
  l = 0;
  i = 0;
  while (k != (COLUMN * LINE))
    {
      i = (k / LINE) * COLUMN;
      if ((k % LINE) == 0)
	l = 0;
      j = l;
      while (j < (COLUMN * LINE))
	{
	  result[k] = (m1[i] * m2[j]) + result[k];
	  i += 1;
	  j += 3;
	}
      k++;
      l++;
    }
  return (result);
}
