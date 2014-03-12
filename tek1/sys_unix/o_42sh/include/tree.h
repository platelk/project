/*
** tree.h for tree in /home/ozouf_h//42sh/src/parsing
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Sat Apr 14 17:52:57 2012 harold ozouf
** Last update Mon Apr 23 11:09:44 2012 kevin platel
*/

#ifndef	__TREE_H__
#define	__TREE_H__

#include	"token.h"

typedef	struct	s_node	t_node;
typedef	struct	s_child	t_child;

struct	s_node
{
  t_t_list	id;
  char		*content;
  t_child	*child;
};

struct	s_child
{
  t_node	*nd;
  t_child	*next;
};

#endif
