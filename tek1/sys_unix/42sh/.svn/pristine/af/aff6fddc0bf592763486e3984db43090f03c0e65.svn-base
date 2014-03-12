/*
** my_strdup.c for my_strdup.c in /home/leprov_a//bdd/source/my
**
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
**
** Started on  Sat Dec 17 17:12:38 2011 alexis leprovost
** Last update Tue Apr 17 12:41:26 2012 alexis leprovost
*/

#include	<stdlib.h>

#include	"xsys.h"
#include	"my.h"

char	*my_strdup(char *str)
{
  char *strdup;
  int i;

  i = -1;
  if ((strdup = xmalloc(sizeof(*strdup) * (my_strlen(str) + 1))) == NULL ||
      !str)
    return (NULL);
  while (str[++i])
    strdup[i] = str[i];
  return (strdup);
}
