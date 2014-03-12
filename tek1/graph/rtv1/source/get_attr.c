/*
** get_attr.c for get_attr in /home/vink/projet/graph/rtv1/source
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Wed Feb  8 10:32:53 2012 kevin platel
** Last update Thu Feb  9 15:51:48 2012 kevin platel
*/

#include <stdlib.h>

#include "my.h"
#include "attribute.h"

t_attr	*new_attr(t_attr *attr, char *name, char *value, void *father)
{
  t_attr	*new;

  new = malloc(sizeof(*new));
  if (new == NULL)
    return (new);
  while (attr != NULL && attr->next != NULL)
    attr = attr->next;
  new->name = my_strdup(name);
  new->value = my_strdup(value);
  new->father = father;
  new->prev = attr;
  new->next = NULL;
  if (attr != NULL)
    attr->next = new;
  return (new);
}

t_attr	*get_attr(char *line, void *father)
{
  t_attr	*attr;
  char		**tab;
  int		i;

  i = 1;
  attr = NULL;
  tab = my_strtok(line, "<| \t/=:;,./>\n");
  while (tab != NULL && tab[i] && tab[i + 1])
    {
      attr = new_attr(attr, tab[i], tab[i + 1], father);
      i += 2;
    }
  if (tab != NULL && tab[i] != NULL)
    {
      my_printf("Error : %s have no value !", tab[i]);
      return (NULL);
    }
  while (attr != NULL && attr->prev != NULL)
    attr = attr->prev;
  if (tab)
    freewordtab(tab);
  return (attr);
}
