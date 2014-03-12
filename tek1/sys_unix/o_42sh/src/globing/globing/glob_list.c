
/*
** glob_list.c for glob in /home/vink/projet/sys_unix/42sh/src/globing/globing
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Tue Apr 17 12:14:50 2012 kevin platel
Last update Wed May  2 21:45:08 2012 kevin platel
*/

#include <stdio.h>
#include <stdlib.h>

#include	"my.h"

#include	"t_history.h"
#include	"history_create_ptr_func.h"
#include	"history_substitution.h"

#include "sh.h"
#include "xsys.h"
#include "token.h"
#include "globing.h"
#include "env.h"
#include "alias.h"

t_token	*put_in_list(t_token *t, int id, int spec, char *content)
{
  t_token	*new;

  if (t)
    {
      new = xmalloc(sizeof(*new));
      if (new == NULL)
	return (NULL);
      if (t)
	{
	  new->next = t->next;
	  t->next = new;
	}
      new->id = id;
      new->spec = spec;
      new->content = my_strdup(content);
      return (new);
    }
  return (t);
}

t_token	*sep_in_dif_tok(t_token *t, char *str, int spec)
{
  char	**tab;
  int	i;
  t_token	*tmp;

  i = 0;
  tab = my_strtok(str, " ", TOK_DELIM);
  tmp = t;
  while (t && tab && tab[i])
    {
      if (i == 0)
	{
	  t->id = WORD;
	  t->spec = spec;
	  t->content = tab[i];
	}
      else
	t = put_in_list(t, WORD, spec, tab[i]);
      if (t == NULL)
	return (NULL);
      i++;
    }
  return (tmp);
}

t_token	*glob_sep_tok(t_token *t, char *str, int spec)
{
  char	**tab;
  int	i;

  i = 0;
  tab = my_strtok(str, " ", TOK_DELIM);
  while (t && tab && tab[i])
    {
      if (i == 0)
	{
	  t->id = WORD;
	  t->spec = t->spec;
	  t->content = tab[i];
	}
      else
	t = put_in_list(t, WORD, spec, tab[i]);
      if (t == NULL)
	return (NULL);
      i++;
    }
  return (t);
}

int	globing_var(t_token *t, t_global *glob)
{
  char	*str;
  int	i;

  str = my_strdup(t->content);
  if ((int) t->id == (int) WORD
      && ((int) t->spec == (int) VARIABLES || t->spec == (int) NONE)
      && glob && glob->config)
    {
      i = 1;
      t = sep_in_dif_tok(t, glob_alias(t->content, glob->config->alias, &i), t->spec);
      if (i != 0)
	{
	  i = 2;
	  res_alias(glob->config->alias);
	  glob_alias(str, glob->config->alias, &i);
	  t = glob_gest_tok_list(t, glob, 0, str);
	}
     }
  if ((int) t->id == (int) WORD &&
      ((int) t->spec == (int) VARIABLES || (int) t->spec == (int) D_QUOTE))
    t = sep_in_dif_tok(t, globing_env(t->content, glob->env, G_E_WITH_DOL),
		       t->spec);
  if (t && (int) t->id == (int) WORD &&
      (((int) t->spec == (int) B_QUOTE) || (int) t->spec == (int) PAR))
    {
      t = glob_back_quotes(t, glob);
      if (t == NULL)
	return (1);
    }
  if ((int) t->id == (int) WORD
      && ((int) t->spec == (int) VARIABLES || (int) t->spec == NONE))
    t = glob_sep_tok(t, globing(t->content, glob, GLOB_DIR), t->spec);
  if (str)
    free(str);
  return (0);
}

int	glob_list(t_token *tok, t_global *glob, int i)
{
  while (tok)
    {
      if (tok->id == WORD)
	{
	  if (i == 0 && glob->config)
	    reset_alias(glob->config->alias);
	  if (globing_var(tok, glob) > 0)
	    return (1);
	}
      tok = tok->next;
    }
  return (0);
}
