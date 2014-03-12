/*
** xml_parser.c for xml in /home/vink/projet/graph/xml
**
** Made by kevin platel
** Login   <vink@epitech.net>
**
** Started on  Sat May  5 18:53:59 2012 kevin platel
** Last update Mon May  7 12:17:26 2012 kevin platel
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
  xml_print_list(token);
  if ((tree = xml_tree(token)) == NULL)
    return (NULL);
  xml_print_tree(tree, 1);
  return (tree);
}
