/*
** my_strtok.c for my_strtok in /home/platel_k/lib
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Tue Jan 24 18:01:30 2012 kevin platel
** Last update Fri Jan 11 12:58:30 2013 kevin platel
*/

#include <stdlib.h>
#include "my.h"

#define CONDI (my_is_instr(str[i], delim) == IS_NOT_STR \
	       && my_is_instr(str[i + 1], delim) == IS_IN_STR)

int	my_is_instr(char c, char *str)
{
  int	i;

  i = 0;
  if (c == 0)
    return (IS_IN_STR);
  while (str[i])
    {
      if (str[i] == c)
	return (IS_IN_STR);
      i++;
    }
  return (IS_NOT_STR);
}

int	my_count_word(char *str, char *delim)
{
  int	i;
  int	count;

  i = 0;
  count = 0;
  while (str[i])
    {
      if (my_is_instr(str[i], delim) == IS_NOT_STR
	  && my_is_instr(str[i + 1], delim) == IS_IN_STR)
	count++;
      i++;
    }
  return (count);
}

char	**my_strtok(char *str, char *delim)
{
  int	i;
  int	j;
  int	k;
  char	**tab;

  if ((tab = malloc((my_count_word(str, delim) + 2) * sizeof(*tab))) == NULL)
    return (0);
  i = -1;
  j = 0;
  k = 0;
  while (str[++i])
    {
      if (my_is_instr(str[i], delim) == IS_NOT_STR)
	k++;
      if (CONDI)
	{
	  tab[j] = malloc((k + 1) * sizeof(**tab));
	  tab[j][0] = 0;
	  tab[j] = my_strncat(tab[j], &str[i - (k - 1)], k);
	  k = 0;
	  j++;
	}
    }
  tab[j] = NULL;
  return (tab);
}
