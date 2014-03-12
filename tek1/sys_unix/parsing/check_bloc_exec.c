/*
** check_bloc_exec.c for check_bloc_exec in /home/ozouf_h//42sh/src/parsing
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Sat Apr 14 22:51:05 2012 harold ozouf
** Last update Tue Apr 17 18:36:26 2012 harold ozouf
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"tree.h"
#include	"token.h"
#include	"puterror.h"
#include	"add_child.h"
#include	"check_cmd.h"
#include	"check_bloc_exec.h"

static t_t_list	get_next_exec(t_token *e, t_token **begin, t_token **end)
{
  static t_token	*tmp;
  t_token		*it;

  if (*begin != NULL)
    tmp = *begin;
  if (tmp == e)
    return (UNKNOW);
  it = tmp;
  while (it && it != e && it->id != PIPE &&
		     it->id != S_RED_LEFT &&
		     it->id != D_RED_LEFT &&
		     it->id != S_RED_RIGHT &&
		     it->id != D_RED_RIGHT &&
		     it->id != S_RED_RIGHT_ERR &&
		     it->id != D_RED_RIGHT_ERR)
    it = it->next;
  *end = it;
  *begin = tmp;
  tmp = (it != e) ? (it->next) : (it);
  return (!it || (it->id != PIPE && it->id != S_RED_LEFT &&
		  it->id != D_RED_LEFT && it->id != S_RED_RIGHT &&
		  it->id != D_RED_RIGHT && it->id != S_RED_RIGHT_ERR &&
		  it->id != D_RED_RIGHT_ERR) ? (UNKNOW) : (it->id));
}

static	t_bool	check_prefix_exec(t_token **begin, t_token *end, int *left, int *right)
{
  int		i;

  i = 0;
  if ((*begin)->id == S_RED_LEFT || (*begin)->id == D_RED_LEFT)
    *left = 1;
  else
    *right = 1;
  *begin = (*begin)->next;
  while (*begin && *begin != end && (*begin)->id == WORD)
    {
      i++;
      *begin = (*begin)->next;
    }
  if (i < 2)
    return (puterror(NULL_CMD, NULL));
  return (TRUE);
}

static t_bool	check_right(t_token *b, t_token *e)
{
  t_token	*tmp;
  int		r;
  int		l;
  int		word;

  word = 0;
  l = 0;
  r = 0;
  tmp = b;
  if (tmp->id != WORD && check_prefix_exec(&tmp, e, &l, &r) != TRUE)
    return (FALSE);
  while (tmp && tmp != e)
    {
      if (tmp->id == S_RED_RIGHT || tmp->id == D_RED_RIGHT ||
	  tmp->id == S_RED_RIGHT_ERR || tmp->id == D_RED_RIGHT_ERR)
	{
	  if (!word)
	    return (puterror(AMB_OUT, NULL));
	  else
	    r++;
	}
      else if (r >= 1 && tmp->id != WORD)
	return (puterror(AMB_OUT, NULL));
      word = (tmp->id == WORD) ? (1) : (0);
      tmp = tmp->next;
    }
  if (!word && r == 1)
    return (puterror(MISSING_N, NULL));
  return ((r > 1) ? (puterror(AMB_OUT, NULL)) : (TRUE));
}

static t_bool	check_left(t_token *b, t_token *e)
{
  t_token	*tmp;
  int		r;
  int		l;
  int		word;

  word = 0;
  l = 0;
  r = 0;
  tmp = b;
  if (tmp->id != WORD && check_prefix_exec(&tmp, e, &l, &r) != TRUE)
    return (FALSE);
  while (tmp && tmp != e)
    {
      if (tmp->id == S_RED_LEFT || tmp->id == D_RED_LEFT)
	{
	  if (!word)
	    return (puterror(AMB_IN, NULL));
	  else
	    r++;
	}
      if (l >= 1 && tmp->id != WORD)
	return (puterror(AMB_IN, NULL));
      word = (tmp->id == WORD) ? (1) : (0);
      tmp = tmp->next;
    }
  if (!word && l == 1)
    return (puterror(MISSING_N, NULL));
  return ((l > 1) ? (puterror(AMB_IN, NULL)) : (TRUE));
}

static	t_bool	check_grammar_exec(t_token *b, t_token *e)
{
  t_token	*tmp;
  int		word;
  int		pipe;

  tmp = b;
  word = 0;
  pipe = 0;
  while (tmp && tmp != e)
    {
      if (!word && tmp->id == PIPE)
	return (puterror(NULL_CMD, NULL));
      word = (tmp->id == WORD) ? (1) : (0);
      pipe = (tmp->id == PIPE) ? (1) : (0);
      tmp = tmp->next;
    }
  if (pipe)
    return (puterror(NULL_CMD, NULL));
  if (check_left(b, e) != TRUE || check_right(b, e) != TRUE)
    return (FALSE);
  return (TRUE);
}

t_bool	check_bloc_exec(t_token *b, t_token *e, t_node **root, int flag)
{
  t_t_list	res;
  t_token	*begin;
  t_token	*end;

  if (check_grammar_exec(b, e) != TRUE)
    return (FALSE);
  begin = (flag) ? (b) : (NULL);
  res = get_next_exec(e, &begin, &end);
  if (res != UNKNOW)
    {
      add_node(root, res, NULL);
      add_child(root);
      check_bloc_exec(b, e, &((*root)->child->nd), 0);
      add_child(root);
      check_cmd(begin, end, &((*root)->child->nd));
      }
  else
    check_cmd(begin, end, root);
  return (TRUE);
}

