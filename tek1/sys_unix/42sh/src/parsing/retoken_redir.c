/*
** retoken_redir.c for retoken_redir in /home/ozouf_h//42sh/srcs/parser/tokenizer
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Wed Apr 11 13:11:51 2012 harold ozouf
** Last update Fri May 18 15:25:23 2012 harold ozouf
*/

#include	<string.h>
#include	<stdlib.h>
#include	"token.h"
#include	"concat_token.h"
#include	"puterror.h"
#include	"retoken_redir_ext.h"
#include	"regroup_token.h"

t_bool	regroup_red(t_token **r, t_token **o)
{
  t_token	*tmp;
  t_token	*n;
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
	  if (!(n = cat_token(b, (*o)->next, (b->id == S_RED_RIGHT) ?
			      (S_RED_RIGHT_ERR) : (D_RED_RIGHT_ERR), NONE)))
	      return (ERROR);
	  n->next = *r;
	  *r = n;
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
      regroup_quote_ext(o, b);
      if (((*o)->next) == NULL)
	return (puterror(UNMATCH, b->content));
      if ((new = cat_token(b->next, *o, WORD, b->spec)) == NULL)
	return (FALSE);
      new->next = *r;
      *r = new;
      *o = (*o)->next->next;
      return (TRUE);
    }
  *o = tmp;
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
      if ((*o)->next && ((*o)->next->id == WORD || (*o)->next->id == EXCLA ||
			 (*o)->next->id == DOLLARS))
	{
	  if ((new = cat_token(*o, (*o)->next, WORD, HISTORY)) == NULL)
	    return (ERROR);
	  new->next = *r;
	  *r = new;
	  *o = (*o)->next->next;
	  return (TRUE);
	}
      if (add_token(r, WORD, (*o)->content, NONE) == EXIT_FAILURE)
	return (ERROR);
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
	  if ((new = cat_token(*o, (*o)->next, WORD, VARIABLES)) == NULL)
	    return (ERROR);
	  new->next = *r;
	  *r = new;
	  *o = (*o)->next->next;
	  return (TRUE);
	}
      if (add_token(r, WORD, (*o)->content, NONE) == EXIT_FAILURE)
	return (ERROR);
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
  int		res;
  char		c[2];

  tmp = *o;
  while (*o && ((*o)->id == SPACE || (*o)->id == TAB))
    *o = (*o)->next;
  if (*o && (*o)->id == INIBIT)
    {
      c[0] = (*o)->content[1];
      c[1] = '\0';
      (*o)->content = strdup(c);
      if ((res = regroup_inibit_ext(o, &new, r)) != FALSE)
	return ((res == TRUE) ? (TRUE) : (ERROR));
      if (add_token(r, WORD, (*o)->content, NONE) == EXIT_FAILURE)
	return (ERROR);
      *o = (*o)->next;
      return (TRUE);
    }
  *o = tmp;
  return (FALSE);
}
