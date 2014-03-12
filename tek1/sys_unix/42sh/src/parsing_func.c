/*
** parsing_func.c for parsing in /home/vink/projet/sys_unix/42sh/src
**
** Made by kevin platel
** Login   <vink@epitech.net>
**
** Started on  Tue May  8 23:11:29 2012 kevin platel
** Last update Sat May 19 14:22:59 2012 kevin platel
*/

#include	<stdlib.h>
#include	<stdio.h>

#include	"sh.h"
#include	"free_child.h"
#include	"globing.h"
#include	"env.h"
#include	"t_history.h"
#include	"history_putlist.h"
#include	"token.h"
#include	"my_rev_list.h"
#include	"reconstruct_token.h"
#include	"check_expression.h"
#include	"alias.h"
#include	"global.h"
#include	"my.h"

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

t_token	*analyse_cmd(char *cmd)
{
  t_token	*tok;
  t_token	*new;

  tok = pars_tokenizer(cmd);
  if (tok == NULL)
    return (NULL);
  my_rev_list(&tok);
  new = reconstruct_token(tok);
  if (tok)
    free_token(tok);
  if (new == NULL)
    return (NULL);
  return (new);
}

t_token	*creat_list_token(char *cmd, t_global *glob, int f)
{
  t_token	*new;

  new = analyse_cmd(cmd);
  glob_list(&new, glob, 1, f);
  return (new);
}

t_node	*parsing_func(char *cmd, t_global *glob, int f)
{
  t_token	*new;
  t_node	*root;
  void		*ret;

  if ((new = analyse_cmd(cmd)) == NULL)
    {
      history_putlist(my_strdup(cmd), &(glob->hist), glob->config);
      glob->exit = EXIT_FAILURE;
      return (NULL);
    }
  ret = new;
  root = NULL;
  new = glob_hist(new, glob, &ret);
  if (ret && glob_list(&new, glob, 0, f) > 0)
    return (NULL);
  if (ret && glob && glob->config)
    reset_alias(glob->config->alias);
  if (new && ret && check_expression(new, &root) != TRUE)
    ret = NULL;
  if (ret == NULL)
    (glob->exit = EXIT_FAILURE);
  else
    (ret = root);
  free_token(new);
  return (ret);
}
