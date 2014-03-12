/*
** parsing.c for parsing in /home/platel_k/projet/103homogene
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Thu Dec 15 13:45:53 2011 kevin platel
** Last update Thu Dec 15 14:43:58 2011 kevin platel
*/

#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int	**parsing(int ac, char **av)
{
  int	**pars;
  int	i;
  int	count;

  i = 0;
  count = 0;
  while (++i < ac)
    {
      av[i][0] == 'T' ? count++ :
	av[i][0] == 'R' ? count++ :
	av[i][0] == 'H' ? count++ :
	av[i][0] == 'S' ? count++ : 42;
      if ((isalpha(av[i][0]) > 0) && av[i][0] != 'T' && av[i][0] != 'H' && av[i][0] != 'R' && av[i][0] != 'S')
	{
	  printf("%c : Option incorrect !\n", av[i][0]);
	  exit(1);
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
	      exit(1);
	    }
	  (av[i][0] == 'T' || av[i][0] == 'H') ? (i += 2) : (av[i][0] == 'R' || av[i][0] == 'S') ? (i++) : 42;
	  if ((i + 1 < ac) && av[i + 1][0] != 'T' && av[i + 1][0] != 'H' && av[i + 1][0] != 'R' && av[i + 1][0] != 'S')
	    {
	      printf("Erreur : trop d'argument\n");
	      exit(1);
	    }
	  count++;
	}
    }
  return (pars);
}
