/*
** xml_creat_attr.c for xml in /home/vink/projet/graph/xml
**
** Made by kevin platel
** Login   <vink@epitech.net>
**
** Started on  Mon May  7 11:45:44 2012 kevin platel
** Last update Mon May  7 12:50:57 2012 kevin platel
*/

#include	<stdlib.h>
#include	<stdio.h>

#include	"xml_attr.h"
#include	"my.h"
#include	"my_strtok.h"
t_attr	*xml_add_attr(t_attr *attr, char *name, char *content)
{
  t_attr	*new;

  new = malloc(sizeof(*new));
  if (new == NULL)
    return (NULL);
  new->name = my_strdup(name);
  new->content = my_strdup(content);

  new->next = attr;
  return (new);
}

t_attr	*xml_create_attr(char *str)
{
  char	**tab;
  char	*tmp;
  int	i;
  t_attr	*attr;

  i = 1;
  tab = my_strtok(str, "</>", TOK_DELIM);
  if (tab == NULL || tab[0] == NULL)
    return (NULL);
  tmp = my_strdup(tab[0]);
  my_free_tab(tab);
  tab = my_strtok(tmp, "= \t/", TOK_DELIM);
  if (!tab || !tab[0] || !tab[1])
    return (NULL);
  attr = NULL;
  while (tab[i])
    {
      attr = xml_add_attr(attr, tab[i], tab[i + 1]);
      i += 2;
    }
  if (tmp)
    free(tmp);
  my_free_tab(tab);
  return (attr);
}
