/*
** config_globing.c for 42sh in /home/leprov_a//depot/42sh/src/config/src
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Wed Apr 18 12:48:11 2012 alexis leprovost
** Last update Wed Apr 18 13:09:57 2012 alexis leprovost
*/

#include	<stdlib.h>

#include	"config.h"
#include	"my.h"

int	config_globing(char *str, t_config *config)
{
  if (!my_strcmp(str, AUTOLIST_CONFIG_STRING))
    config->option[AUTOLIST] = !config->option[AUTOLIST];
  if (!my_strcmp(str, COMPLETE_CONFIG_STRING))
    config->option[COMPLETE] = !config->option[COMPLETE];
  return (EXIT_SUCCESS);
}
