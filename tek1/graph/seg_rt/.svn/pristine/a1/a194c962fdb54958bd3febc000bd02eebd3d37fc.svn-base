/*
** my_strtok.c for my in /home/leprov_a//bdd/my
**
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
**
** Started on  Mon Apr 30 16:20:12 2012 alexis leprovost
** Last update Wed May 23 22:34:34 2012 kevin platel
*/

#include	<stdlib.h>
#include	<stdio.h>

#include	"my_strtok.h"

int	my_getword(char *str, char *base, t_mytok flag)
{
  int i;
  int word;

  i = -1;
  word = 0;
  while (str && str[++i])
    {
      if (i == 0 && check_base(str[i], base) == (int)flag)
	++word;
      if (i > 0 && (check_base(str[i], base) == (int)flag &&
		    check_base(str[i - 1], base) != (int)flag))
	++word;
    }
  return (word);
}

int	my_getchar(char *str, char *base, int *k, t_mytok flag)
{
  int letter;
  int i;

  letter = 0;
  while (check_base(str[*k], base) != (int)flag)
    ++(*k);
  i = *k;
  while (check_base(str[i], base) == (int)flag && str[i] != '\0')
    {
      ++i;
      ++letter;
    }
  return (letter);
}

char	*my_putword(char *str, char *base, int *k, t_mytok flag)
{
  char *word;
  int len;
  int i;

  i = 0;
  len = my_getchar(str, base, k, flag) + 1;
  if ((word = malloc(len * sizeof(*word))) == NULL)
    return (NULL);
  while (check_base(str[*k], base) == (int)flag && str[*k] != '\0')
    {
      word[i] = str[*k];
      ++i;
      ++(*k);
    }
  word[i] = '\0';
  return (word);
}

char	**my_strtok(char *str, char *base, t_mytok flag)
{
  char **tab;
  int len;
  int i;
  int k;

  if (str == NULL)
    return (NULL);
  k = 0;
  i = 0;
  len = my_getword(str, base, flag) + 1;
  if ((len) == 1 || (tab = malloc(len * sizeof(*tab))) == NULL)
    return (NULL);
  while (i < (len - 1))
    {
      tab[i] = my_putword(str, base, &k, flag);
      ++i;
    }
  tab[i] = NULL;
  return (tab);
}
