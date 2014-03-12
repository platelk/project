/*
** xml_parser.c for xml in /home/vink/projet/graph/xml
**
** Made by kevin platel
** Login   <vink@epitech.net>
**
** Started on  Sat May  5 18:53:59 2012 kevin platel
** Last update Thu May 24 17:17:25 2012 ronan guiho
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
  //  xml_print_tree(tree, 1);
  return (tree);
}
