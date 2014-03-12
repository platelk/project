/*
** globing_env.c for globing_env in /home/vink/projet/sys_unix/42sh/src/globing
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Wed Apr 11 15:45:45 2012 kevin platel
** Last update Wed May 16 08:11:10 2012 kevin platel
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "global.h"
#include "my_strtok.h"
#include "globing.h"
#include "utils.h"
#include "env.h"
#include "my.h"
#include "token.h"

char	*other_cas(char *str, t_global *glob)
{
  char	*tmp;
  int	i;

  i = 0;
  tmp = malloc(128 * sizeof(*tmp));
  if (my_strcmp(str, "$$") == 0)
    {
      snprintf(tmp, 128, "%d", getpid());
      i++;
    }
  if (my_strcmp(str, "$?") == 0)
    {
      snprintf(tmp, 128, "%d", glob->exit);
      i++;
    }
  if (i > 0)
    return (tmp);
  if (tmp)
    free(tmp);
  return (NULL);
}

char	*globing_env(char *str, t_env *env, t_global *glob, int flag)
{
  char	*new;
  char	**tab;
  int	i;

  i = -1;
  if (str == NULL)
    return (NULL);
  if (other_cas(str, glob) != NULL)
    return (other_cas(str, glob));
  tab = my_strtok(str, " \n\t", TOK_DELIM);
  new = strdup(str);
  while (tab && tab[++i])
      if (flag & G_E_WITH_DOL && tab[i][0] == CHAR_VAR_ENV)
	{
	  if (find_in_env(&(tab[i][1]), env) == NULL && (flag & 16))
	    fprintf(stderr, "%s : Undefined variable.\n", &tab[i][1]);
	  else if (find_in_env(&(tab[i][1]), env) != NULL)
	    new = replace_str(my_strdup(find_in_env(&(tab[i][1]), env)),
			      &(tab[i][0]), new);
	}
      else if (flag == G_E_WITHOUT_DOL && find_in_env(tab[i], env))
	new = my_strdup(find_in_env(tab[i], env));
  my_free_tab(tab);
  return (new);
}
