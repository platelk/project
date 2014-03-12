/*
** xml_tree.c for xml in /home/vink/projet/graph/xml/xml_src/src
**
** Made by kevin platel
** Login   <vink@epitech.net>
**
** Started on  Sun May  6 11:19:51 2012 kevin platel
** Last update Tue May  8 11:41:16 2012 kevin platel
*/

#include	<stdlib.h>

#include	"xml_attr.h"
#include	"xml_tree.h"
#include	"xml_token.h"
#include	"my.h"
#include	"my_strtok.h"

t_xtree	*xml_add_node_tree(t_xtree **tree, char *name, char *content)
{
  t_xtree	*new;
  char	**tab;

  new = malloc(sizeof(*new));
  if (new == NULL)
    return (NULL);
  new->name = my_strdup(name);
  tab = my_strtok(content, "<>", TOK_DELIM);
  if (tab && tab[0])
    new->content = my_strdup(tab[1]);
  else
    new->content = NULL;
  new->attr = xml_create_attr(content);
  new->prev = *tree;
  if (*tree)
    (*tree)->next = new;
  new->next = NULL;
  new->sun = NULL;
  my_free_tab(tab);
  return (new);
}

t_xtree	*xml_create_tree(t_xtree *tree, t_token **t, char *name)
{
  while (t && *t && (*t)->token != TK_END_NODE
	 && my_strcmp((*t)->name, name) != 0)
    {
      if ((*t)->token == TK_OPEN_NODE)
	{
	  tree = xml_add_node_tree(&tree, (*t)->name, (*t)->content);
	  (*t) = (*t)->next;
	  tree->sun = xml_create_tree(NULL, t, tree->name);
	}
      else
	{
	  tree = xml_add_node_tree(&tree, (*t)->name, (*t)->content);
	  if (t && *t)
	    *t = (*t)->next;
	}
    }
  while (t && *t && (*t)->token == TK_END_NODE)
    (*t) = (*t)->next;
  while (tree && tree->prev)
    tree = tree->prev;
  return (tree);
}

t_xtree	*xml_tree(t_token *t)
{
  t_xtree	*tree;
  t_xtree	*tmp;

  tree = NULL;
  tree = xml_add_node_tree(&tree, "root", NULL);
  tmp = tree;
  tmp->sun = xml_create_tree(NULL, &t, "root");
  return (tmp);
}
