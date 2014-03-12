/*
** my_strcat.c for my_strcat in /home/platel_k//projet/piscine/Jour_07
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Tue Oct 11 10:45:37 2011 kevin platel
** Last update Thu Apr 26 14:37:31 2012 zoe phalippou
*/

#include	<stdlib.h>

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	j;

  j = 0;
  i = 0;
  if (!dest || !src)
    return (NULL);
  while (dest[i])
    i = i + 1;
  while (src[j])
    {
      dest[i + j] = src[j];
      j = j + 1;
    }
  dest[i + j] = '\0';
  return (dest);
}
