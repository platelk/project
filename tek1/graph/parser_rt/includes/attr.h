/*
** attr.h for attr in /home/vink/projet/graph/parser_rt/includes
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Tue Apr 24 16:39:38 2012 kevin platel
** Last update Wed Apr 25 11:56:56 2012 kevin platel
*/

#ifndef	__ATTR_H__
#define __ATTR_H__

#include	"node.h"

typedef	struct s_attr
{
  char	*name;
  char	*content;
  struct s_node	*father;
  struct s_attr	*next;
} t_attr;

char    *get_value_of_attr(char *name, t_attr *attr);
char    *find_attr(char *path, struct s_node *src);

#endif
