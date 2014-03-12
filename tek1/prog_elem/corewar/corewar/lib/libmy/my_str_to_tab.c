/*
** my_str_to_tab.c for my_str_to_tab in /home/leprov_a//project/igraph/fdf/v_04/new
**
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
**
** Started on  Sat Dec 10 12:36:48 2011 alexis leprovost
** Last update Thu Feb  2 14:54:47 2012 alexis leprovost
*/

#include	<stdlib.h>
#include	"my.h"

int	check_bdd(char c, char *bdd)
{
  int i;

  i = -1;
  while (bdd[++i])
    {
      if (bdd[i] == c)
	return (1);
    }
  return (0);
}

int	my_getword(char *str, char *bdd)
{
  int i;
  int word;

  i = -1;
  word = 0;
  while (str[++i])
    {
      if (i == 0 && check_bdd(str[i], bdd))
	word++;
      if (i > 0 && (check_bdd(str[i], bdd) && !check_bdd(str[i - 1], bdd)))
	word++;
    }
  return (word);
}

int	my_getchar(char *str, char *bdd, int *k)
{
  int letter;
  int i;

  letter = 0;
  while (!check_bdd(str[*k], bdd))
    *k = *k + 1;
  i = *k;
  while (check_bdd(str[i], bdd) && str[i] != '\0')
    {
      i++;
      letter++;
    }
  return (letter);
}

char	*my_putword(char *str, char *bdd, int *k)
{
  char *word;
  int len;
  int i;

  i = 0;
  len = my_getchar(str, bdd, k) + 1;
  word = malloc(len * sizeof(*word));
  while (check_bdd(str[*k], bdd) && str[*k] != '\0')
    {
      word[i] = str[*k];
      i++;
      *k = *k + 1;
    }
  word[i] = '\0';
  return (word);
}

char	**my_str_to_tab(char *str, char *bdd)
{
  char **tab;
  int len;
  int i;
  int k;

  k = 0;
  i = 0;
  len = my_getword(str, bdd) + 1;
  tab = malloc(len * sizeof(*tab));
  while (i < (len - 1))
    {
      tab[i] = my_putword(str, bdd, &k);
      i++;
    }
  tab[i] = NULL;
  return (tab);
}
