/*
** count.c for colle in /home/fontai_t/colle2
** 
** Made by thomas fontaine
** Login   <fontai_t@epitech.net>
** 
** Started on  Thu Apr 26 21:39:51 2012 thomas fontaine
** Last update Thu Apr 26 21:41:05 2012 thomas fontaine
*/

#include <stdlib.h>

int	my_strlen(char *str)
{
  int	i;

  if (str == NULL)
    return (0);
  i = -1;
  while (str[++i]);
  return (i);
}
