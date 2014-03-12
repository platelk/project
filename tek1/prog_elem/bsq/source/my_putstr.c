/*
** my_putstr.c for my_putstr in /home/platel_k//projet/piscine/Jour_04
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Thu Oct  6 10:12:04 2011 kevin platel
** Last update Fri Dec  9 14:43:28 2011 kevin platel
*/

#include "my.h"

int	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
  return (0);
}
