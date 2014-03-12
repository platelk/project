/*
** xml_tree.h for xml in /home/vink/projet/graph/rt/src/moebus
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Sun Jun  3 16:33:31 2012 kevin platel
** Last update Sun Jun  3 16:33:32 2012 kevin platel
*/

#ifndef __XML_TREE_H__
#define __XML_TREE_H__

#include	"global.h"
#include	"xml_token.h"
#include	"xml_attr.h"

struct s_xtree
{
  char	*name;
  char	*content;
  t_attr	*attr;

  struct s_xtree	*next;
  struct s_xtree	*prev;
  struct s_xtree	*sun;
  struct s_xtree	*father;
};

t_xtree	*xml_tree(t_token *);

#endif
