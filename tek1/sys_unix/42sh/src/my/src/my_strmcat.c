/*
** my_strmcat.c for test in /home/vink/projet/sys_unix/42sh
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Sun Apr 29 12:55:15 2012 kevin platel
** Last update Mon Apr 30 12:49:21 2012 kevin platel
*/

#include	<stdlib.h>
#include	"my.h"

char	*my_strmcat(char *dest, char *src)
{
  char	*new;
  int	i;
  int	j;

  if (src == NULL)
    return (NULL);
  new = malloc((my_strlen(dest) + my_strlen(src) + 1) * sizeof(*new));
  if (new == NULL)
    return (NULL);
  i = 0;
  j = 0;
  while (dest && dest[i])
    new[j++] = dest[i++];
  i = 0;
  while (src && src[i])
    new[j++] = src[i++];
  if (dest)
    free(dest);
  new[j] = 0;
  return (new);
}
