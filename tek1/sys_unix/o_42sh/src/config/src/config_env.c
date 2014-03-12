/*
** config_env.c for 42sh in /home/leprov_a//depot/42sh/src/config/src
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Wed Apr 18 13:44:44 2012 alexis leprovost
** Last update Wed Apr 18 15:06:57 2012 alexis leprovost
*/

#include	<stdlib.h>
#include	<stdio.h>

#include	"config.h"
#include	"env.h"
#include	"my_strtok.h"
#include	"xsys.h"

int	config_env(char *str, t_config *config)
{
  char	**tab;
  char	**spec;
  char	*base;
  char	*var;

  base = DELIM_ENV_STRING;
  if ((tab = my_strtok(str, base, TOK_DELIM)) == NULL ||
      my_tablen(tab) != ENV_STRING_NUMBER)
    return (EXIT_FAILURE);
  base = DELIM_SPACE_STRING;
  if ((spec = my_strtok(tab[0], base, TOK_DELIM)) == NULL ||
      my_tablen(spec) != ENV_STRING_NUMBER ||
      (var = xmalloc(sizeof(*var) *					\
      (my_strlen(spec[1]) + my_strlen(tab[1]) + 2))) == NULL)
    return (EXIT_FAILURE);
  sprintf(var, "%s=%s", spec[1], tab[1]);
  config->env = creat_list_env(var, config->env);
  my_free_tab(tab);
  my_free_tab(spec);
  free(var);
  return (EXIT_SUCCESS);
}
