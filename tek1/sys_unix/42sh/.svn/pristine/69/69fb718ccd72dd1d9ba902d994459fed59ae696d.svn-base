/*
** builtin_alias.c for 42sh in /home/leprov_a//depot/42sh/src/builtin/src/alias
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Thu May 17 14:03:39 2012 alexis leprovost
** Last update Sat May 19 19:38:19 2012 alexis leprovost
*/

#include	<stdlib.h>
#include	<stdio.h>

#include	"global.h"
#include	"config.h"
#include	"alias.h"
#include	"my.h"
#include	"xsys.h"

static void	show_alias(t_alias *alias, char *str)
{
  while (alias)
    {
      if (str == NULL)
	printf("%s=%s\n", alias->initial, alias->alias);
      else if (!my_strcmp(alias->initial, str))
	printf("%s=%s\n", alias->initial, alias->alias);
      alias = alias->next;
    }
}

static char	*alias_concat(char **tab)
{
  char	*str;
  int	len;
  int	i;

  i = -1;
  len = 0;
  while (tab && tab[++i])
    len += (my_strlen(tab[i]) + 2);
  if ((str = xmalloc(sizeof(*str) * (len + 1))) == NULL)
    return (NULL);
  i = -1;
  while (tab && tab[++i])
    {
      str = my_strcat(str, tab[i]);
      if (tab[i + 1] != NULL)
	str = my_strcat(str, " ");
    }
  return (str);
}

static int	my_subalias(t_alias **begin, char *str)
{
  t_alias	*tmp;

  tmp = *begin;
  while (tmp)
    {
      if (!my_strcmp(tmp->initial, str))
	{
	  if (tmp->next != NULL)
	    tmp->next->prev = tmp->prev;
	  if (tmp->prev != NULL)
	    tmp->prev->next = tmp->next;
	  (tmp->initial) ? free(tmp->initial) : (tmp->initial = NULL);
	  (tmp->alias) ? free(tmp->alias) : (tmp->alias = NULL);
	  (tmp->prev == NULL) ? (*begin = tmp->next) : (*begin = *begin);
	  free(tmp);
	  tmp = NULL;
	  return (EXIT_SUCCESS);
	}
      tmp = tmp->next;
    }
  return (EXIT_FAILURE);
}

int	builtin_alias(t_global *global, char **cmd)
{
  int	len;
  char	*alias;

  alias = NULL;
  len = my_tablen(cmd);
  if (len == 1 && global->config != NULL)
    show_alias(global->config->alias, NULL);
  else if (len >= 3 && global->config != NULL)
    {
      alias = alias_concat(&cmd[2]);
      my_putalias(&global->config->alias, cmd[1], alias);
      (alias) ? free(alias) : (alias = NULL);
    }
  else if (len == 2 && global->config != NULL)
    show_alias(global->config->alias, cmd[1]);
  else
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int	builtin_unalias(t_global *global, char **cmd)
{
  int	len;
  int	i;

  i = 0;
  len = my_tablen(cmd);
  if (len == 1)
    {
      fprintf(stderr, "Unalias: Too few arguments.\n");
      return (EXIT_FAILURE);
    }
  else if (global->config != NULL)
    {
      while (cmd[++i])
	my_subalias(&global->config->alias, cmd[i]);
    }
  else
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
