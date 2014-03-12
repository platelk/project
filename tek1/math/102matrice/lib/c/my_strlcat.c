/*
** my_strlcat.c for my_strlcat in /home/platel_k//projet/piscine/Jour_07/ex_01
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Tue Oct 11 11:54:36 2011 kevin platel
** Last update Wed Nov 23 11:23:21 2011 kevin platel
*/

#include "my.h"

int    my_strlcat(char *dest, char *src, int n)
{
  int   i;
  int   j;

  j = 0;
  i = 0;
  while (dest[i])
    i = i + 1;
  while (src[j] && n > j)
    {
      dest[i + j] = src[j];
      j = j + 1;
    }
  dest[i + j] = '\0';
  i = 0;
  while (dest[i])
    i = i + 1;
  return (i);
}
