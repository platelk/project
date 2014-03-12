/*
** is_a_singlestr.c for my in /home/leprov_a//bdd/my
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Mon Apr 30 13:23:11 2012 alexis leprovost
** Last update Mon Apr 30 13:24:20 2012 alexis leprovost
*/

#include	<stdlib.h>

int	is_a_singlestr(char c, char *str)
{
  int	i;

  i = -1;
  if (str == NULL)
    return (EXIT_FAILURE);
  while (str[++i])
    if (str[i] != c)
      return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
