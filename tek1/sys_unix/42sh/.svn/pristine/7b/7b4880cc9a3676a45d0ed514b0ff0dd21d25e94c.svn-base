/*
** config_free.c for 42sh in /home/leprov_a//depot/42sh/src/config/src
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Sat May 19 14:22:03 2012 alexis leprovost
** Last update Sat May 19 14:37:38 2012 alexis leprovost
*/

#include	<stdlib.h>

#include	"config.h"
#include	"alias.h"
#include	"env.h"

static void	alias_free(t_alias *alias)
{
  t_alias	*tmp;

  while (alias)
    {
      tmp = alias->next;
      (alias->initial) ? free(alias->initial) : (alias->initial = NULL);
      (alias->alias) ? free(alias->alias) : (alias->alias = NULL);
      free(alias);
      alias = tmp;
    }
}

void	config_free(t_config *config)
{
  if (config)
    {
      (config->prompt) ? free(config->prompt) : (config->prompt = NULL);
      (config->env) ? env_free(config->env) : (config->env = NULL);
      (config->option) ? free(config->option) : (config->option = NULL);
      (config->alias) ? alias_free(config->alias) : (config->alias = NULL);
    }
}
