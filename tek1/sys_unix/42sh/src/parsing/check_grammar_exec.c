/*
** check_grammar_exec.c for check_grammar_exec in /home/ozouf_h//42sh/src/parsing
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Wed Apr 18 20:03:59 2012 harold ozouf
** Last update Tue May  8 19:04:31 2012 harold ozouf
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"tree.h"
#include	"token.h"
#include	"puterror.h"
#include	"check_grammar_exec.h"

static	int	there_are_red(t_token *b, t_token *e)
{
  t_token *tmp;

  tmp = b;
  while (tmp && tmp != e)
    {
      if (tmp->id == S_RED_LEFT || tmp->id == D_RED_LEFT)
	return (1);
      else if (tmp->id == S_RED_RIGHT || tmp->id == D_RED_RIGHT)
	return (2);
      else if (tmp->id == S_RED_RIGHT_ERR || tmp->id == D_RED_RIGHT_ERR)
	return (2);
      tmp = tmp->next;
    }
  return (0);
}

static	t_bool	check_prefix_exec(t_token **begin, t_token *end,
				  int *left, int *right)
{
  int		i;

  *left = 0;
  *right = 0;
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
  int		r;
  int		l;
  int		word;

  word = 0;
  r = 0;
  if (b->id != WORD)
    return (check_prefix_exec(&b, e, &l, &r));
  while (b && b != e)
    {
      if (b->id == S_RED_RIGHT || b->id == D_RED_RIGHT ||
	  b->id == S_RED_RIGHT_ERR || b->id == D_RED_RIGHT_ERR)
	{
	  if (!word)
	    return (puterror(AMB_OUT, NULL));
	  r++;
	}
      else if (r >= 1 && b->id != WORD)
	return (puterror(AMB_OUT, NULL));
      word = (b->id == WORD) ? (1) : (0);
      b = b->next;
    }
  if (!word && r == 1)
    return (puterror(MISSING_N, NULL));
  return ((r > 1) ? (puterror(AMB_OUT, NULL)) : (TRUE));
}

static t_bool	check_left(t_token *b, t_token *e)
{
  int		r;
  int		l;
  int		word;

  word = 0;
  l = 0;
  r = 0;
  if (b->id != WORD)
    return (check_prefix_exec(&b, e, &l, &r));
  while (b && b != e)
    {
      if (b->id == PIPE || b->id == S_RED_LEFT || b->id == D_RED_LEFT)
	{
	  if (!word || (b->id == PIPE && r == 0))
	    return (puterror(AMB_IN, NULL));
	  r++;
	}
      if (l >= 1 && (b->id == S_RED_LEFT || b->id == D_RED_LEFT))
	return (puterror(AMB_IN, NULL));
      word = (b->id == WORD) ? (1) : (0);
      b = b->next;
    }
  if (!word && l == 1)
    return (puterror(MISSING_N, NULL));
  return ((l > 1) ? (puterror(AMB_IN, NULL)) : (TRUE));
}

t_bool	check_grammar_exec(t_token *b, t_token *e)
{
  t_token	*tmp;
  int		word;
  int		pipe;
  int		res;

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

  res = there_are_red(b, e);
  if (res == 1 && check_left(b, e) != TRUE)
    return (FALSE);
  else if (res == 2 && check_right(b, e) != TRUE)
    return (FALSE);
  return (TRUE);
}
