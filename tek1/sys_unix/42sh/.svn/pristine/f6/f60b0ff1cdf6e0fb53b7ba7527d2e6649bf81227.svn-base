/*
** reconstruct_token.c for reconstruct_token in /home/ozouf_h//42sh/srcs/parser/tokenizer
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Wed Apr 11 15:09:41 2012 harold ozouf
** Last update Fri May 18 15:14:43 2012 harold ozouf
*/

#include	<stdlib.h>
#include	<string.h>

#include	"token.h"
#include	"regroup_token.h"
#include	"my_rev_list.h"
#include	"reconstruct_token.h"
#include	"xsys.h"

f_regroup	*init_ptr_funct_regroup(void)
{
  f_regroup	*tab;

  if ((tab = xmalloc(sizeof(*tab) * 8)) == NULL)
    return (NULL);
  tab[0] = &regroup_par;
  tab[1] = &regroup_quote;
  tab[2] = &regroup_red;
  tab[3] = &regroup_history;
  tab[4] = &regroup_variable;
  tab[5] = &regroup_esp;
  tab[6] = &regroup_inibit;
  tab[7] = NULL;
  return (tab);
}

t_bool	re_add_token(t_token **root, t_token **tok)
{
  t_token	*new;

  if (*tok == NULL)
    {
       return (FALSE);
    }
  if ((*tok)->id != SPACE && (*tok)->id != TAB)
    {
      if ((new = malloc(sizeof(*new))) == NULL)
	return (ERROR);
      new->content = strdup((*tok)->content);
      new->id = (*tok)->id;
      new->spec = (*tok)->spec;
      new->next = *root;
      *root = new;
    }
  *tok = (*tok)->next;
  return (TRUE);
}

void	change_token_exec(t_token **tok)
{
  int		inc;
  t_token	*tmp;

  tmp = *tok;
  inc = 0;
  while (tmp)
    {
      if (inc == 0 && (tmp->id == WORD || tmp->id == ESP))
	{
	  inc = 1;
	  tmp->id = CMD;
	}
      else if (tmp->id != WORD && tmp->id != ESP)
	inc = 0;
      else
	tmp->id = ARG;
      tmp = tmp->next;
    }
}

t_token	*reconstruct_token(t_token *tok)
{
  f_regroup	*re;
  t_token	*new;
  int		res;
  int		i;
  int		done;

  done = 1;
  new = NULL;
  if ((re = init_ptr_funct_regroup()) == NULL)
    return (NULL);
  while (done)
    {
      i = -1;
      res = FALSE;
      done = (tok == NULL) ? (0) : (1);
      while (++i < 7 && res == FALSE && tok)
	res = re[i](&new, &tok);
      if ((res == FALSE && re_add_token(&new, &tok) == FALSE) || res == ERROR)
	done = 0;
    }
  (re) ? free(re) : (re = NULL);
  if (res == ERROR)
    return (NULL);
  my_rev_list(&new);
  return (new);
}
