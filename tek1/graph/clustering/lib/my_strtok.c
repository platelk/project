/*
** my_str_to_tab.c for my_str_to_tab in /home/leprov_a//project/igraph/fdf/v_04/new
**
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
**
** Started on  Sat Dec 10 12:36:48 2011 alexis leprovost
** Last update Sat May  5 21:55:14 2012 ronan guiho
*/

#include	<stdlib.h>

#include	"my.h"

int	my_getword(char *str, char *bdd, int flag)
{
  int i;
  int word;

  i = -1;
  word = 0;
  while (str[++i])
    {
      if (i == 0 && check_base(str[i], bdd) == flag)
	word++;
      if (i > 0 && (check_base(str[i], bdd) == flag &&
		    check_base(str[i - 1], bdd) != flag))
	word++;
    }
  return (word);
}

int	my_getchar(char *str, char *bdd, int *k, int flag)
{
  int letter;
  int i;

  letter = 0;
  while (check_base(str[*k], bdd) != flag)
    *k = *k + 1;
  i = *k;
  while (check_base(str[i], bdd) == flag && str[i] != '\0')
    {
      i++;
      letter++;
    }
  return (letter);
}

char	*my_putword(char *str, char *bdd, int *k, int flag)
{
  char *word;
  int len;
  int i;

  i = 0;
  len = my_getchar(str, bdd, k, flag) + 1;
  word = malloc(len * sizeof(*word));
  while (check_base(str[*k], bdd) == flag && str[*k] != '\0')
    {
      word[i] = str[*k];
      i++;
      *k = *k + 1;
    }
  word[i] = '\0';
  return (word);
}

char	**my_strtok(char *str, char *bdd, int flag)
{
  char **tab;
  int len;
  int i;
  int k;

  k = 0;
  i = 0;
  len = my_getword(str, bdd, flag) + 1;
  tab = malloc(len * sizeof(*tab));
  while (i < (len - 1))
    {
      tab[i] = my_putword(str, bdd, &k, flag);
      i++;
    }
  tab[i] = NULL;
  return (tab);
}
