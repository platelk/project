/*
** parser_check_link.c for lemin in /home/guiho_r/tek1/lemin/src/parser
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Wed Apr  4 14:48:01 2012 ronan guiho
** Last update Thu Apr  5 15:44:01 2012 ronan guiho
*/

#include <stdlib.h>

int	parser_check_if_link(char *buffer)
{
  int	i;

  i = -1;
  if (buffer == NULL)
    return (-1);
  while (buffer[++i])
    if (buffer[i] == '-')
      return (1);
  return (0);
}
