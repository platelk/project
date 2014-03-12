/*
** my_strdup.c for my_strdup in /home/platel_k//projet/piscine/Jour_08
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Wed Oct 12 09:14:04 2011 kevin platel
** Last update Thu Dec  1 17:33:13 2011 kevin platel
*/

#include <stdlib.h>
#include "my.h"

char	*my_strdup(char *src)
{
  char	*new;
  int	length;
  int	i;

  i = 0;
  length = my_strlen(src) + 1;
  new = malloc(length);
  if (new == NULL)
    return (NULL);
  while (src[i])
  {
    new[i] = src[i];
    i = i + 1;
  }
  new[i] = '\0';
  return (new);
}
