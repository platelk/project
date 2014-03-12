/*
** xml_parser.c for xml in /home/vink/projet/graph/rt/src/xml_src/src
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Sun Jun  3 16:24:20 2012 kevin platel
** Last update Sun Jun  3 16:24:22 2012 kevin platel
*/

#include	<stdlib.h>

#include	"xml_parser.h"
#include	"xml_print.h"

void	*xml_parser(char *path)
{
  t_token	*token;
  t_xtree	*tree;

  token = xml_get_file(path);
  if (token == NULL)
    return (NULL);
  if (xml_check_token(token) == EXIT_FAILURE)
    return (NULL);
  if ((tree = xml_tree(token)) == NULL)
    return (NULL);
  return (tree);
}
