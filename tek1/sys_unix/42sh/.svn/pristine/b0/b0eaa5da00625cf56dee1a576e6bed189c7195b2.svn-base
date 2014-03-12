/*
** glob_gest_tok_list.c for 42s in /home/vink/projet/sys_unix/42sh
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Sat Apr 28 12:13:39 2012 kevin platel
** Last update Sat May 19 20:40:41 2012 kevin platel
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

int	check_alias(t_token *t, char *str)
{
  while (t)
    {
      if (my_strcmp(t->content, str) == 0)
	t->spec = CMD;
      t = t->next;
    }
  return (0);
}

t_token	*glob_gest_tok_list(t_token *t, t_global *glob, int flag, char *str)
{
  t_token	*tmp;
  t_token	*tmp2;
  t_token	*tmp3;

  (flag == 0) ? (tmp = creat_list_token(t->content, glob, 0)) :
    (tmp = analyse_cmd(t->content));
  if (str)
    (check_alias(tmp, str));
  if (t && tmp)
    {
      tmp2 = t->next;
      (t->content) ? free(t->content) : (NULL);
      t->content = my_strdup(tmp->content);
      t->id = tmp->id;
      t->spec = tmp->spec;
      (tmp->content) ? (free(tmp->content)) : (tmp->content = NULL);
      (tmp->next) ? (t->next = tmp->next) : (t->next = t->next);
      tmp3 = tmp;
      tmp = tmp->next;
      tmp3 ? (free(tmp3)) : (tmp3 = tmp3);
      while (tmp && tmp->next)
	tmp = tmp->next;
      (tmp) ? tmp->next = tmp2 : (tmp = t);
    }
  return (t);
}
