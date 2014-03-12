/*
** parsing.c for 103homogene
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Thu Dec 15 13:45:53 2011 kevin platel
** Last update Thu Dec 15 16:08:03 2011 matthieu przybylski
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "103homogene.h"

int	**parsing(int ac, char **av)
{
  int	**pars;
  int	i;
  int	count;

  i = 0;
  count = 0;
  while (++i < ac)
    {
      strcmp(av[i], "T") == 0 ? count++ :
	strcmp(av[i], "R") == 0 ? count++ :
	strcmp(av[i], "H") == 0 ? count++ :
	strcmp(av[i], "S") == 0 ? count++ : 42;
      if (isalpha(av[i][0]) > 0 && strcmp(av[i], "T") \
	  != 0 && strcmp(av[i], "R") != 0 && strcmp(av[i], "H") != 0 \
	  && strcmp(av[i], "S") != 0)
	{
	  printf("%s : Option incorrect !\n", av[i]);
	  return (NULL);
	}
    }
  pars = malloc((count + 1) * sizeof(*pars));
  pars[count] = NULL;
  i = 0;
  count = 0;
  while (++i < ac)
    {
      if (av[i][0] == 'T' || av[i][0] == 'H' || av[i][0] == 'R' || av[i][0] == 'S')
	{
	  pars[count] = malloc(3 * sizeof(**pars));
	  pars[count][0] = av[i][0];
	  i + 1 < ac ? pars[count][1] = atoi(av[i + 1]) : 42;
	  if (av[i][0] == 'T' || av[i][0] == 'H')
	    i + 2 < ac ? pars[count][2] = atoi(av[i + 2]) : 42;
	  if (((av[i][0] == 'T' || av[i][0] == 'H') && i + 2 >= ac) || ((av[i][0] == 'S' || av[i][0] == 'R') && i + 1 >= ac))
	    {
	      printf("Erreur : pas assez d'argument\n");
	      return (NULL);
	    }
	  (av[i][0] == 'T' || av[i][0] == 'H') ? (i += 2) : (av[i][0] == 'R' || av[i][0] == 'S') ? (i++) : 42;
	  if ((i + 1 < ac) && av[i + 1][0] != 'T' && av[i + 1][0] != 'H' && av[i + 1][0] != 'R' && av[i + 1][0] != 'S')
	    {
	      printf("Erreur : trop d'argument\n");
	      return (NULL);
	    }
	  count++;
	}
    }
  return (pars);
}
