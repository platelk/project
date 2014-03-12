/*
** my_str_isnum.c for my_str_isnum in /home/platel_k//projet/piscine/Jour_6
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Mon Oct 10 16:31:15 2011 kevin platel
** Last update Wed Nov 23 11:21:15 2011 kevin platel
*/

#include "my.h"

int     my_str_isnum(char *str)
{
  int   i;

  i = 0;
  while (str[i])
    {
      if (str[i] < '1' || str[i] > '9')
        return (0);
      i = i + 1;
    }
  if (i == 1)
    return (0);
  return (1);
}
