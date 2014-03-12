/*
** my_strmcat.c for my_strmcat in /home/vink/projet/sys_unix/minishell2/source
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Sun Feb  5 14:17:03 2012 kevin platel
** Last update Fri Jun  8 19:11:50 2012 kevin platel
*/

#include <stdlib.h>
#include "my.h"

char	*my_strmcat(char *dest, char *src)
{
  int	i;
  int	j;
  char	*tmp;

  i = 0;
  j = -1;
  if (src == NULL)
    return (dest);
  tmp = my_strdup(dest);
  dest = malloc((my_strlen(tmp) + my_strlen(src) + 1) * sizeof(*dest));
  while (tmp != NULL && tmp[i])
    {
      dest[i] = tmp[i];
      i++;
    }
  if (tmp != NULL)
    free(tmp);
  i < 0 ? (i = 0) : (i = i);
  while (src[++j])
    dest[i++] = src[j];
  dest[i] = 0;
  return (dest);
}

