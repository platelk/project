/*
** xml_creat_attr.c for xml in /home/vink/projet/graph/rt/src/xml_src/src
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Sun Jun  3 16:23:44 2012 kevin platel
** Last update Sun Jun  3 16:23:45 2012 kevin platel
*/

#include	<stdlib.h>
#include	<stdio.h>

#include	"xml_attr.h"
#include	"my.h"
#include	"my_strtok.h"
#include	"xml_error.h"

t_attr	*xml_add_attr(t_attr *attr, char *name, char *content)
{
  t_attr	*new;
  char	**tab;

  new = malloc(sizeof(*new));
  if (new == NULL)
    return (NULL);
  new->name = my_strdup(name);
  tab = my_strtok(content, "\"", TOK_DELIM);
  if (tab)
    new->content = my_strdup(tab[0]);
  else
    new->content = NULL;
  new->next = attr;
  my_free_tab(tab);
  return (new);
}

t_attr	*xml_create_attr(char *str, int line)
{
  char	**tab;
  char	*tmp;
  int	i;
  t_attr	*attr;

  i = 0;
  tab = my_strtok(str, "</>", TOK_DELIM);
  if (tab == NULL || tab[0] == NULL)
    return (NULL);
  tmp = my_strdup(tab[0]);
  my_free_tab(tab);
  tab = my_strtok(tmp, "= \t/", TOK_DELIM);
  if (!tab || !tab[0] || !tab[1])
    return (NULL);
  attr = NULL;
  while (tab[++i])
    if (i % 2 == 1)
      attr = xml_add_attr(attr, tab[i], tab[i + 1]);
  if (i % 2 == 0)
    xml_put_synt_error(my_strlen(tmp), str, "Warning : missing value\n", line);
  if (tmp)
    free(tmp);
  my_free_tab(tab);
  return (attr);
}
