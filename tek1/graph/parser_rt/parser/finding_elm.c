/*
** finding_elm.c for finding_elm in /home/ozouf_h//projet/rtv1/parser/srcs
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Wed Feb 15 20:28:31 2012 harold ozouf
** Last update Tue May  1 11:18:41 2012 kevin platel
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

char	*get_next_name(char **path)
{
  char	*name;
  int	i;

  i = -1;
  name = NULL;
  if ((**path) == '\0')
    return (NULL);
  name = xmalloc(sizeof(*name) * (MARKER_LEN + 1));
  while (**path != '/' && (**path) != '\0')
    {
      name[++i] = **path;
      (*path)++;
    }
  if (**path == '/')
    (*path)++;
  name[++i] = '\0';
  return (name);
}

t_node	*is_in_list(char *name, t_node *tmp)
{
  t_child	*current;
  t_child	*ret;

  current = NULL;
  ret = NULL;
  if (tmp == NULL)
    return (NULL);
  current = tmp->elm;
  while (tmp && tmp->elm != NULL && my_strcmp(name, tmp->elm->child->name) != 0)
    tmp->elm = tmp->elm->next;
  ret = tmp->elm;
  if (tmp && tmp->elm == NULL)
    xerror(name, "do not exist");
  tmp->elm = current;
  return (ret->child);
}

t_node	*get_node(char *path, t_node *src)
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
      return (get_node(tab[0], tmp));
    }
  n = src;
  return (n);
}

char	*get_value(t_node *node)
{
  if (node != NULL && node->content != NULL)
    return (node->content);
  xexit("Internal Error");
  return (NULL);
}
