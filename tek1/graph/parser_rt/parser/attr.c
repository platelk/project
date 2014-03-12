/*
** attr.c for attr in /home/vink/projet/graph/parser_rt/parser
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Tue Apr 24 16:51:17 2012 kevin platel
** Last update Wed Apr 25 14:29:26 2012 kevin platel
*/

#include	<stdlib.h>
#include	"node.h"
#include	"str.h"
#include	"marker.h"
#include	"xfnt.h"
#include	"finding_elm.h"
#include	"attr.h"
#include	"my.h"
#include	"my_strtok.h"

char	*get_value_of_attr(char *name, t_attr *attr)
{
  if (name == NULL)
    return (NULL);
  while (attr)
    {
      if (my_strcmp(name, attr->name) == 0)
	return (attr->content);
      attr = attr->next;
    }
  return (NULL);
}

char	*find_attr(char *path, t_node *src)
{
  char		*name;
  t_node	*n;
  t_node	*tmp;
  char	**tab;

  tab = my_strtok(path, "=", TOK_DELIM);
  name = NULL;
  n = NULL;
  if (tab && tab[0] && (name = get_next_name(tab)) != NULL)
    {
      tmp = is_in_list(name, src);
      free(name);
      return (find_attr(tab[0], tmp));
    }
  n = src;
  if (tab && tab[0])
    return (get_value_of_attr(tab[1], n->attr));
  return (NULL);
}
