/*
** utils.c for utils in /home/vink/projet/sys_unix/42sh/src/globing
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Wed Apr 11 21:28:31 2012 kevin platel
** Last update Tue May  8 22:43:38 2012 kevin platel
*/

#include <stdlib.h>
#include <string.h>

#include	"my.h"
#include	"xsys.h"

int	my_wordtab_len(char **tab)
{
  int	len;
  int	i;

  i = 0;
  len = 0;
  while (tab && tab[i])
    {
      len += strlen(tab[i]);
      i++;
    }
  return (len);
}

int	my_count_str_in_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab && tab[i])
    i++;
  return (i);
}

char	*replace_str(char *new, char *old, char *str)
{
  char	*s;
  char	*tmp;
  int	i;
  int	j;
  int	h;

  s = xmalloc(((my_strlen(new) + (my_strlen(str) - my_strlen(old))) + 1)
	      * sizeof(*s));
  tmp = strstr(str, old);
  if (tmp == NULL || new == NULL || str == NULL)
    return (str);
  i = 0;
  j = 0;
  h = 0;
  while (&str[j] != tmp)
    s[i++] = str[j++];
  j += (my_strlen(old));
  while (new[h])
    s[i++] = new[h++];
  while (str[j])
    s[i++] = str[j++];
  return (s);
}
