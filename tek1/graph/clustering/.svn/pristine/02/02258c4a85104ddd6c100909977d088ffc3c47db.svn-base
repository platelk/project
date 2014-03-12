/*
** my_malloc.c for my_malloc in /u/all/guiho_r/rendu/lib/my
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Mon Nov 14 16:47:02 2011 ronan guiho
** Last update Sun Dec 11 16:25:15 2011 ronan guiho
*/
#include <stdlib.h>
#include "my.h"

void	RAZ_str(char *str)
{
  int	i;

  i = -1;
  while (str[++i])
    str[i] = '\0';
}

char	*xmalloc(int size)
{
  char	*str;
  if ((str = malloc(size)) == NULL)
    exit (1);
  RAZ_str(str);
  return (str);
}
