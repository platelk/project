/*
** my_str_to_tab.c for my_str_to_tab in /home/leprov_a//project/igraph/fdf/v_04/new
**
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
**
** Started on  Sat Dec 10 12:36:48 2011 alexis leprovost
** Last update Fri Jan 11 15:21:23 2013 kevin platel
*/

#include	<stdlib.h>

#include	"xsys.h"
#include	"my_strtok.h"

int	my_getword(char *str, char *base, t_type flag)
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

int	my_getchar(char *str, char *base, int *k, t_type flag)
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

char	*my_putword(char *str, char *base, int *k, t_type flag)
{
  char *word;
  int len;
  int i;

  i = 0;
  len = my_getchar(str, base, k, flag) + 1;
  if ((word = xmalloc(len * sizeof(*word))) == NULL)
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

char	**my_strtok(char *str, char *base, t_type flag)
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
  if ((tab = xmalloc(len * sizeof(*tab))) == NULL)
    return (NULL);
  while (i < (len - 1))
    {
      tab[i] = my_putword(str, base, &k, flag);
      ++i;
    }
  tab[i] = NULL;
  return (tab);
}
