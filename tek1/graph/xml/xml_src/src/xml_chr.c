/*
** xml_chr.c for xml in /home/vink/projet/graph/xml/xml_src/src
**
** Made by kevin platel
** Login   <vink@epitech.net>
**
** Started on  Mon May  7 11:37:29 2012 kevin platel
** Last update Mon May  7 12:25:49 2012 kevin platel
*/

#include	<stdlib.h>

#include	"xml_tree.h"
#include	"my_strtok.h"
#include	"my.h"

char	*xml_find_attr(t_attr *attr, char *name)
{
  while (attr)
    {
      if (my_strcmp(attr->name, name) == 0)
	return (attr->content);
      attr = attr->next;
    }
  return (NULL);
}

t_xtree	*xml_find_one_node(t_xtree *tree, char *name)
{
  while (tree)
    {
      if (my_strcmp(tree->name, name) == 0)
	return (tree);
      tree = tree->next;
    }
  return (NULL);
}

t_xtree	*xml_find_in_tree(t_xtree *tree, char *find)
{
  char	**tab;
  int	i;

  tab = my_strtok(find, "/ \n\t", TOK_DELIM);
  i = 0;
  while (tree && tab && tab[i])
    {
      tree = xml_find_one_node(tree->sun, tab[i]);
      i++;
    }
  my_free_tab(tab);
  return (tree);
}
