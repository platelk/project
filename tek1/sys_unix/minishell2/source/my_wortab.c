/*
** my_str_to_wordtab.c for my_str_to_wordtab.c in /home/platel_k//projet/piscine/my_str_to
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Fri Oct 14 09:03:20 2011 kevin platel
** Last update Sat Dec 31 01:03:57 2011 kevin platel
*/

#include <stdlib.h>
#include "my.h"

int     is_alnume(char c)
{
  if ((c < 'a' || c > 'z') && (c < 'A' || c > 'Z') && c != '/' && c != '.')
    if ((c < '0' || c > '9') && c != '-' && c != '_')
      return (0);
  return (1);
}

int	word_cnt(char *str)
{
  int   i;
  int   word;

  word = 0;
  i = 0;
  while (str != NULL && str[i] != '\0')
    {
      if (is_alnume(str[i]) == 1 && is_alnume(str[i + 1]) == 0)
        word = word + 1;
      i = i + 1;
    }
  return (word);
}

char	**my_wordtab(char *str)
{
  int	j;
  int	i;
  char	**wordtab;
  int	len;

  j = 0;
  len = 0;
  i = -1;
  if ((wordtab = malloc((word_cnt(str) + 1) * sizeof(char *))) == 0)
    return (NULL);
  while (str != NULL && str[++i] != '\0')
    {
      if (is_alnume(str[i]))
	  len++;
      if (is_alnume(str[i]) == 1 && is_alnume(str[i + 1]) == 0)
	{
	  if ((wordtab[j] = malloc((len + 1) * sizeof(char))) == 0)
	    return (wordtab);
	  my_strncpy(wordtab[j], &str[i - len + 1], len);
	  len = 0;
	  j++;
	}
    }
  wordtab[j] = NULL;
  return (wordtab);
}
