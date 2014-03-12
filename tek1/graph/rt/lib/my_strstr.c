/*
** my_strstr.c for my in /home/leprov_a//bdd/my
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Mon Apr 30 16:55:03 2012 alexis leprovost
** Last update Mon Apr 30 16:57:52 2012 alexis leprovost
*/

#include	<stdlib.h>

int	my_strstr(char *s1, char *s2)
{
  int	i;
  int	k;

  if (s1 == NULL || s2 == NULL)
    return (EXIT_FAILURE);
  i = -1;
  k = 0;
  while (s2[++i])
    {
      if (s1[k] == s2[i])
	++k;
      else
	if (s1[k] != '\0')
	  k = 0;
    }
  return (EXIT_SUCCESS);
}
