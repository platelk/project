/*
** parsing_func.c for 42sh in /home/vink/projet/sys_unix/42sh/src
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Wed Apr 18 18:52:07 2012 kevin platel
*/

#include	<stdlib.h>
#include	<stdio.h>

#include	"globing.h"
#include	"env.h"
#include	"t_history.h"
#include	"token.h"
#include	"my_rev_list.h"
#include	"reconstruct_token.h"
#include	"check_expression.h"
#include	"alias.h"
#include	"global.h"

char	*get_cmd_in_list(t_token *t)
{
  char	*new_str;

  new_str = NULL;
  while (t)
    {
      if (t->spec == S_QUOTE)
	new_str = my_strmcat(new_str, "'");
      if (t->spec == D_QUOTE)
	new_str = my_strmcat(new_str, "\"");
      if (t->spec == B_QUOTE)
	new_str = my_strmcat(new_str, "`");
      new_str = my_strmcat(new_str, t->content);
      if (t->spec == D_QUOTE)
	new_str = my_strmcat(new_str, "\"");
      if (t->spec == S_QUOTE)
	new_str = my_strmcat(new_str, "'");
      if (t->spec == B_QUOTE)
	new_str = my_strmcat(new_str, "`");
      if (t->next)
	new_str = my_strmcat(new_str, " ");
      t = t->next;
    }
  return (new_str);
}

void	reset_alias(t_alias *alias)
{
  while (alias)
    {
      alias->flag = 0;
      alias = alias->next;
    }
}

t_token	*analyse_cmd(char *cmd)
{
  t_token	*tok;
  t_token	*new;

  tok = pars_tokenizer(cmd);
  if (tok == NULL)
    return (tok);
  my_rev_list(&tok);
  new = reconstruct_token(tok);
  if (new == NULL)
    return (NULL);
  return (new);
}

t_token	*creat_list_token(char *cmd, t_global *glob)
{
  t_token	*new;

  new = analyse_cmd(cmd);
  glob_list(new, glob, 1);
  return (new);
}

t_node	*parsing_func(char *cmd, t_global *glob)
{
  t_token	*new;
  t_node	*root;
  char		**type_str;
  t_token	*tmp;
  void	*ret;
  int	i;

  type_str = put_str_subs();
  new = analyse_cmd(cmd);
  tmp = new;
  root = NULL;
  ret = NULL;
  if (new == NULL)
    return (NULL);
  i = 0;
  while (tmp)
    {
      if ((int) tmp->spec == HISTORY)
	{
	  tmp = sep_in_dif_tok(tmp,
			       (ret = history_substitution(tmp->content,
							   glob->hist,
							   type_str)),
			       VARIABLES);
	  if ((ret) == NULL)
	    tmp->content = "\0";
	  tmp = glob_gest_tok_list(tmp, glob, 1, NULL);
	  new = analyse_cmd(get_cmd_in_list(new));
	  i++;
	}
      tmp = tmp->next;
    }
  if (i ==  0 || ret != NULL)
    history_putlist(get_cmd_in_list(new), &(glob->hist));
  if (glob_list(new, glob, 0) > 0)
    return (NULL);
  if (glob && glob->config)
    reset_alias(glob->config->alias);
  if (check_expression(new, &root) != TRUE)
    return (NULL);
  return (root);
}
