/*
** config_history.c for 42sh in /home/leprov_a//depot/42sh/src/config/src
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Mon Apr 16 12:06:11 2012 alexis leprovost
** Last update Sat May 19 09:52:58 2012 alexis leprovost
*/

#include	<stdlib.h>

#include	"config.h"
#include	"xsys.h"
#include	"my_strtok.h"
#include	"my.h"

int	config_history(char *str, t_config *config)
{
  char	**tab;
  char	*base;
  int	history;

  base = DELIM_HISTORY_STRING;
  if ((tab = my_strtok(str, base, TOK_DELIM)) == NULL ||
      my_tablen(tab) != HISTORY_STRING_NUMBER)
    {
      (tab) ? my_free_tab(tab) : (tab = NULL);
      return (EXIT_FAILURE);
    }
  if ((history = my_getnbr(tab[1])) < 0 || isanumber(tab[1]))
    fprintf(stderr, "History: Badly formed number.\n");
  (tab) ? my_free_tab(tab) : (tab = NULL);
  history = history < 0 ? 0 : history;
  config->option[HIST] = history;
  return (EXIT_SUCCESS);
}

int	config_savehist(char *str, t_config *config)
{
  char	**tab;
  char	*base;
  int	savehist;

  base = DELIM_SAVEHIST_STRING;
  if ((tab = my_strtok(str, base, TOK_DELIM)) == NULL ||
      my_tablen(tab) != SAVEHIST_STRING_NUMBER)
    {
      (tab) ? my_free_tab(tab) : (tab = NULL);
      return (EXIT_FAILURE);
    }
  if ((savehist = my_getnbr(tab[1])) < 0 || isanumber(tab[1]))
    fprintf(stderr, "Savehist: Badly formed number.\n");
  (tab) ? my_free_tab(tab) : (tab = NULL);
  savehist = savehist < 0 ? 0 : savehist;
  config->option[SAVEHIST] = savehist;
  return (EXIT_SUCCESS);
}
