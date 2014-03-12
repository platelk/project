/*
** check_bloc_exec_ext.c for c_b_e_e in /home/ozouf_h//42sh/src/parsing
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Fri May 18 15:15:16 2012 harold ozouf
** Last update Sat May 19 16:31:16 2012 harold ozouf
*/

#include	<stdlib.h>
#include	"tree.h"
#include	"token.h"
#include	"my_rev_node.h"
#include	"add_child.h"
#include	"check_bloc_exec_ext.h"

t_bool	check_bloc_exec_ext(t_node **root, t_token **b, t_token *e)
{
  *b = (*b)->next;
  while (*b && *b != e)
    {
      if (add_child(root) == EXIT_FAILURE)
	return (ERROR);
      if (add_node(&((*root)->child->nd), ARG, (*b)->content) == EXIT_FAILURE)
	return (ERROR);
      *b = (*b)->next;
    }
  my_rev_node(&((*root)->child));
  return (TRUE);
}

t_bool	get_spe_red_ext(t_node **r, t_token **tmp, t_token *e)
{
  *tmp = (*tmp)->next->next;
  while (*tmp && *tmp != e)
    {
      if (add_child(&((*r)->child->nd)) == EXIT_FAILURE)
	return (FALSE);
      if (add_node(&((*r)->child->nd->child->nd), ARG,
		   (*tmp)->content) == EXIT_FAILURE)
	return (FALSE);
      *tmp = (*tmp)->next;
    }
  return (TRUE);
}

t_bool	check_red_ext(t_token **begin, t_node **root, t_token *end)
{
  if (*begin)
   {
      *begin = (*begin)->next;
      while (*begin && *begin != end)
	{
	  if (add_child(&((*root)->child->nd)) == EXIT_FAILURE)
	    return (FALSE);
	  if (add_node(&((*root)->child->nd->child->nd), ARG,
		       (*begin)->content) == EXIT_FAILURE)
	    return (FALSE);
	  *begin = (*begin)->next;
	}
      my_rev_node(&((*root)->child->nd->child));
   }
  return (TRUE);
}
