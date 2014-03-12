/*
** config_keyword.c for 42sh in /home/leprov_a//depot/42sh/src/config/src
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Mon Apr 16 00:49:40 2012 alexis leprovost
** Last update Sat May 19 09:53:41 2012 alexis leprovost
*/

#include	<stdlib.h>

#include	"config.h"
#include	"xsys.h"
#include	"my.h"

int	config_keyword(char **tab)
{
  if (tab == NULL)
    return (EXIT_FAILURE);
  tab[0] = PROMPT_CONFIG_STRING;
  tab[1] = HISTORY_CONFIG_STRING;
  tab[2] = SAVEHIST_CONFIG_STRING;
  tab[3] = ALIAS_CONFIG_STRING;
  tab[4] = AUTOLIST_CONFIG_STRING;
  tab[5] = COMPLETE_CONFIG_STRING;
  tab[6] = ENV_CONFIG_STRING;
  tab[MAX_KEYWORD_NUMBER - 1] = NULL;
  return (EXIT_SUCCESS);
}

int	config_iskeyword(char *str, char **keyword, int size)
{
  int	i;

  i = -1;
  if (keyword == NULL || str == NULL)
    return (size - 1);
  while (keyword[++i])
    if (!my_strncmp(keyword[i], str, (my_strlen(keyword[i]) - 1)))
      return (i);
  return (i);
}
