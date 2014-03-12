/*
** my_strcmp.c for my_strcmp.c in /home/leprov_a//rendu/Jour_06/ex_05
**
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
**
** Started on  Mon Oct 10 17:31:40 2011 alexis leprovost
** Last update Thu Apr 26 15:06:07 2012 kevin platel
*/

#include	<stdlib.h>

int	my_strcmp(char *s1, char *s2)
{
  int i;

  i = 0;
  if (s1 == NULL || s2 == NULL)
    return (-1);
  while (s1[i] == s2[i] && (s1[i] != '\0' && s2[i] != '\0'))
    ++i;
  return (s1[i] - s2[i]);
}
