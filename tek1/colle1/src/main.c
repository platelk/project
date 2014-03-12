/*
** main.c for mastermind in /home/vink/projet/colle/src
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Thu Apr 19 14:10:18 2012 kevin platel
** Last update Thu Apr 19 16:45:47 2012 kevin platel
*/

#include	<stdlib.h>
#include        "master.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

char	*my_strdup(char *str)
{
  char	*new;
  int	i;

  i = -1;
  if (!str)
    return (NULL);
  new = malloc((my_strlen(str) + 1) * sizeof(char));
  if (new == NULL)
    return (NULL);
  while (str[++i])
    new[i] = str[i];
  new[i] = 0;
  return (new);
}

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] != 0 && s2[i] != 0)
    {
      if (s1[i] != s2[i])
	return (s1[i] - s2[i]);
      i++;
    }
  if (s1[i] != 0 || s2[i] != 0)
    return (s1[i] - s2[i]);
  return (0);
}

int	main(int ac, char **av)
{
  char	*code;
  char	*pion;
  int	tentative;
  int	slot;
  int	i;

  i = 0;
  code = NULL;
  pion = NULL;
  tentative = 10;
  slot = 4;
  while (ac > ++i)
      if (my_strcmp(av[i], "-c") == 0 && i < ac)
	code = my_strdup(av[i + 1]);
      else if (my_strcmp(av[i], "-p") == 0 && i < ac)
	pion = my_strdup(av[i + 1]);
      else if (my_strcmp(av[i], "-s") == 0 && i < ac)
	slot = my_get_nbr(av[i + 1]);
      else if (my_strcmp(av[i], "-t") == 0 && i < ac)
	tentative = my_get_nbr(av[i + 1]);
  (pion == NULL) ? (pion = my_strdup("01234567")) : (pion = pion);
  (code == NULL) ? (code = my_rand_code(slot, pion)) : (code = code);
  game(code, pion, tentative, slot);
  return (0);
}
