/*
** my_strdup.c for my_strdup in /home/platel_k//projet/piscine/Jour_08
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Wed Oct 12 09:14:04 2011 kevin platel
** Last update Wed Nov 23 11:20:09 2011 kevin platel
*/

#include <stdlib.h>
#include "my.h"

char	*my_strdup(char *src)
{
  char	*new;
  int	length;
  int	i;

  i = 0;
  length = my_strlen(src);
  new = malloc(length);
  if (malloc(length) == 0)
    return (0);
  while (src[i])
  {
    new[i] = src[i];
    i = i + 1;
  }
  return (new);
}
