/*
** init_result.c for 103homogene
** 
** Made by matthieu przybylski
** Login   <przyby_m@epitech.net>
** 
** Started on  Thu Dec 15 14:32:37 2011 matthieu przybylski
** Last update Thu Dec 15 16:59:08 2011 matthieu przybylski
*/

#include <stdlib.h>
#include "103homogene.h"

float	*init_result()
{
  float	*result;
  int	i;

  result = malloc((COLUMN * LINE) * sizeof(*result));
  i = 0;
  while (i <= 9)
    {
      result[i] = 0;
      i++;
    }
  return (result);
}
