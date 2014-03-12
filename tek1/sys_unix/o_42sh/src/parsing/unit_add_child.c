/*
** unit_add_child.c for unit_child.c in /home/ozouf_h//42sh/src/parsing
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Mon Apr 16 13:51:58 2012 harold ozouf
** Last update Mon Apr 16 15:31:27 2012 harold ozouf
*/

#include	<string.h>
#include	"token.h"
#include	"tree.h"
#include	"add_child.h"

int	main(void)
{
  t_node	*nd;

  add_node(&nd, WORD, "coucou");
  add_child(&nd);
  if (nd)
    if (strcmp("coucou", nd->content) == 0)
      if (nd->child)
	return (0);
  return (1);
}
