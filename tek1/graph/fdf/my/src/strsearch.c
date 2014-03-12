/*
** strsearch.c for strsearch in /home/guiho_r/tek1/42sh/src/stack_exec/src
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Wed May 16 14:32:07 2012 ronan guiho
** Last update Wed May 16 14:36:36 2012 ronan guiho
*/

#include <stdlib.h>

int	my_strsearch(char *str, char c)
{
  int	i;

  i = -1;
  while (str && str[++i])
    {
      if (str[i] == c)
	return (1);
    }
  return (0);
}
