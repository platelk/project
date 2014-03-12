/*
** check_args.c for check_args in /home/leprov_a//depot/corewar/source/VM/check
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Fri Feb  3 11:54:46 2012 alexis leprovost
** Last update Sun Mar 25 01:53:41 2012 ronan guiho
*/

#include <stdlib.h>

#include "corewar.h"

int	is_number(char *str)
{
  char	*bdd;
  int	i;
  int	k;
  int	len;

  len = 0;
  bdd = my_strdup("0123456789");
  i = -1;
  while (str[++i])
    {
      k = -1;
      while (bdd[++k] && str[i] != bdd[k]);
      if (bdd[k] == str[i])
	len++;
    }
  free(bdd);
  if (len != my_strlen(str))
    return (1);
  return (0);
}

int	is_valid_exec(char *str)
{
  char	**tab;
  int	i;

  i = -1;
  if ((tab = my_str_to_tab(str, ".cor")) == NULL ||
      my_tablen(tab) == 0)
    return (0);
  while (tab[++i]);
  if (!my_strcmp(tab[i - 1], ".cor"))
    {
      my_free_tab(tab);
      return (1);
    }
  my_free_tab(tab);
  return (0);
}

int	check_args(int ac, char **av)
{
  int	champ;

  champ = 0;
  if (ac < 2)
    return (1);
  if (ac > 1)
    {
      while ((--ac + 1) > 1)
	{
	  if (my_strcmp(av[ac], "-n") && my_strcmp(av[ac], "-a") &&
	      my_strcmp(av[ac], "-dump") && my_strcmp(av[ac], "-rr") &&
	      my_strcmp(av[ac], "-rm") && is_number(av[ac]) &&
	      is_valid_exec(av[ac]))
	    champ++;
	}
      if (champ >= 1 && champ <= MAX_CHAMPS_NUMBER)
	return (0);
    }
  if (champ < 1)
    my_puterror("Corewar: Too few champions.\n");
  else
    my_puterror("Corewar: Too many champions.\n");
  return (1);
}
