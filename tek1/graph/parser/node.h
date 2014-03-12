/*
** n_tree.h for n_tree in /home/ozouf_h//projet/rtv1/parser/srcs
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Tue Feb 14 10:40:54 2012 harold ozouf
** Last update Wed Apr 25 11:53:48 2012 kevin platel
*/

#ifndef		N_TREE_H__
# define	N_TREE_H__

#include	"attr.h"

typedef	struct s_child	t_child;
typedef	struct s_node	t_node;

struct	s_child
{
  t_node       	*child;
  t_child	*next;
};

struct	s_node
{
  char	       	*name;
  char		*content;
  t_child	*elm;
  t_attr	*attr;
  t_node       	*prev;
};

void	add_node(t_node **root, char *name, char *content);

#endif
