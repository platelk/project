/*
** xml_tree.h for xml in /home/vink/projet/graph/xml/xml_inc
**
** Made by kevin platel
** Login   <vink@epitech.net>
**
** Started on  Sun May  6 11:15:30 2012 kevin platel
** Last update Thu May 24 17:44:40 2012 ronan guiho
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

t_xtree	*xml_tree(t_token *t);

#endif
