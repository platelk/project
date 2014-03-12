/*
** my_str_to_wortab.c for my_str_to_wordtab in /home/desoul_b/
** 
** Made by benoit desoulle
** Login   <desoul_b@epitech.net>
** 
** Started on  Fri Oct 28 17:27:01 2011 benoit desoulle
** Last update Sat Nov 26 22:48:49 2011 kevin platel
*/
#include <stdlib.h>

int	word_count_mod(char *str)
{
  int	i;
  int	space;

  i = 0;
  space = 1;
  while (str[i])
    if (str[i++] == ' ')
      space++;
  return (space);
}

int	size(char *str)
{
  int	i;
  int	count;

  i = 0;
  count = 0;
  while (str[i++] != ' ' && str[i])
    count++;
  return (count);
}

void	boucle(int j, int k, char **tab, char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] == ' ')
	{
	  tab[j][k] = '\0';
	  j = j + 1;
	  k = 0;
	  i = i + 1;
	}
      else
	{
	  tab[j][k] = str[i];
	  k = k + 1;
	  i = i + 1;
	}
    }
}

char	**my_str_to_wordtabmod(char *str)
{
  int	j;
  int	k;
  int	wordnb;
  int	size_word;
  char	**tab;

  size_word = 0;
  wordnb = (word_count_mod(str));
  tab = malloc((wordnb + 1) * sizeof(*tab));
  tab[wordnb] = '\0';
  if (tab == NULL)
    return (0);
  j = 0;
  while (j != wordnb && str[size_word])
    {
      size_word = size_word + size(&str[size_word]) + 1;
      tab[j] = malloc((size(&str[size_word]) + 1) * sizeof(**tab));
      if (tab[j++] == NULL)
	return (0);
    }
  j = 0;
  k = 0;
  boucle(j, k, tab, str);
  return (tab);
}
