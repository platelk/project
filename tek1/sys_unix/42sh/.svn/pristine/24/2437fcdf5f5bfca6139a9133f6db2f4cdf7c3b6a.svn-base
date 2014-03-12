/*
** isanumber.c for my in /home/leprov_a//afs/current/cmp_str
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Mon Apr 16 12:12:03 2012 alexis leprovost
** Last update Tue Apr 17 12:38:20 2012 alexis leprovost
*/

#include	<stdlib.h>

#include	"my.h"

int	isanumber(char *str)
{
  char	*base;
  int	i;

  base = NUMBER_STRING;
  i = -1;
  if (!str)
    return (EXIT_FAILURE);
  while (str[++i])
    if (!check_base(str[i], base))
      return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
