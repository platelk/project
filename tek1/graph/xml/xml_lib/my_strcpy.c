/*
** my_strcpy.c for my in /home/leprov_a//bdd/my
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Mon Apr 30 16:19:13 2012 alexis leprovost
** Last update Mon Apr 30 16:19:14 2012 alexis leprovost
*/

#include	<stdlib.h>

#include	"my.h"

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  if (src == NULL)
    return (dest);
  if (dest == NULL)
    if ((dest = malloc(sizeof(*dest) * (my_strlen(src) + 1))) == NULL)
      return (NULL);
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}
