/*
** epur_str.c for my in /home/leprov_a//bdd/my
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Mon Apr 30 13:25:37 2012 alexis leprovost
** Last update Mon Apr 30 16:14:44 2012 alexis leprovost
*/

#include	<stdlib.h>

#include	"my.h"

char	*epur_str(char *str)
{
  char	*epur_str;
  int	i;
  int	k;

  i = 0;
  k = 0;
  if ((epur_str = malloc(sizeof(*epur_str) * (my_strlen(str) + 1))) == NULL ||
      str == NULL)
    return (NULL);
  while (str[i])
    {
      while (str[i] == ' ' || str[i] == '\t')
	++i;
      while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t')
	epur_str[k++] = str[i++];
      if (str[i] != '\0')
	{
	  epur_str[k++] = ' ';
	  ++i;
	}
    }
  epur_str[k] = '\0';
  return (epur_str);
}
