/*
** my_clstr.c for my in /home/leprov_a//depot/42sh/src/my/src
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Mon Apr 23 14:20:53 2012 alexis leprovost
** Last update Mon Apr 23 14:22:21 2012 alexis leprovost
*/

#include	<stdlib.h>

int	my_clstr(char *str, int size)
{
  int	i;

  i = -1;
  if (!str || size <= 0)
    return (EXIT_FAILURE);
  while (++i < size)
    str[i] = 0;
  return (EXIT_FAILURE);
}
