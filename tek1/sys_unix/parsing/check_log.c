/*
** check_log.c for check_log in /home/ozouf_h//42sh/src/parsing
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Sat Apr 14 20:55:24 2012 harold ozouf
** Last update Tue Apr 17 18:35:59 2012 harold ozouf
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"tree.h"
#include	"puterror.h"
#include	"token.h"
#include	"add_child.h"
#include	"check_bloc_exec.h"
#include	"check_log.h"

static t_t_list	get_next_log(t_token *e, t_token **begin, t_token **end)
{
  static t_token	*tmp;
  t_token		*it;

  if (*begin != NULL)
    tmp = *begin;
  if (tmp == e)
    return (UNKNOW);
  it = tmp;
  while (it && it != e && it->id != AND && it->id != OR)
    it = it->next;
  *end = it;
  *begin = tmp;
  tmp = (it != e) ? (it->next) : (it);
  return (!it || (it->id != AND && it->id != OR) ? (UNKNOW) : (it->id));
}

static t_bool	check_grammar_log(t_token *begin, t_token *end)
{
  t_token	*tmp;
  int		log;

  log = 1;
  tmp = begin;
  while (tmp && tmp != end)
    {
      if (log && (tmp->id == OR || tmp->id == AND))
	return (puterror(NULL_CMD, NULL));
      else if (!log && (tmp->id == OR || tmp->id == AND))
	log = 1;
      else
	log = 0;
      tmp = tmp->next;
    }
  if (log)
    return (puterror(NULL_CMD, NULL));
  return (TRUE);
}

t_bool	check_log(t_token *b, t_token *e, t_node **root, int flag)
{
  t_t_list	res;
  t_token	*begin;
  t_token	*end;

  if (check_grammar_log(b, e) != TRUE)
    return (FALSE);
  begin = (flag) ? (b) : (NULL);
  res = get_next_log(e, &begin, &end);
  if (res != UNKNOW)
    {
      add_node(root, res, NULL);
      add_child(root);
      check_log(b, e, &((*root)->child->nd), 0);
      add_child(root);
      if (check_bloc_exec(begin, end, &((*root)->child->nd), 1) != TRUE)
	return (FALSE);
    }
  else
    if (check_bloc_exec(begin, end, root, 1) != TRUE)
      return (FALSE);
  return (TRUE);
}
