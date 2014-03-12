/*
** xml_tree.h for xml in /home/vink/projet/graph/xml/xml_inc
**
** Made by kevin platel
** Login   <vink@epitech.net>
**
** Started on  Sun May  6 11:15:30 2012 kevin platel
** Last update Tue May  8 11:40:54 2012 kevin platel
*/

#ifndef __XML_TREE_H__
#define __XML_TREE_H__

#include	"xml_token.h"
#include	"xml_attr.h"

typedef struct s_xtree
{
  char	*name;
  char	*content;
  t_attr	*attr;
  int	line;

  struct s_xtree	*next;
  struct s_xtree	*prev;
  struct s_xtree	*sun;
  struct s_xtree	*father;
} t_xtree;

t_xtree	*xml_tree(t_token *t);

#endif
