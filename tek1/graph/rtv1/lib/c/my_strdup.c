/*
** my_strdup.c for my_strdup in /home/platel_k//projet/piscine/Jour_08
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Wed Oct 12 09:14:04 2011 kevin platel
** Last update Wed Feb  8 18:50:00 2012 kevin platel
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
  length = my_strlen(src);
  new = malloc((length + 2) * sizeof(char));
  if (new == 0)
    return (0);
  while (src[i])
  {
    new[i] = src[i];
    i++;
  }
  new[i] = '\0';
  return (new);
}
