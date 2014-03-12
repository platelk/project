/*
** check_bloc_exec.c for check_bloc_exec in /home/ozouf_h//42sh/src/parsing
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Sat Apr 14 22:51:05 2012 harold ozouf
** Last update Sat Apr 28 11:46:32 2012 kevin platel
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"tree.h"
#include	"token.h"
#include	"puterror.h"
#include	"add_child.h"
#include	"check_cmd.h"
#include	"check_grammar_exec.h"
#include	"my_rev_node.h"
#include	"check_bloc_exec.h"


static t_bool	there_are_two_red(t_token *b, t_token *e)
{
  t_token *tmp;
  int		l;
  int		r;

  l = 0;
  r = 0;
  tmp = b;
  while (tmp && tmp != e)
    {
      if (tmp->id == S_RED_LEFT || tmp->id == D_RED_LEFT)
	l = 1;
      else if (tmp->id == S_RED_RIGHT || tmp->id == D_RED_RIGHT ||
	       tmp->id == D_RED_RIGHT_ERR || tmp->id == S_RED_RIGHT_ERR)
	r = 1;
      tmp = tmp->next;
    }
  if (l && r)
    return (TRUE);
  return (FALSE);
}

static void	get_pre_exec(t_token *tok, t_token **file, t_token **b, t_token **e)
{
  t_token	*end;

  end = *e;
  *file = tok;
  *b = tok->next;
  while (tok && tok != end)
    tok = tok->next;
  *e = tok;
}

static t_t_list	get_exec(t_token *tok, t_token **file, t_token **b, t_token **e)
{
  t_t_list	type;

  *b = tok;
  while (tok->id == WORD && tok != *e)
    tok = tok->next;
  *e = tok;
  type = tok->id;
  *file = tok->next;
  return (type);
}

static t_bool	check_red(t_token *b, t_token *e, t_node **root)
{
  t_token	*begin;
  t_token	*end;
  t_token	*file;
  int		type;

  type = b->id;
  end = e;
  if (b->id != WORD)
    get_pre_exec(b->next, &file, &begin, &end);
  else
    type = get_exec(b, &file, &begin, &end);
  add_node(root, type, NULL);
  add_child(root);
  if (!file)
    return (puterror(MISSING_N, NULL));
  add_node(&((*root)->child->nd), CMD, file->content);
  add_child(root);
  add_node(&((*root)->child->nd), CMD, begin->content);
  begin = begin->next;
  while (begin && begin != end)
    {
      add_child(&((*root)->child->nd));
      add_node(&((*root)->child->nd->child->nd), ARG, begin->content);
      begin = begin->next;
    }
  my_rev_node(&((*root)->child->nd->child));
  return (TRUE);
}

static t_bool	there_are_red(t_token *b, t_token *e)
{
  t_token	*tmp;

  tmp = b;
  while (tmp && tmp != e)
    {
      if (tmp->id != WORD)
	return (TRUE);
      tmp = tmp->next;
    }
  return (FALSE);
}

static t_bool	get_spe_red(t_node **r, t_token *b, t_token *e)
{
  t_token	*tmp;
  t_token	*tok;

  tmp = b;
  while (tmp && tmp != e && tmp->id != S_RED_RIGHT && tmp->id != D_RED_RIGHT &&
	       tmp->id != D_RED_RIGHT_ERR && tmp->id != S_RED_RIGHT_ERR)
    tmp = tmp->next;
  tok = tmp->next;
  add_node(r, tmp->id, tmp->content);
  add_child(r);
  add_node(&((*r)->child->nd), CMD, tmp->next->content);
  tmp = tmp->next->next;
  while (tmp && tmp != e)
    {
      add_child(&((*r)->child->nd));
      add_node(&((*r)->child->nd->child->nd), ARG, tmp->content);
      tmp = tmp->next;
    }
  add_child(r);
  if (check_red(b, tok, &((*r)->child->nd)) != TRUE)
    return (FALSE);
  return (TRUE);
}

t_bool	check_bloc_exec(t_token *b, t_token *e, t_node **root)
{
  if (there_are_two_red(b, e) == TRUE)
    {
      if (get_spe_red(root, b, e) != TRUE)
	return (FALSE);
    }
  else if (there_are_red(b, e) == TRUE)
    {
      if (check_red(b, e, root) != TRUE)
	return (FALSE);
    }
  else
    {
      add_node(root, CMD, b->content);
      b = b->next;
      while (b && b != e)
	{
	  add_child(root);
	  add_node(&((*root)->child->nd), ARG, b->content);
	  b = b->next;
	}
      my_rev_node(&((*root)->child));
    }
  return (TRUE);
}
