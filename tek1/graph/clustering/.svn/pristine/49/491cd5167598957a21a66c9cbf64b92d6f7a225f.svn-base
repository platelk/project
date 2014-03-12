/*
** server_ping_check_recv.c for server in /home/guiho_r/tek1/clustering/src/server
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Thu May  3 13:41:56 2012 ronan guiho
** Last update Sun May  6 14:15:18 2012 ronan guiho
*/

#include <stdlib.h>

#include "server.h"

t_client	*list;

int		server_ping_check_recv()
{
  t_client	*tmp;

  tmp = list;
  while (tmp)
    {
      if (tmp->ping == 0)
	server_client_remove(tmp);
      tmp = tmp->next;
    }
  return (EXIT_SUCCESS);
}
