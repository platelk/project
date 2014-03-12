/*
** xml_print.h for xml in /home/vink/projet/graph/rt/src/moebus
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Sun Jun  3 16:33:13 2012 kevin platel
** Last update Sun Jun  3 16:33:14 2012 kevin platel
*/

#ifndef	__XML_PRINT_H__
#define __XML_PRINT_H__

#include	"xml_token.h"
#include	"xml_tree.h"

void	xml_print_list(t_token *);
t_xtree *xml_print_tree(t_xtree *, int);

#endif
