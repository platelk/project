/*
** retoken_redir_ext.c for r_t_r_e in /home/ozouf_h//42sh/src/parsing
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Fri May 18 15:21:56 2012 harold ozouf
** Last update Fri May 18 15:24:26 2012 harold ozouf
*/

#include	<stdlib.h>
#include	"token.h"
#include	"concat_token.h"
#include	"retoken_redir_ext.h"

t_bool	regroup_inibit_ext(t_token **o, t_token **new, t_token **r)
{
  if ((*o)->next && (*o)->next->id == WORD)
    {
      if ((*new = cat_token(*o, (*o)->next, WORD, NONE)) == NULL)
	return (ERROR);
      (*new)->next = *r;
      *r = *new;
      *o = (*o)->next->next;
      return (TRUE);
    }
  return (FALSE);
}

void	regroup_quote_ext(t_token **o, t_token *b)
{
  while ((*o)->next && (*o)->next->spec != b->spec)
    {
      if ((*o)->next->id == INIBIT)
	transform_inib((*o)->next);
      *o = (*o)->next;
    }
}
