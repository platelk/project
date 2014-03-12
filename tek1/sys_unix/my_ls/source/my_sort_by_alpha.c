/*
** my_sort_by_alpha.c for my_sort_by_alpha in /home/platel_k/projet/my_ls/source
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Tue Nov 22 19:44:56 2011 kevin platel
** Last update Sun Dec  4 08:08:17 2011 kevin platel
*/

#include <stdlib.h>
#include "my.h"

char	*str_upper(char	*str)
{
  int   i;

  i = -1;
  while (str[++i])
    if (str[i] >= 'a' && str[i] <= 'z')
      str[i] = str[i] - 32;
  return (str);
}

int	my_sort_by_alpha(char *str1, char *str2)
{
  int   i;
  char	*s1;
  char	*s2;

  s1 = str_upper(my_strdup(str1));
  s2 = str_upper(my_strdup(str2));
  i = 0;
  while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' )
      i++;
  if (s1[i] == s2[i] && s1[i] == '\0')
    {
      free(s1);
      free(s2);
      return (0);
    }
  i = s1[i] - s2[i];
  free(s1);
  free(s2);
  return (i);
}
