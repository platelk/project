/*
** my_strdup for my_strdup.c in /home/guiho_r//workhome/piscine/Jour_08
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Wed Oct 12 09:14:45 2011 ronan guiho
** Last update Sun May  6 22:09:09 2012 ronan guiho
*/
#include <stdlib.h>
#include "my.h"

char	*my_strdup(char *src)
{
  char  *dest;
  int	i;

  i = 0;
  if (src == NULL)
    {
      dest = malloc(sizeof(char) * 1);
      dest[0] = '\0';
      return (dest);
    }
  dest = malloc(sizeof(char) * (my_strlen(src) + 1));
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}
