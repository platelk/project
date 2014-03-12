/*
** my_strdup.c for my_strdup in /home/platel_k//projet/piscine/Jour_08
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Wed Oct 12 09:14:04 2011 kevin platel
** Last update Sat Dec 31 00:37:50 2011 kevin platel
*/

#include <stdlib.h>
#include "my.h"

char	*my_strdup(char *src)
{
  char	*new;
  int	length;
  int	i;

  if (src == NULL)
    return (NULL);
  i = 0;
  length = 0;
  while (src[length] != '\0')
    length++;
  new = malloc((length + 1) * sizeof(char));
  if (new == NULL)
    return (NULL);
  while (src[i] != '\0')
    {
      new[i] = src[i];
      i++;
    }
  new[i] = '\0';
  return (new);
}
