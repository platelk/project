/*
** my_strncmp.c for my_strncmp in /home/leprov_a//afs/current/warning/xmalloc
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Tue Feb 28 00:29:51 2012 alexis leprovost
** Last update Mon Apr 30 13:10:55 2012 alexis leprovost
*/

#include	<stdlib.h>

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;

  i = 0;
  if (s1 == NULL || s2 == NULL)
    return (-1);
  while (s1[i] == s2[i] && (s1[i] != '\0' && s2[i] != '\0') && i < n)
    ++i;
  return (s1[i] - s2[i]);
}
