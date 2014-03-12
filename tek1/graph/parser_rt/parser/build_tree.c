/*
** buid_tree.c for build_tree in /home/ozouf_h//projet/rtv1/parser/srcs
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Wed Feb 15 09:55:29 2012 harold ozouf
** Last update Tue May  1 11:26:21 2012 kevin platel
*/

#include	<stdlib.h>
#include	"marker.h"
#include	"node.h"
#include	"str.h"
#include	"aff.h"
#include	"xfnt.h"
#include	"build_tree.h"

char	*get_next_node(char **xml, char **name)
{
  char	*tmp;
  int	size;

  if (get_size_next_marker(*xml) < 0)
    return (NULL);
  *name = malloc(sizeof(char) * (get_size_next_marker(*xml) + 1));
  if (*name == NULL)
    return (NULL);
  if (get_next_marker(xml, name) == -1)
    return (NULL);
   size = get_end_marker(xml, *name);
  if (size == -1)
    return (NULL);
  tmp = my_strcut(*xml, size);
  return (tmp);
}

int	build_tree(t_node **root)
{
  char		*name;
  char		*tmp;

  if ((*root) == NULL)
    return (1);
  if ((tmp = get_next_node(&((*root)->content), &name)) != NULL)
    {
      add_node(root, name, tmp);
      delete_marker(&((*root)->content), name);
      build_tree(&((*root)->elm->child));
      if (tmp)
	free(tmp);
    }
  else
    build_tree(&((*root)->prev));
  free(name);
  return (0);
}
