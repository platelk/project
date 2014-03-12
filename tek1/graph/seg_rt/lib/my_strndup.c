/*
** my_strndup.c for pi in /home/leprov_a//depot/colle10/lib
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Thu Apr 19 14:40:56 2012 alexis leprovost
** Last update Mon Apr 30 16:17:00 2012 alexis leprovost
*/

#include	<stdlib.h>

#include	"my.h"

char	*my_strndup(char *str, int size)
{
  char	*strdup;
  int	i;

  i = -1;
  if ((strdup = malloc(sizeof(*strdup) * (size + 1))) == NULL ||
      str == NULL)
    return (NULL);
  while (str[++i] && i < size)
    strdup[i] = str[i];
  strdup[i] = '\0';
  return (strdup);
}
