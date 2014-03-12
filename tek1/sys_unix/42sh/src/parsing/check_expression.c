/*
** check_expression.c for check_expression in /home/ozouf_h//42sh/src/parsing
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Sat Apr 14 19:20:49 2012 harold ozouf
** Last update Fri May 18 17:25:29 2012 harold ozouf
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"token.h"
#include	"tree.h"
#include	"add_child.h"
#include	"check_log.h"
#include	"my_rev_node.h"
#include	"check_expression.h"

static int	get_next_pv(t_token **begin, t_token **end)
{
  static t_token	*tmp;
  t_token		*iter;

  if (*begin != NULL)
    tmp = *begin;
  if (tmp == NULL)
    return (0);
  iter = tmp;
  while (iter && iter->id != PV)
    iter = iter->next;
  *end = iter;
  *begin = tmp;
  tmp = (iter) ? (iter->next) : (iter);
  return (1);
}

t_bool	check_expression(t_token *tok, t_node **root)
{
  int		res;
  t_token	*begin;
  t_token	*end;

  begin = tok;
  if (add_node(root, PV, ";") == EXIT_FAILURE)
    return (FALSE);
  while ((res = get_next_pv(&begin, &end)))
    {
      if (begin != end)
      	{
	  if (add_child(root) == EXIT_FAILURE)
	    return (FALSE);
      	  if (check_log(begin, end, &((*root)->child->nd), 1) != TRUE)
	    return (FALSE);
	}
      begin = NULL;
    }
  my_rev_node(&((*root)->child));
  return (TRUE);
}
