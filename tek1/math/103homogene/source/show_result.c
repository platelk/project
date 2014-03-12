/*
** show_result.c for 103homogene
** 
** Made by matthieu przybylski
** Login   <przyby_m@epitech.net>
** 
** Started on  Thu Dec 15 14:50:59 2011 matthieu przybylski
** Last update Fri Dec 16 10:21:00 2011 matthieu przybylski
*/

#include <stdio.h>
#include "103homogene.h"

void	show_result(float *result)
{
  int	i;

  printf("Matrice résultat :\n");
  i = 0;
  while (i != (COLUMN * LINE))
    {
      if (i == 0)
	printf("\t%.3f  ", result[i]);
      else if (i == 8)
	printf("%.3f\n", result[i]);
      else if (((i + 1) % 3) == 0)
	printf("%.3f\n\t", result[i]);
      else
	printf("%.3f  ", result[i]);
      i++;
    }
}
