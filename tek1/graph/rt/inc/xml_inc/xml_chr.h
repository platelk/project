/*
** xml_chr.h for xml in /home/vink/projet/graph/rt/src/moebus
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Sun Jun  3 16:32:49 2012 kevin platel
** Last update Sun Jun  3 16:32:49 2012 kevin platel
*/

#ifndef	__XML_CHR_H__
#define __XML_CHR_H__

#include	"xml_tree.h"

t_xtree		*xml_find_one_node(t_xtree *, char *);
t_xtree		*xml_find_in_tree(t_xtree *, char *, int);
char		*xml_find_attr(t_attr *, char *);

#endif
