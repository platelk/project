/*
** client_endtrame.c for client in /home/guiho_r/tek1/clustering/src/server
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Mon May  7 17:27:08 2012 ronan guiho
** Last update Mon May  7 17:32:27 2012 ronan guiho
*/

#include <stdlib.h>

#include "server.h"

char	*client_endtrame(char *s1)
{
  int	i1;
  char	*str;

  i1 = my_strlen(s1);
  if (s1 != NULL)
    if (s1[0] == '\0')
      return (s1);
  if ((str = malloc(sizeof(char) * (i1 + 2))) == NULL)
    return (NULL);
  str = my_strcpy(str, s1);
  str[i1] = 4;
  str[i1 + 1] = '\0';
  return (str);
}
