/*
** server_int_to_str.c for server in /home/guiho_r/tek1/clustering/src/server
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Wed May  2 15:10:39 2012 ronan guiho
** Last update Fri Jun  1 11:04:45 2012 ronan guiho
*/

#include <stdlib.h>

#include "server.h"

int	my_swap_char(char *a, char *b)
{
  char	c;
  char	d;

  c = *a;
  d = *b;
  *b = c;
  *a = d;
  return (0);
}

char	*my_revstr(char *str)
{
  int	leng;
  int	i;

  leng = my_strlen(str);
  i = 0;
  while ((leng / 2) > i)
    {
      my_swap_char(str + i, str + ((leng - 1) - i));
      i = i + 1;
    }
  return (str);
}

char	*server_int_to_str(int value)
{
  int	i;
  char	*str;
  int	result;

  i = -1;
  if ((str = malloc(sizeof(char) * (20 + 1))) == NULL)
    return (NULL);
  if (value <= 0)
    {
      str[0] = '0';
      str[1] = '\0';
      return (str);
    }
  else
    {
      while (value != 0)
	{
	  result = value % 10;
	  value = value / 10;
	  str[++i] = result + '0';
	}
      str[++i] = '\0';
    }
  return (my_revstr(str));
}
