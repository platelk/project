/*
** my_strcat.c for my in /home/leprov_a//bdd/my
**
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
**
** Started on  Mon Apr 30 16:18:57 2012 alexis leprovost
** Last update Fri Jan 11 10:07:48 2013 kevin platel
*/

#include	<stdlib.h>
#include	"my.h"

char	*my_strmcat(char *dest, char *src)
{
  int	i;
  int	j;
  char	*new;

  j = 0;
  i = 0;
  if (!src)
    return (NULL);
  new = malloc((my_strlen(dest) + my_strlen(src) + 1) * sizeof(*new));
  if (new == NULL)
    return (NULL);
  while (dest && dest[j])
    {
      new[j] = dest[j];
      j++;
    }
  while (src[i])
    new[j++] = src[i++];
  new[j] = 0;
  if (dest)
    free(dest);
  return (new);
}
