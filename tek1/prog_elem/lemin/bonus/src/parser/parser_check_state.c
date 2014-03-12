/*
** parser_check_state.c for lemin in /home/guiho_r/tek1/lemin/src/parser
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Thu Apr  5 09:39:19 2012 ronan guiho
** Last update Fri Apr  6 15:21:07 2012 alexis leprovost
*/

#include <stdlib.h>

#include "hex.h"

int	parser_check_if_state(char *buffer, int i)
{
  if (my_strcmp("##start", buffer) == 0)
    return (START);
  else if (my_strcmp("##end", buffer) == 0)
    return (END);
  else if (buffer[0] == '#' && buffer[1] == '#')
    {
      my_printf("lemin: error(%i): bad instruction '%s'\n", i + 1, buffer);
      return (-1);
    }
  return (TMP);
}