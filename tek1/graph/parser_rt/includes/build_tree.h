/*
** build_tree.h for build_tree in /home/ozouf_h//projet/rtv1/parser/srcs
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Wed Feb 15 10:02:37 2012 harold ozouf
** Last update Wed Feb 15 14:14:32 2012 harold ozouf
*/

#ifndef		BUILD_TREE_H__
# define	BUILD_TREE_H__

#include	"node.h"

char	*get_next_node(char **xml, char **name);
int	build_tree(t_node **root);

#endif
