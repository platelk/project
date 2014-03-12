/*
** xml_parser.h for xml in /home/vink/projet/graph/rt/src/moebus
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Sun Jun  3 16:33:04 2012 kevin platel
** Last update Sun Jun  3 16:33:05 2012 kevin platel
*/

#ifndef __XML_PARSER_H__
#define __XML_PARSER_H__

#include	"xml_token.h"

t_token		*xml_get_file(char *);
void		*xml_parser(char *);
int		xml_check_token(t_token *);

#endif
