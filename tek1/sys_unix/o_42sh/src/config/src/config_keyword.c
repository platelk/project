/*
** config_keyword.c for 42sh in /home/leprov_a//depot/42sh/src/config/src
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Mon Apr 16 00:49:40 2012 alexis leprovost
** Last update Wed Apr 25 11:05:27 2012 alexis leprovost
*/

#include	"config.h"
#include	"xsys.h"
#include	"my.h"

char	**config_keyword(void)
{
  char	**tab;

  if ((tab = xmalloc(sizeof(*tab) * MAX_KEYWORD_NUMBER)) == NULL)
    return (NULL);
  tab[0] = PROMPT_CONFIG_STRING;
  tab[1] = HISTORY_CONFIG_STRING;
  tab[2] = SAVEHIST_CONFIG_STRING;
  tab[3] = ALIAS_CONFIG_STRING;
  tab[4] = AUTOLIST_CONFIG_STRING;
  tab[5] = COMPLETE_CONFIG_STRING;
  tab[6] = ENV_CONFIG_STRING;
  tab[7] = NULL;
  return (tab);
}

int	config_iskeyword(char *str, char **keyword)
{
  int	i;

  i = -1;
  while (keyword[++i])
    if (!my_strncmp(keyword[i], str, (my_strlen(keyword[i]) - 1)))
      return (i);
  return (i);
}

