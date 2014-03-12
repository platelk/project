/*
** retoken_redir_par.c for retoken_red_par in /home/ozouf_h//42sh/src/parsing
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Tue May  8 16:55:50 2012 harold ozouf
** Last update Fri May 18 14:47:51 2012 harold ozouf
*/

#include	<stdlib.h>
#include	"token.h"
#include	"concat_token.h"
#include	"puterror.h"
#include	"regroup_token.h"

t_bool	regroup_esp(t_token **r, t_token **o)
{
  while (*o && ((*o)->id == SPACE || (*o)->id == TAB))
    *o = (*o)->next;
  if (*o && (*o)->id == ESP)
    {
      *r = *r;
      *o = (*o)->next;
    }
  return (FALSE);
}

static	t_bool	check_par(t_token **root, t_token **old,
			  t_token *b, t_token *bef)
{
  t_token	*new;
  t_token	*tmp;

  if (bef->id == WORD)
    return (puterror(BAD_PLA, NULL));
  tmp = (*old)->next->next;
  while (tmp && (tmp->id == SPACE || tmp->id == TAB))
    tmp = tmp->next;
  if (tmp && tmp->id == WORD)
    return (puterror(BAD_PLA, NULL));
  if ((new = cat_token(b->next, *old, WORD, PAR)) == NULL)
    return (ERROR);
  new->next = *root;
  *root = new;
  *old = (*old)->next->next;
  return (TRUE);
}

t_bool	regroup_par(t_token **root, t_token **old)
{
  t_token	*tmp;
  t_token	*b;
  t_token      	*ret;

  tmp = *old;
  ret = *old;
  while (*old && ((*old)->id == SPACE || (*old)->id == TAB))
    {
      ret = *old;
      *old = (*old)->next;
    }
  if (*old && (*old)->spec == E_PAR)
    return (puterror(TOO_MANY, (*old)->content));
  if (*old && (*old)->spec == S_PAR)
    {
      b = *old;
      while ((*old)->next && (*old)->next->spec != E_PAR)
	*old = (*old)->next;
      if (!((*old)->next))
	return (puterror(TOO_MANY, b->content));
      return ((check_par(root, old, b, ret) != TRUE) ? (ERROR) : (TRUE));
    }
  *old = tmp;
  return (FALSE);
}

