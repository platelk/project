/*
** retoken_redir.c for retoken_redir in /home/ozouf_h//42sh/srcs/parser/tokenizer
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Wed Apr 11 13:11:51 2012 harold ozouf
** Last update Tue Apr 17 12:16:51 2012 harold ozouf
*/

#include	<string.h>
#include	<stdlib.h>
#include	"token.h"
#include	"concat_token.h"
#include	"puterror.h"
#include	"regroup_token.h"

t_bool	regroup_red(t_token **r, t_token **o)
{
  t_token	*tmp;
  t_token	*new;
  t_token	*b;

  tmp = *o;
  while (*o && ((*o)->id == SPACE || (*o)->id == TAB))
    *o = (*o)->next;
  if (*o && ((*o)->id == S_RED_RIGHT || (*o)->id == D_RED_RIGHT))
    {
      b = *o;
      while ((*o)->next && ((*o)->next->id == SPACE || (*o)->next->id == TAB))
	*o = (*o)->next;
      if ((*o)->next && (*o)->next->id == ESP)
	{
	  new = concat_token(b, (*o)->next, (b->id == S_RED_RIGHT) ?
			     (S_RED_RIGHT_ERR) : (D_RED_RIGHT_ERR), NONE);
	  new->next = *r;
	  *r = new;
	  *o = (*o)->next->next;
	  return (TRUE);
	}
    }
  *o = tmp;
  return (FALSE);
}

t_bool	regroup_quote(t_token **r, t_token **o)
{
  t_token	*tmp;
  t_token	*new;
  t_token	*b;

  tmp = *o;
  while (*o && ((*o)->id == SPACE || (*o)->id == TAB))
    *o = (*o)->next;
  if (*o && (*o)->id == QUOTE)
    {
      b = *o;
      while ((*o)->next && (*o)->next->spec != b->spec)
	*o = (*o)->next;
      if (((*o)->next) == NULL)
	return (puterror(UNMATCH, b->content));
      new = concat_token(b->next, *o, WORD, b->spec);
      new->next = *r;
      *r = new;
      *o = (*o)->next->next;
      return (TRUE);
    }
  *o = tmp;
  return (FALSE);
}

t_bool	regroup_par(t_token **root, t_token **old)
{
  t_token	*tmp;
  t_token	*new;
  t_token	*b;

  tmp = *old;
  while (*old && ((*old)->id == SPACE || (*old)->id == TAB))
    *old = (*old)->next;
  if (*old && (*old)->spec == E_PAR)
    return (puterror(TOO_MANY, (*old)->content));
  if (*old && (*old)->spec == S_PAR)
    {
      b = *old;
      while ((*old)->next && (*old)->next->spec != E_PAR)
	*old = (*old)->next;
      if (!((*old)->next))
	  return (puterror(TOO_MANY, b->content));
      new = concat_token(b->next, *old, WORD, PAR);
      new->next = *root;
      *root = new;
      *old = (*old)->next->next;
      return (TRUE);
    }
  *old = tmp;
  return (FALSE);
}

t_bool	regroup_history(t_token **r, t_token **o)
{
  t_token	*tmp;
  t_token	*new;

  tmp = *o;
  while (*o && ((*o)->id == SPACE || (*o)->id == TAB))
    *o = (*o)->next;
  if (*o && ((*o)->id == EXCLA))
    {
      if ((*o)->next && ((*o)->next->id == WORD || (*o)->next->id == EXCLA))
	{
	  new = concat_token(*o, (*o)->next, WORD, HISTORY);
	  new->next = *r;
	  *r = new;
	  *o = (*o)->next->next;
	  return (TRUE);
	}
      add_token(r, WORD, (*o)->content, NONE);
      *o = (*o)->next;
      return (TRUE);
    }
  *o = tmp;
  return (FALSE);
}

t_bool	regroup_variable(t_token **r, t_token **o)
{
  t_token	*tmp;
  t_token	*new;

  tmp = *o;
  while (*o && ((*o)->id == SPACE || (*o)->id == TAB))
    *o = (*o)->next;
  if (*o && ((*o)->id == DOLLARS))
    {
      if ((*o)->next && ((*o)->next->id != TAB || (*o)->id != SPACE))
	{
	  new = concat_token(*o, (*o)->next, WORD, VARIABLES);
	  new->next = *r;
	  *r = new;
	  *o = (*o)->next->next;
	  return (TRUE);
	}
      add_token(r, WORD, (*o)->content, NONE);
      *o = (*o)->next;
      return (TRUE);
    }
  *o = tmp;
  return (FALSE);
}

t_bool	regroup_inibit(t_token **r, t_token **o)
{
  t_token	*tmp;
  t_token	*new;

  tmp = *o;
  while (*o && ((*o)->id == SPACE || (*o)->id == TAB))
    *o = (*o)->next;
  if (*o && (*o)->id == INIBIT)
    {
      if ((*o)->next && (*o)->next->id == WORD)
	{
	  new = concat_token(*o, (*o)->next, WORD, NONE);
	  new->next = *r;
	  *r = new;
	  *o = (*o)->next->next;
	  return (TRUE);
	}
      add_token(r, WORD, (*o)->content, NONE);
      *o = (*o)->next;
      return (TRUE);
    }
  *o = tmp;
  return (FALSE);
}
