/*
** my_strdup.c for my_strdup.c in /home/leprov_a//bdd/source/my
**
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
**
** Started on  Sat Dec 17 17:12:38 2011 alexis leprovost
** Last update Mon Apr  2 09:23:21 2012 alexis leprovost
*/

#include	<stdlib.h>

#include	"my.h"

char	*my_strdup(char *expr)
{
  char *str;
  int len;
  int i;

  i = 0;
  len = my_strlen(expr) + 1;
  str = malloc(len * sizeof(*str));
  if (str == NULL)
    {
      my_puterror("Error: Could not alloc.\n");
      return (NULL);
    }
  while (expr[i])
    {
      str[i] = expr[i];
      i++;
    }
  str[i] = '\0';
  return (str);
}
