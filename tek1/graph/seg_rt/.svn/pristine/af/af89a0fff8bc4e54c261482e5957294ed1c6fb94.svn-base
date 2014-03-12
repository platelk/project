/*
** server_client_count.c for server in /home/guiho_r/tek1/clustering/src/server
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Fri May  4 14:03:57 2012 ronan guiho
** Last update Fri May  4 16:20:33 2012 ronan guiho
*/

#include <stdlib.h>

#include "server.h"

t_client	*list;

int		server_client_count()
{
  int		i;
  t_client	*tmp;

  i = 0;
  tmp = list;
  while (tmp)
    {
      i++;
      tmp = tmp->next;
    }
  return (i);
}
