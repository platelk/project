/*
** my_revstr.c for my in /home/leprov_a//depot/42sh/src/my/src
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Fri May 18 13:35:04 2012 alexis leprovost
** Last update Fri May 18 13:41:33 2012 alexis leprovost
*/

#include	<stdlib.h>

#include	"my.h"

char	*my_revstr(char *str)
{
  int	i;
  int	k;
  int	data;

  i = 0;
  k = my_strlen(str) - 1;
  if (str == NULL)
    return (NULL);
  while (i < k)
    {
      data = str[i];
      str[i] = str[k];
      str[k] = data;
      ++i;
      --k;
    }
  return (str);
}
