/*
** check_args.c for check_args in /home/leprov_a//depot/corewar/source/ASM/errors
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Wed Feb  8 18:04:12 2012 alexis leprovost
** Last update Wed Mar 21 10:51:45 2012 alexis leprovost
*/

#include <stdlib.h>

#include "corewar.h"

int	check_file(char *str)
{
  char	**tab;
  char	*bdd;
  int	ret;
  int	i;

  i = -1;
  bdd = my_strdup(".");
  tab = my_strtok(str, bdd);
  free(bdd);
  if (tab != NULL && my_tablen(tab) > 1)
    while (tab[++i] != NULL);
  else
    ret = EXIT_FAILURE;
  if (!my_strcmp(tab[--i], "s"))
    ret = EXIT_SUCCESS;
  else
    ret = EXIT_FAILURE;
  my_free_tab(tab);
  return (ret);
}
