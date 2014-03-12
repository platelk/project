/*
** xml_chr.h for xml in /home/vink/projet/graph/xml/xml_src/src
**
** Made by kevin platel
** Login   <vink@epitech.net>
**
** Started on  Mon May  7 11:38:22 2012 kevin platel
** Last update Tue May 29 20:18:23 2012 zoe phalippou
*/

#ifndef	__XML_CHR_H__
#define __XML_CHR_H__

#include	"xml_tree.h"

t_xtree		*xml_find_one_node(t_xtree *, char *);
t_xtree		*xml_find_in_tree(t_xtree *, char *);
char		*xml_find_attr(t_attr *, char *);

#endif
