/*
** is_singlestr.c for my in /home/leprov_a//depot/42sh/src/my/src
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Sat Apr 28 12:20:14 2012 alexis leprovost
** Last update Sat Apr 28 12:21:30 2012 alexis leprovost
*/

#include	<stdlib.h>

int	is_singlestr(char c, char *str)
{
  int	i;

  i = -1;
  while (str && str[++i])
    if (str[i] != c)
      return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
