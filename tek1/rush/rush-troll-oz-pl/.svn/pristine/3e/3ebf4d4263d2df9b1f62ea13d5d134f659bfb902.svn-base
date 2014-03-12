/*
** my_evil_str.c for my_evil_str in /home/platel_k//projet/piscine/Jour_04
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Thu Oct  6 10:53:48 2011 kevin platel
** Last update Wed Nov 23 11:33:32 2011 kevin platel
*/

#include "my.h"

/*
**calculate a length of a string
*/
int	my_strleng(char *str)
{
  int   length;

  length = 0;
  while (str[length])
    {
      length = length + 1;
    }
  return (length);
}

/*
** reverse a string
*/
char	*my_revstr(char *str)
{
  int   length;
  int	c;

  c = 0;
  length = my_strleng(str);
  while (length > c)
    {
	length = length - 1;
	my_swap_char(&str[c], &str[length]);
	c = c + 1;
    }
  return (str);
}
