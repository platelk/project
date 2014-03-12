/*
** concat.c for test in /home/guiho_r/test
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Thu Apr 12 15:20:41 2012 ronan guiho
** Last update Wed May 23 16:00:42 2012 ronan guiho
*/

#include <stdlib.h>

#include "my.h"

char	*my_strconcat(char *s1, char *s2)
{
  int	i1;
  int	i2;
  char	*str;

  i1 = my_strlen(s1);
  i2 = my_strlen(s2);
  if (s1 != NULL)
    if (s1[0] == '\0')
      return (my_strdup(s2));
  if (s1 == NULL)
    return (s2);
  if ((str = malloc(sizeof(char) * (i1 + i2 + 1))) == NULL)
    return (NULL);
  str = my_strcpy(str, s1);
  str = my_strcat(str, s2);
  return (str);
}
