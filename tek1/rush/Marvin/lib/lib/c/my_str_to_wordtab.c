/*
** my_str_to_wordtab.c for my_str_to_wordtab.c in /home/platel_k//projet/piscine/my_str_to
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Fri Oct 14 09:03:20 2011 kevin platel
** Last update Fri Nov 25 21:42:20 2011 kevin platel
*/

#include <stdlib.h>
#include "my.h"

int     is_alnum(char c)
{
  if ((c < 'a' || c > 'z') && (c < 'A' || c > 'Z'))
    if (c < '0' || c > '9')
      return (0);
  return (1);
}

int	word_count(char *str)
{
  int   i;
  int   word;

  word = 0;
  i = 0;
  while (str[i])
    {
      if (is_alnum(str[i]) == 1 && is_alnum(str[i + 1]) == 0)
        word = word + 1;
      i = i + 1;
    }
  return (word);
}

char	**my_str_to_wordtab(char *str)
{
  int	j;
  int	i;
  char	**wordtab;
  int	len;

  j = 0;
  len = 0;
  i = 0;
  wordtab = malloc((word_count(str) + 1) * sizeof(char *));
  while (str[i])
    {
      if (is_alnum(str[i]))
	  len = len + 1;
      if (is_alnum(str[i]) == 1 && is_alnum(str[i + 1]) == 0)
	{
	  wordtab[j] = malloc(len + 1);
	  my_strncpy(wordtab[j], &str[i - len + 1], len);
	  len = 0;
	  j = j + 1;
	}
      i = i + 1;
    }
  wordtab[j] = malloc(1);
  wordtab[j] = '\0';
  return (wordtab);
}
