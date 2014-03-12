/*
** check_bloc_exec.c for check_bloc_exec in /home/ozouf_h//42sh/src/parsing
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Sat Apr 14 22:51:05 2012 harold ozouf
** Last update Fri May 18 19:02:05 2012 harold ozouf
*/

#include	<stdlib.h>
#include	"tree.h"
#include	"token.h"
#include	"puterror.h"
#include	"add_child.h"
#include	"check_cmd.h"
#include	"check_grammar_exec.h"
#include	"my_rev_node.h"
#include	"check_bloc_exec_ext.h"
#include	"check_bloc_exec.h"

static t_t_list	get_exec(t_token *tok, t_token **file,
			 t_token **b, t_token **e)
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

static t_bool	check_red(t_token *b, t_token *end, t_node **root)
{
  t_token	*begin;
  t_token	*file;
  int		type;

  begin = NULL;
  if ((type = b->id) != WORD && b->next)
    get_pre_exec(b->next, &file, &begin, &end);
  else
    type = get_exec(b, &file, &begin, &end);
  if (add_node(root, type, NULL) == EXIT_FAILURE)
    return (ERROR);
  if (add_child(root) == EXIT_FAILURE)
    return (ERROR);
  if (!file)
    return (puterror(MISSING_N, NULL));
  if (add_node(&((*root)->child->nd), CMD, file->content) == EXIT_FAILURE)
    return (ERROR);
  if (add_child(root) == EXIT_FAILURE)
    return (ERROR);
   if (begin && add_node(&((*root)->child->nd), CMD, begin->content)
       == EXIT_FAILURE)
    return (ERROR);
  if (check_red_ext(&begin, root, end) != TRUE)
    return (ERROR);
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
  if (!tmp ||  !tmp->next)
    return (puterror(MISSING_N, NULL));
  tok = tmp->next;
  if (add_node(r, tmp->id, tmp->content) == EXIT_FAILURE)
    return (ERROR);
  if (add_child(r) == EXIT_FAILURE)
    return (ERROR);
  if (add_node(&((*r)->child->nd), CMD, tmp->next->content) == EXIT_FAILURE)
    return (ERROR);
  if (get_spe_red_ext(r, &tmp, e) == FALSE)
    return (ERROR);
  if (add_child(r) == EXIT_FAILURE)
    return (ERROR);
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
      if (add_node(root, CMD, b->content) == EXIT_FAILURE)
	return (ERROR);
      if (check_bloc_exec_ext(root, &b, e) == ERROR)
	return (ERROR);
    }
  return (TRUE);
}
