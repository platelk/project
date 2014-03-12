/*
** check_pipe.c for check_pipe in /home/ozouf_h//42sh/src/parsing
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Wed Apr 18 20:29:32 2012 harold ozouf
** Last update Thu Apr 26 17:28:08 2012 harold ozouf
*/

#include	<stdlib.h>
#include	"token.h"
#include	"tree.h"
#include	"add_child.h"
#include	"check_grammar_exec.h"
#include	"check_bloc_exec.h"
#include	"check_pipe.h"

static t_bool	get_next_pipe(t_token *e, t_token **begin, t_token **end)
{
  static t_token	*tmp;
  t_token		*it;

  if (*begin != NULL)
    tmp = *begin;
  if (!tmp || tmp == e)
    return (FALSE);
  it = tmp;
  while (it && it != e && it->id != PIPE)
    it = it->next;
  *end = it;
  *begin = tmp;
  tmp = (it && it->next && it != e) ? (it->next) : (it);
  return (TRUE);
}

static t_bool	there_are_pipe(t_token *b, t_token *e)
{
  t_token	*tmp;

  tmp = b;
  while (tmp && tmp != e)
    {
      if (tmp->id == PIPE)
	return (TRUE);
      tmp = tmp->next;
    }
  return (FALSE);
}

t_bool	check_pipe(t_token *b, t_token *e, t_node **root, int flag)
{
  t_token	*begin;
  t_token	*end;

  if (flag && check_grammar_exec(b, e) != TRUE)
    return (FALSE);
  begin = (flag) ? (b) : (NULL);
  if (there_are_pipe(b, e) == TRUE)
    {
      if (get_next_pipe(e, &begin, &end) == TRUE)
	{
	  if (!end || end == e)
	    check_bloc_exec(begin, end, root);
	  else
	    {
	      add_node(root, PIPE, "|");
	      add_child(root);
	      check_pipe(b, e, &((*root)->child->nd), 0);
	      add_child(root);
	      if (check_bloc_exec(begin, end, &((*root)->child->nd)) != TRUE)
		return (FALSE);
	    }
	}
    }
  else
    if (check_bloc_exec(begin, e, root) != TRUE)
      return (FALSE);
  return (TRUE);
}
