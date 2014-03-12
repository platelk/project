/*
** my_str_isalpha.c for my_str_isalpha in /home/platel_k//projet/piscine/Jour_6
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Mon Oct 10 15:24:28 2011 kevin platel
** Last update Wed Nov 23 11:20:47 2011 kevin platel
*/

#include "my.h"

int	my_str_isalpha(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if ((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
	return (0);
      i = i + 1;
    }
  if (i == 1)
    return (0);
  return (1);
}
