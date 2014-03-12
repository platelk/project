/*
** search_attr.c for search_attr in /home/vink/projet/graph/rtv1
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Thu Feb  9 10:00:00 2012 kevin platel
** Last update Thu Feb  9 13:08:40 2012 kevin platel
*/

#include <stdlib.h>
#include "my.h"
#include "attribute.h"

char	*search_attr(t_attr *attr, char *str)
{
  while (attr != NULL)
    {
      if (my_find_str(attr->name, str) > 0)
	return (attr->value);
      attr = attr->next;
    }
  return (NULL);
}
