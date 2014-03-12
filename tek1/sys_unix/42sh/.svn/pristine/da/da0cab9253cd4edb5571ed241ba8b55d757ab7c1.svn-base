/*
** edit_env.c for 42sh in /home/leprov_a//depot/42sh/src/edit/src
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Fri May 18 01:22:47 2012 alexis leprovost
** Last update Fri May 18 12:29:03 2012 alexis leprovost
*/

#include	<stdlib.h>

#include	"env.h"
#include	"config.h"
#include	"builtin.h"

int	edit_env(t_config *config, t_env **sys)
{
  t_env	*local;

  if (config == NULL)
    return (EXIT_FAILURE);
  local = config->env;
  while (local)
    {
      check_exist_or_not(sys, local->name, local->value);
      local = local->prev;
    }
  return (EXIT_SUCCESS);
}
