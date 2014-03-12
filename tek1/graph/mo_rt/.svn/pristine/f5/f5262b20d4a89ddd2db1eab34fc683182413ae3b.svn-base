/*
** my_strcat.c for my in /home/leprov_a//bdd/my
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Mon Apr 30 16:18:57 2012 alexis leprovost
** Last update Mon Apr 30 16:18:59 2012 alexis leprovost
*/

#include	<stdlib.h>

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	j;

  j = 0;
  i = 0;
  if (dest == NULL && src != NULL)
    return (src);
  if (dest != NULL && src == NULL)
    return (dest);
  if (dest == NULL && src == NULL)
    return (NULL);
  while (dest[i])
    ++i;
  while (src[j])
    {
      dest[i + j] = src[j];
      ++j;
    }
  dest[i + j] = '\0';
  return (dest);
}
