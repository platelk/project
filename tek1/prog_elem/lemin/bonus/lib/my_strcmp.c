/*
** my_strcmp.c for my_strcmp.c in /home/leprov_a//rendu/Jour_06/ex_05
**
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
**
** Started on  Mon Oct 10 17:31:40 2011 alexis leprovost
** Last update Mon Feb 27 23:27:10 2012 alexis leprovost
*/

#include	<stdlib.h>

int	my_strcmp(char *s1, char *s2)
{
  int i;
  int value;

  i = 0;
  value = 0;
  if (s1 == NULL || s2 == NULL)
    return (42);
  while (s1[i] == s2[i] && (s1[i] != '\0' && s2[i] != '\0'))
    i++;
  value = s1[i] - s2[i];
  return (value);
}
