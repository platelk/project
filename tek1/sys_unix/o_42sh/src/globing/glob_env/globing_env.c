/*
** globing_env.c for globing_env in /home/vink/projet/sys_unix/42sh/src/globing
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Wed Apr 11 15:45:45 2012 kevin platel
** Last update Wed May  2 15:01:01 2012 kevin platel
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "my_strtok.h"
#include "globing.h"
#include "utils.h"
#include "env.h"
#include "my.h"
#include "token.h"

t_token	 *rep_token_env(t_token *tok, t_env *env)
{
  if (tok && tok->next && tok->id == DOLLARS)
    {
      tok->id = -1;
      tok->next->content = globing_env(tok->next->content, env,
				       G_E_WITHOUT_DOL);
    }
  return (tok);
}

char	*globing_env(char *str, t_env *env, int flag)
{
  char	*new;
  char	**tab;
  int	i;

  i = 0;
  if (str == NULL)
    return (NULL);
  tab = my_strtok(str, " \n\t", TOK_DELIM);
  new = strdup(str);
  while (tab[i])
    {
      if (flag == G_E_WITH_DOL && tab[i][0] == CHAR_VAR_ENV)
	{
	  if (find_in_env(&(tab[i][1]), env) == NULL)
	    fprintf(stderr, "%s : Undefinded variable.\n", &tab[i][1]);
	  else
	    new = replace_str(my_strdup(find_in_env(&(tab[i][1]), env)), &(tab[i][0]), new);
	}
      else if (flag == G_E_WITHOUT_DOL)
	new = my_strdup(find_in_env(tab[i], env));
      i++;
    }
  my_free_tab(tab);
  return (new);
}
