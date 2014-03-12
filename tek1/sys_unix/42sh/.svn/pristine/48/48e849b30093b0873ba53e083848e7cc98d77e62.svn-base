/*
** check_cmd.c for check_cmd in /home/ozouf_h//42sh/src/parsing
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Sat Apr 14 23:38:28 2012 harold ozouf
** Last update Thu May 17 20:28:12 2012 harold ozouf
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"token.h"
#include	"tree.h"
#include	"add_child.h"
#include	"check_cmd.h"

t_bool	check_cmd(t_token *b, t_token *e, t_node **root)
{
  t_token	*it;

  it = b;
  if (add_node(root, it->id, it->content) == EXIT_FAILURE)
    return (ERROR);
  it = it->next;
  while (it && it != e)
    {
      if (add_child(root) == EXIT_FAILURE)
	return (ERROR);
      if (add_node(&((*root)->child->nd), it->id, it->content) ==
	  EXIT_FAILURE)
	return (ERROR);
      it = it->next;
    }
  return (TRUE);
}
