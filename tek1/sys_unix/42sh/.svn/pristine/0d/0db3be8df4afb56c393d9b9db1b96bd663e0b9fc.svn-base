/*
** multired.c for multi in /home/ozouf_h//42sh/src/parsing
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Tue May  8 19:29:07 2012 harold ozouf
** Last update Tue May  8 19:30:37 2012 harold ozouf
*/

#include	"token.h"
#include	"check_bloc_exec.h"

t_bool	there_are_two_red(t_token *b, t_token *e)
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

void	get_pre_exec(t_token *tok, t_token **file,
			     t_token **b, t_token **e)
{
  t_token	*end;

  end = *e;
  *file = tok;
  *b = tok->next;
  while (tok && tok != end)
    tok = tok->next;
  *e = tok;
}
