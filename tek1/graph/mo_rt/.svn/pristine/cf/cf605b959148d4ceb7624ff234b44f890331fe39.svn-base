/*
** xml_fct_utils.c for xml in /home/vink/projet/graph/xml/xml_src/src
**
** Made by kevin platel
** Login   <vink@epitech.net>
**
** Started on  Sat May  5 13:25:00 2012 kevin platel
** Last update Sat May  5 21:32:39 2012 kevin platel
*/

#include	<stdlib.h>

#include	"my.h"
#include	"my_strtok.h"

int	xml_len_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab && tab[i])
    i++;
  return (i);
}

char	*xml_epur_str(char *s)
{
  char	**tab;
  char	*new;
  int	i;

  i = 0;
  tab = my_strtok(s, " \t\n", TOK_DELIM);
  new = NULL;
  while (tab && tab[i])
    {
      new = my_strmcat(new, tab[i]);
      if (tab[i + 1])
	new = my_strmcat(new, " ");
      i++;
    }
  my_free_tab(tab);
  return (new);
}
