/*
** my_strdup.c for my_strdup.c in /home/leprov_a//bdd/source/my
**
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
**
** Started on  Sat Dec 17 17:12:38 2011 alexis leprovost
** Last update Wed May  9 12:36:36 2012 alexis leprovost
*/

#include	<stdlib.h>

#include	"my.h"

char	*my_strdup(char *str)
{
  char *strdup;
  int i;

  i = -1;
  if (str == NULL ||
      (strdup = malloc(sizeof(*strdup) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  while (str[++i])
    strdup[i] = str[i];
  strdup[i] = '\0';
  return (strdup);
}
