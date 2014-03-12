/*
** my_strstr.c for my_strstr in /home/platel_k//projet/piscine/Jour_6
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Mon Oct 10 12:58:08 2011 kevin platel
** Last update Mon Dec 12 20:53:06 2011 kevin platel
*/

#include <string.h>

char	*my_strstr(char *str, char *to_find)
{
  int	i;
  int	e;

  i = 0;
  while (str[i])
    {
      e = 0;
      while (str[e + i] == to_find[e])
	{
	  if (to_find[e + 1] == '\0')
	    return (&str[i]);
	  e = e + 1;
	}
      i = i + 1;
    }
  return (NULL);
}
