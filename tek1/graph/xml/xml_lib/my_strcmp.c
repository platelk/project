/*
** my_strcmp.c for my in /home/leprov_a//bdd/my
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Mon Apr 30 16:20:00 2012 alexis leprovost
** Last update Mon Apr 30 16:20:01 2012 alexis leprovost
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
