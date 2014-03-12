/*
** my_malloc.c for malloc in /home/leprov_a//bdd/source/my
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Mon Nov 28 13:06:16 2011 alexis leprovost
** Last update Mon Jan 16 13:48:51 2012 alexis leprovost
*/

#include	<stdlib.h>

#include	"my.h"

char	*my_malloc(int size)
{
  char *str;
  int i;

  str = malloc(size * sizeof(*str));
  i = 0;
  if (str == NULL)
    my_merror();
  while (i < size)
    {
      str[i] = '\0';
      i++;
    }
  return (str);
}
