/*
** parser_size_list.c for lemin in /home/guiho_r/tek1/lemin/src/parser
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Fri Apr  6 12:37:16 2012 ronan guiho
** Last update Mon Apr  9 10:53:50 2012 ronan guiho
*/

#include <stdlib.h>

#include "lemin.h"

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
