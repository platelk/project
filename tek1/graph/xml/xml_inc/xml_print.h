/*
** xml_print.c for xml in /home/vink/projet/graph/xml/xml_src/src
**
** Made by kevin platel
** Login   <vink@epitech.net>
**
** Started on  Sat May  5 20:42:05 2012 kevin platel
** Last update Sun May  6 14:38:02 2012 kevin platel
*/

#ifndef	__XML_PRINT_H__
#define __XML_PRINT_H__

#include	"xml_token.h"
#include	"xml_tree.h"

void	xml_print_list(t_token *t);
t_xtree *xml_print_tree(t_xtree *t, int i);

#endif
