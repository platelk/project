/*
** check_pipe.c for check_pipe in /home/ozouf_h//42sh/src/parsing
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Wed Apr 18 20:29:32 2012 harold ozouf
** Last update Thu May 17 20:38:15 2012 harold ozouf
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

static t_bool	check_pipe_ext(t_node **root)
{
  if (add_node(root, PIPE, "|") == EXIT_FAILURE)
    return (ERROR);
  if (add_child(root) == EXIT_FAILURE)
    return (ERROR);
  return (TRUE);
}

t_bool	check_pipe(t_token *b, t_token *e, t_node **root, int flag)
{
  t_token	*begin;
  t_token	*end;

  if (flag && check_grammar_exec(b, e) != TRUE)
    return (FALSE);
  begin = (flag) ? (b) : (NULL);
  if (there_are_pipe(b, e) == TRUE && get_next_pipe(e, &begin, &end) == TRUE)
    {
      if (!end || end == e)
	check_bloc_exec(begin, end, root);
      else
	{
	  if (check_pipe_ext(root) == ERROR)
	    return (ERROR);
	  if (check_pipe(b, e, &((*root)->child->nd), 0) != TRUE)
	    return (FALSE);
	  if (add_child(root) == EXIT_FAILURE)
	    return (ERROR);
	  if (check_bloc_exec(begin, end, &((*root)->child->nd)) != TRUE)
	    return (FALSE);
	}
    }
  else
    return ((check_bloc_exec(begin, e, root) != TRUE) ? (FALSE) : (TRUE));
  return (TRUE);
}
