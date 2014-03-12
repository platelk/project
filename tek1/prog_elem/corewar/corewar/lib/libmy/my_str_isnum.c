/*
** my_str_isnum.c for my_str_isnum in /home/platel_k//projet/piscine/Jour_6
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Mon Oct 10 16:31:15 2011 kevin platel
** Last update Tue Jan 31 11:14:31 2012 alexandre deceneux
*/

#include "my.h"

int     my_str_isnum(char *str)
{
  int   i;

  i = 0;
  if (str && str[0] == '-')
    i++;
  while (str && str[i])
    {
      if (str[i] < '0' || str[i] > '9')
	return (0);
      i = i + 1;
    }
  return (1);
}
