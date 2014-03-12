/*
** glob_gest_tok_list.c for 42s in /home/vink/projet/sys_unix/42sh
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Sat Apr 28 12:13:39 2012 kevin platel
** Last update Tue May  1 13:20:49 2012 kevin platel
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
}

t_token	*glob_gest_tok_list(t_token *t, t_global *glob, int flag, char *str)
{
  t_token	*tmp;
  t_token	*tmp2;

  if (flag == 0)
    tmp = creat_list_token(t->content, glob);
  else
    tmp = analyse_cmd(t->content);
  if (str)
    check_alias(tmp, str);
  if (t && tmp)
    {
      tmp2 = t->next;
      t->content = tmp->content;
      t->id = tmp->id;
      t->spec = tmp->spec;
      if (tmp->next)
	t->next = tmp->next;
      tmp = tmp->next;
      while (tmp && tmp->next)
	tmp = tmp->next;
      if (tmp)
	tmp->next = tmp2;
    }
  return (t);
}
