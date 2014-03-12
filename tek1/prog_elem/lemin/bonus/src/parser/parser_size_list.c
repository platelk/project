/*
** parser_size_list.c for lemin in /home/guiho_r/tek1/lemin/src/parser
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Fri Apr  6 12:37:16 2012 ronan guiho
** Last update Fri Apr  6 17:19:58 2012 alexis leprovost
*/

#include <stdlib.h>

#include "hex.h"

int		parser_size_list(t_room *room)
{
  int		i;
  t_room	*ptr;

  i = 0;
  ptr = room;
  while (ptr)
    {
      ptr = ptr->next;
      i++;
    }
  return (i);
}
