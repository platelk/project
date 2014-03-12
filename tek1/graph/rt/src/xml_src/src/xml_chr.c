/*
** xml_chr.c for xml in /home/vink/projet/graph/rt/src/xml_src/src
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Sun Jun  3 16:23:21 2012 kevin platel
** Last update Sun Jun  3 16:23:22 2012 kevin platel
*/

#include	<stdlib.h>
#include	<stdio.h>

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

t_xtree	*xml_find_in_tree(t_xtree *tree, char *find, int i)
{
  char	**tab;
  t_xtree	*tmp[0];

  tab = my_strtok(find, "/ \n\t", TOK_DELIM);
  i = -1;
  tmp[0] = NULL;
  while (tree && tab && tab[++i])
    {
      (tmp[0] == NULL) ? (tmp[0] = tree) : (tmp[0] = tmp[0]);
      tmp[1] = tmp[0];
      tmp[0] = NULL;
      while (tmp[1] && !tmp[0])
	{
	  if (!tab[i + 1] && my_strcmp(tmp[1]->name, tab[i]) == 0)
	    {
	      my_free_tab(tab);
	      return (tmp[1]);
	    }
	  tmp[0] = xml_find_one_node(tmp[1]->sun, tab[i]);
	  (tmp[0] == NULL) ? tmp[1] = tmp[1]->next : (tmp[0] = tmp[0]);
	}
    }
  my_free_tab(tab);
  return (tmp[0]);
}
