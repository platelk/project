/*
** main.c for 103homogene
**
** Made by matthieu przybylski
** Login   <przyby_m@epitech.net>
**
** Started on  Thu Dec 15 14:36:38 2011 matthieu przybylski
** Last update Fri Dec 16 10:14:50 2011 matthieu przybylski
*/

#include <stdio.h>
#include <stdlib.h>
#include "103homogene.h"

int	main(int argc, char **argv)
{
  float	*result;
  float *temp;
  int	**pars;

  if (argc > 1)
    {
      if ((pars = parsing(argc, argv)) == NULL)
	return (1);
      result = create_matrix(pars);
      while ((temp = create_matrix(pars)) != NULL)
	result = mult_matrix(temp, result);
      show_result(result);
    }
  else
    printf("Usage: <transformation> <coefficients>\n");
  return (0);
}
